---
title: java mysql-connector-java 操作mysql
date: 2020/12/28 20:00:00
categories: 技术
toc: True
tags: [java]
---

### 前言

mysql 连接库版本:mysql-connector-java-8.0.19.jar

### pom.xml 配置

```xml
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
    <version>8.0.19</version>
</dependency>
```

### sql

```sql
DROP TABLE IF EXISTS `stu`;
CREATE TABLE `stu` (
    `id` INT NOT NULL  COMMENT '编号',
    `name` varchar(100) DEFAULT NULL COMMENT '姓名',
    `age` INT NOT NULL  COMMENT '年龄',
    PRIMARY KEY (`id`)
) COMMENT='学生表';
INSERT INTO stu VALUES(1,'张三',20);
INSERT INTO stu VALUES(2,'李四',21);
INSERT INTO stu VALUES(3,'王五',19);
```

### 测试连接代码

```java
public static void testConnect(){
    try{
        //调用Class.forName()方法加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        System.out.println("成功加载MySQL驱动！");
    }catch(ClassNotFoundException e1){
        System.out.println("找不到MySQL驱动!");
        e1.printStackTrace();
    }

    String url="jdbc:mysql://localhost:3306/springboot?serverTimezone=UTC&useUnicode=true&characterEncoding=utf-8";    //JDBC的URL
    //调用DriverManager对象的getConnection()方法，获得一个Connection对象
    Connection conn;
    try {
        conn = DriverManager.getConnection(url,"root","root");//url 账号 密码
        //创建一个Statement对象
        Statement stmt = conn.createStatement(); //创建Statement对象
        System.out.print("成功连接到数据库！");
        stmt.close();
        conn.close();
    } catch (SQLException e){
        e.printStackTrace();
    }
}
```

### 增删查改代码

```java
public static void testProcess(){
    try{
        //调用Class.forName()方法加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        System.out.println("成功加载MySQL驱动！");

        String url="jdbc:mysql://localhost:3306/springboot?serverTimezone=UTC&useUnicode=true&characterEncoding=utf-8";    //JDBC的URL
        Connection conn;

        conn = DriverManager.getConnection(url,    "root","root");//url 账号 密码
        Statement stmt = conn.createStatement(); //创建Statement对象
        System.out.println("成功连接到数据库！");

        //查询数据的代码
        String sql = "select * from stu";    //要执行的SQL
        ResultSet rs = stmt.executeQuery(sql);//创建数据对象
        System.out.println("原始数据： \n " + "编号"+"\t"+"姓名"+"\t"+"年龄");
        while (rs.next()){
            System.out.print(rs.getInt(1) + "\t");
            System.out.print(rs.getString(2) + "\t");
            System.out.print(rs.getInt(3) + "\t");
            System.out.println();
        }

        //增加数据
        String sql1 = "insert into stu (id,name,age) values(?,?,?)";
        PreparedStatement pst = conn.prepareStatement(sql1);
        pst.setInt(1,4);
        pst.setString(2,"sunlu");
        pst.setInt(3, 25);
        pst.executeUpdate();
        ResultSet rs1 = stmt.executeQuery(sql);//创建数据对象
        System.out.println("插入后数据：  \n" + "编号"+"\t"+"姓名"+"\t"+"年龄");
        while (rs1.next()){
            System.out.print(rs1.getInt(1) + "\t");
            System.out.print(rs1.getString(2) + "\t");
            System.out.print(rs1.getInt(3) + "\t");
            System.out.println();
        }

        //修改数据的代码
        String sql2 = "update stu set name=? where id=?";
        pst = conn.prepareStatement(sql2);
        pst.setString(1,"nick");
        pst.setInt(2,1);
        pst.executeUpdate();

        ResultSet rs3 = stmt.executeQuery(sql);//创建数据对象
        System.out.println("修改后数据：  \n" + "编号"+"\t"+"姓名"+"\t"+"年龄");
        while (rs3.next()){
            System.out.print(rs3.getInt(1) + "\t");
            System.out.print(rs3.getString(2) + "\t");
            System.out.print(rs3.getInt(3) + "\t");
            System.out.println();
        }
        //删除数据的代码
        String sql3 = "delete from stu where id=?";
        pst = conn.prepareStatement(sql3);
        pst.setInt(1,1);
        pst.executeUpdate();

        ResultSet rs2 = stmt.executeQuery(sql);//创建数据对象
        System.out.println("删除后数据：   \n" + "编号"+"\t"+"姓名"+"\t"+"年龄");
        while (rs2.next()){
            System.out.print(rs2.getInt(1) + "\t");
            System.out.print(rs2.getString(2) + "\t");
            System.out.print(rs2.getInt(3) + "\t");
            System.out.println();
        }

        rs.close();
        stmt.close();
        conn.close();
    }catch(Exception e)
    {
        e.printStackTrace();
    }
}
```

### 备注

MySQL 8.0 以上版本的数据库连接有所不同:
1.MySQL 8.0 以上版本驱动包版本 mysql-connector-java-8.0.19.jar
2.com.mysql.jdbc.Driver 更换为 com.mysql.cj.jdbc.Driver
MySQL 8.0 以上版本不需要建立 SSL 连接的，需要显示关闭,最后还需要设置 CST
