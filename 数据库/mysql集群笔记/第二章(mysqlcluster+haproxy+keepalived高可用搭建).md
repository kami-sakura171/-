# mysqlcluster+haproxy+keepalived高可用搭建

[TOC]



## 第一步：环境准备
mysqlcluster集群环境(上一章搭建的环境)
```
192.168.15.10:管理节点
192.168.15.11:数据节点和SQL节点
192.168.15.12:数据节点和SQL节点
```
haproxy+keepalived环境
```
192.168.15.20:haproxy和keepalived
192.168.15.30:hproxy和keepalived
192.168.15.200:VIP
```

## 第二步：安装haproxy
192.168.15.20为主
```
yum install haproxy
cd /etc/haproxy
vi haproxy.cfg
```
修改配置文件为
```
global
        #工作目录
	chroot      /var/lib/haproxy
        #日志文件，使用rsyslog服务中local5日志设备（/var/log/local5），等级info
        log 127.0.0.1 local5 info
        #守护进程运行
        daemon

defaults
        log     global
        mode    http
        #日志格式
        option  httplog
        #日志中不记录负载均衡的心跳检测记录
        option  dontlognull
    #连接超时（毫秒）
        timeout connect 5000
    #客户端超时（毫秒）
        timeout client  50000
        #服务器超时（毫秒）
    timeout server  50000

#监控界面
listen  admin_stats
        #监控界面的访问的IP和端口
        bind  0.0.0.0:8888
        #访问协议
    mode        http
        #URI相对地址
    stats uri   /dbs
        #统计报告格式
    stats realm     Global\ statistics
        #登陆帐户信息
    stats auth  admin:admin
#数据库负载均衡
listen  proxy-mysql
        #访问的IP和端口
        bind  0.0.0.0:9999 
    #网络协议
        mode  tcp
        #负载均衡算法（轮询算法）
        #轮询算法：roundrobin
        #权重算法：static-rr
        #最少连接算法：leastconn
        #请求源IP算法：source
    balance  roundrobin
        #日志格式
    option  tcplog
        #在MySQL中创建一个没有权限的haproxy用户，密码为空。Haproxy使用这个账户对MySQL数据库心跳检测
    option  mysql-check user haproxy
    server  MySQL_1 192.168.15.11:3306 check weight 1 maxconn 2000
    server  MySQL_2 192.168.15.12:3306 check weight 1 maxconn 2000
        #使用keepalive检测死链
    option  tcpka  
```

192.168.15.30为备
```
跟192.168.15.20同样操作、同样配置
```

## 第三步：安装keepalived
192.168.15.20为主
```
yum install keepalived
cd /etc/keepalived
vi keepalived.conf
```
修改配置文件为
```
! Configuration File for keepalived

vrrp_instance  VI_200 {
    state  MASTER
    interface  ens33
    virtual_router_id  51
    priority  100
    advert_int  1
    authentication {
        auth_type  PASS
        auth_pass  123456
    }
    virtual_ipaddress {
        192.168.15.200
    }
}
```
192.168.15.30为备
```
yum install keepalived
cd /etc/keepalived
vi keepalived
```
修改配置文件为
```
! Configuration File for keepalived

vrrp_instance  VI_200 {
    state  BACKUP
    interface  ens33
    virtual_router_id  51
    priority  100
    advert_int  1
    authentication {
        auth_type  PASS
        auth_pass  123456
    }
    virtual_ipaddress {
        192.168.15.200
    }
}
```
俩台机器重启服务
```
systemctl start keepalived
```
创建MYSQL的账户haproxy,并且密码为空

## 第四部：测试
打开监控地址：
http://192.168.15.20:8888/dbs   用户名和密码都是admin
http://192.168.15.30:8888/dbs   用户名和密码都是admin