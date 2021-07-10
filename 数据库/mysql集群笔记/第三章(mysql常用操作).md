# mysql常用操作

[TOC]


## 一、导出和导入
### 1.导出
```
mysqldump -uroot -p --default-character-set=utf8  数据库名 >文件名.sql  #导出整个库 
mysqldump -uroot -p --default-character-set=utf8 数据库名|gzip>文件名.sql.gz  #压缩导出整个库
mysqldump -uroot -p --default-character-set=utf8 数据库名 表名>文件名.sql #导出单个表

如果出现锁表错误，加上参数--skip_add_locks --skip-lock-tables
### ```
### 2.导入
```
mysql -uroot -p 数据库名<文件名.sql
gunzip -d < 文件名.sql.gz | mysql -uroot -p 数据库名 #导入压缩备份
```
## 二、设置慢查询跟踪
### 1.设置配置文件
```
vi /etc/my.cnf
slow_query_log=1 #打开设置
slow_query_log_file=/usr/local/mysql/data/slow-query.log #记录日志
long_query_time=1　　　　　　　　　　 # 慢查询日志的时间定义（秒），默认为10秒，多久就算慢查询的日志
log_queries_not_using_indexes=1    # 将所有没有使用带索引的查询语句全部写到慢查询日志中
重启服务
```
2.查看设置是否生效
```
mysql -uroot -p
show variables like "%slow_query_log%";
```
## 三、数据库备份
### 1.备份脚本-mysqlback.sh
```
#/bin/bash 
#file executable: chmod 755 filebak 
#PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin 
#export PATH 
bakdir="/usr/local/databack" 
filename="bwyp_`date +%Y%m%d`.sql.gz" 
if [ ! -x "$bakdir" ];then 
mkdir $bakdir 
fi 
cd $bakdir 
mysqldump -uroot -pbwyp --default-character-set=utf8 --skip_add_locks --skip-lock-tables  bwyp|gzip>$filename

```
`授权 chown 777 mysqlback.sh `
### 2.任务调度
```
1.命令进入任务调度  crontab -e
2.编写每天凌晨执行备份
#mysql备份任务
0 0 * * * /usr/local/task/mysqlback.sh
```