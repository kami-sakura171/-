# servlet编程

1.表单提交

  页面->controller(servlet)->业务处理

2.servlet

  web.xml配置     注解方式(@WebServlet)

3.GET、POST

4.获取表单数据的方法

**getParameter()**

**getParameterValues()**

**getParameterNames()**



## PageData思想

1.解决重复劳动，(持久层、控制层、页面层)

KEY-VALUE（MAP、表单、数据库行、列；NOSQL）

 2.控制层：request.getParameter()

​                  KEY-VALUE



## Filter过滤器

LISTENER->FILTER->SERVLET



实际场景：权限控制

1.过滤器先要将静态资源文件、登录页面放开；

2.登录页面成功后的servlet里面必须把用户名和信息存储到session里面

3.在过滤器doFilter方法里面：

​    查看session是否存在这个用户，如果存在，直接放过；

​    如果session里面不存在这个用户，就直接跳转到登录页面；



## Cookie

1.目的：因为http协议是无状态的

2.存储在客户端浏览器中，不安全；



## 回顾总结

1.JAVA开发路径和配置的地方尽量不要用中文；

2.JAVA里面开发各个插件和环境跟版本之间的对应关系；



## SESSION

1.目的：因为http协议是无状态的

2.存储在应用服务中的(tomcat)，安全的；

**3.当应用服务器做集群的时候，如果没用通过代理限制，就需要做SESSION同步。**

​    redis   nginx代理





## 文件上传

1.工具包：commons