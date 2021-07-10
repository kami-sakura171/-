# mysql-cluster集群搭建

[TOC]

[参考博客1](https://blog.csdn.net/l1028386804/article/details/53079933)
[参考博客2](https://www.cnblogs.com/kingsonfu/p/9803418.html)

## 第一步：环境准备
1.服务器配置,CentOS7系统
```
192.168.15.10  #管理节点
192.168.15.11  #数据节点、SQL节点(其中机器多的话，数据节点和SQL节点最好分开)
192.168.15.12  #数据节点、SQL节点(其中机器多的话，数据节点和SQL节点最好分开)
```
2.mysql-cluster配置
```
官网下载mysql-cluster-community-7.6.12-1.el7.x86_64.rpm-bundle.tar基于RPM方式安装
```

## 第二步：基础环境安装(三台机器执行相同操作)
1.清理CentOS7中以前mysql服务
```
yum -y remove mariadb-libs
yum -y remove mysql
rpm -qa | grep mysql*
rpm -e --nodeps mysql-libs-*
```
2.创建文件夹，并且授权
```
存储节点:mkdir /usr/local/mysql/data
管理节点:mkdir /usr/local/mysql-cluster   SQL节点：可不用  文件夹授权
使用如下命令来变更权限保证可写入
chmod -R 1777 /usr/local/mysql/data
chmod -R 1777 /usr/local/mysql-cluster
```
3.关闭SELinux和防火墙
```
修改/etc/selinux/config 配置SELINUX=disabled
systemctl stop firewalld
systemctl disable firewalld
```
4.安装所需要的依赖
```
yum install vim perl perl-Data-Dumper perl-DBI epel-release net-tools
再安装所需的perl-Class-MethodMaker依赖，如果安装失败的话，直接下载RPM包离线安装
yum install perl-Class-MethodMaker
```

## 第三步：管理节点安装
1.解压文件
```
cd /opt
tar -xvf mysql-cluster-community-7.6.12-1.el7.x86_64.rpm-bundle.tar
```
2.安装依赖包
```
rpm -ivh mysql-cluster-community-common-7.6.12-1.el7.x86_64.rpm 
rpm -ivh mysql-cluster-community-libs-7.6.12-1.el7.x86_64.rpm
rpm -ivh mysql-cluster-community-client-7.6.12-1.el7.x86_64.rpm
rpm -ivh mysql-cluster-community-management-server-7.6.12-1.el7.x86_64.rpm
```
3.创建配置文件
```
cd /usr/local/mysql-cluster
vim config.ini
```
复制以下内容
```
[ndbd default]
NoOfReplicas=2
DataDir=/usr/local/mysql/data
[ndb_mgmd]
Hostname=192.168.15.10
[ndbd]
HostName=192.168.15.11
[ndbd]
HostName=192.168.15.12
[mysqld]
HostName=192.168.15.11
[mysqld]
HostName=192.168.85.12
```
至此，管理端配置完毕，直接启动
```
ndb_mgmd -f /usr/local/mysql-cluster/config.ini --initial (**备注：最后全部安装完毕统一执行**)
```
## 第四步：数据节点安装
1.解压文件
```
cd /opt
tar -xvf mysql-cluster-community-7.6.12-1.el7.x86_64.rpm-bundle.tar
```
2.安装依赖包
```
rpm -ivh mysql-cluster-community-data-node-7.6.12-1.el7.x86_64.rpm 
```
3.创建配置文件(**如果SQL节点也在这台机器，千万不要执行这个步骤，由SQL节点统一来创建**)
```
cd /etc
vim my.cnf
```
复制以下内容
```
[mysql_cluster]
ndb-connectstring=192.168.15.10
```
至此，数据节点安装完毕，直接启动,连接mgmd时默认使用1186端口
```
ndbd --initial (**备注：最后全部安装完毕统一执行**)
```
## 第五步：SQL节点安装
1.解压文件
```
cd /opt
tar -xvf mysql-cluster-community-7.6.12-1.el7.x86_64.rpm-bundle.tar
```
2.安装依赖包
```
rpm -ivh mysql-cluster-community-common-7.6.12-1.el7.x86_64.rpm 
rpm -ivh mysql-cluster-community-libs-7.6.12-1.el7.x86_64.rpm  
rpm -ivh mysql-cluster-community-client-7.6.12-1.el7.x86_64.rpm 
rpm -ivh mysql-cluster-community-server-7.6.12-1.el7.x86_64.rpm 
```

3.配置配置文件
在源文件尾部添加(其中192.168.15.11换成对应SQL节点IP)
```
ndbcluster
ndb-connectstring=192.168.15.10 
[ndbd]
connect-string=192.168.15.11
[mysql_cluster]
ndb-connectstring=192.168.15.10
[ndb_mgm]
connect-string=192.168.15.10
[ndbd_mgmd]
config-file=/usr/local/mysql-cluster/config.ini
```
至此，SQL节点安装完毕，直接启动
```
systemctl start mysqld (**备注：最后全部安装完毕统一执行**)
```

## 第六步：测试
1.启动集群
```
管理节点：ndb_mgmd -f /usr/local/mysql-cluster/config.ini --initial   （第一次启动才加参数--initial）
数据节点：ndbd --initial (第一次启动才加参数--initial)
SQL节点：systemctl start mysqld
备注：
启动顺序：管理节点->数据节点->SQL节点
关闭顺序：SQL节点->数据节点->管理节点
```
2.关闭集群
```
SQL节点:systemctl stop mysqld
数据节点:pkill ndbd
管理节点:ndb_mgm -e shutdown
```

3.管理节点查看信息
```
ndb_mgm
```
4.SQL节点的初始化
```
随机密码的查找:grep "password" /var/log/mysqld.log
mysql登录:mysql -u root -p
修改密码: set password for root@localhost = password('123');
设置简单密码策略:set global validate_password_policy=0;
设置密码长度策略:set global validate_password_length=1;
设置任意IP访问:GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '密码' WITH GRANT OPTION;
刷新修改配置:flush privileges;
```
