# JDBC

## MVC

1.模型、视图、控制器



## DEMO

1.SSM

 

## 基础知识

1.JDBC是持久层：

2.作用：应用程序跟数据库打交道的桥梁

3.JDBC是一套标准规范，本身不实现；实现部分由各个数据库厂家进行驱动实现；



## 编码实战

1.Maven仓库地址：https://mvnrepository.com/

2.代码结构规范:

   controller:控制层（servlet、springmvc）

   service:业务层( 处理业务)

  dao:持久层(跟数据库打交道)

   dto:数据传输对象

  util:工具类

   

3.jdbc流程

   加载驱动-》创建连接->  得到一个SQL执行对象->执行返回结果->释放资源

  **URL规范：**

URI告诉JDBC程序连接哪个数据库，URI的写法为：

​     jdbc:<subprotocol>:<subname>

 

不同数据库连接的URI的格式是不同的，常用数据库的URI地址：

1、MySQL的URL格式：

​     jdbc:mysql://localhost:3306/databseName

2、Oracle的URL格式：

​     jdbc:oracle:thin:@localhost:1521:sid

3、SqlServer写法

​     jdbc:microsoft:sqlserver://localhost:1433;DatabaseName=sid



MYSQL注意事项：

1.驱动如果是8以上：Class.forName("com.mysql.cj.jdbc.Driver");

   URL后面要加参数：?serverTimezone=UTC

SQL对象：

| **createStatement()**     | 创建向数据库发送sql的Statement对象                 |
| ------------------------- | -------------------------------------------------- |
| **prepareStatement(sql)** | **创建向数据库发送预编译SQL的PrepareSatement对象** |
| prepareCall(sql)          | 创建执行存储过程的CallableStatement对象            |



资源的打开顺序：Connection、Statement、ResultSet

资源的关闭顺序：ResultSet、Statement、Connection



## PreparedStatement

解决SQL注入的问题，实际生产环境都采用这种方式。





JAVA与数据库的对应关系

| **Java** | **数据库**    |
| -------- | ------------- |
| byte     | tityint       |
| short    | smallint      |
| int      | int           |
| long     | bigint        |
| float    | float         |
| double   | double        |
| String   | varchar、char |
| Date     | datetime      |



## 事务

1.ACID

关系型数据库必备；

非关系型数据库(nosql)不具备(如果具备的话，已牺牲性能为代价的)



实际场景：死锁，数据库(锁行、锁表)，最终数据库崩溃；



注意三个地方：

1.设置手动提交事务：connection.setAutoCommit(false);

2.业务完成后，手动提交事务：connection.commit();

3.在出现异常情况，或者业务逻辑不正确情况，手动回滚事务：connection.rollback();



## IDEA+MAVEN

1.不会手动配置maven插件的，不熟悉原理的  直接把idea升级到群里发的最新版本；

2.如果还是出现问题，删除本地仓库，重新编译；



## 批处理

1.解决性能问题，一次性提交给数据库(不是说一次性提交越多越好，要找一个平衡点)；

2.stmt.addBatch();   stmt.executeBatch();stmt.clearBatch(）；



## 数据库连接池

1.作用：解决性能问题，尽可能把所有的连接利用最大化

2.原理：先初始化一批连接放到池子里面，应用不需要手动创建连接，直接从池子里面取。也不需要手动关闭，用完就丢回池子里面。

3.必备功能：最小连接数、最大连接数、监控和自动治理的功能。

4.常用的连接池：C3P0、tomcat自带的、weblogic自带、**阿里druid**

