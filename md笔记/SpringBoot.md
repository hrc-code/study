# SpringBoot

## 配置文件

- properties（高）
- yml
- yaml（低）

三种配置文件配置相同属性时properties>yml>yaml

## 整合第三方技术

## 服务器

- Tomcat
- Jetty
- Undertow

## 注解

### 注册为Bean

- @Componet

- @Controller

- @Service

- @Reponsitory

- @Mapper

- @RestController

### 依赖注入
#### 从容器注入
- @Autowired(按类型注入)
- @Qulifier+@Autowired(按名称注入)
- @Resource=@Qulifier+@Autowired
- @Primary(容器中相同类型对象>1时，注入该注解下的类)
#### 从配置文件注入
- @ConfigurationProperties(将配置文件中内容注入该注解下的类)