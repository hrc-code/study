# 牛客刷题知识积累

[TOC]

- 数据缓存( [-128]到[127] Byte Short Integer Long  [0]到[127] Character )
  - 当封装类与基本数据类型进行比较(` ==与equals`)时，会自动拆箱 (`XXValue()`)  内容相同全为true
  - 当封装类与封装类进行比较时，直接赋值会自动装箱（`valueOf()`）在范围内内容相同为true
  - Boolean与boolean进行比较内容相同全为true
  - Integer与new Integer()永远为false
  
- 重载  （发生在同一个类中）
     - 同名不同参
     - 对返回值与访问修饰符没有限制

- 正则表达式

  | 符号  |            含义            |
  | :---: | :------------------------: |
  |   ^   |          起始符号          |
  |   $   |          结束符号          |
  | [n-m] | 表示n到m范围内中的一个数字 |
  |  \d   |      表示任何一个数字      |
  | X{m}  |          表示m个X          |





- 内部类
  - 成员内部类
  - 局部内部类
  - 匿名内部类（继承该类或实现接口的子类的对象）

- 逗号运算符  只存在于for循环中
```java
int i,j;
for(i=1,j=2;;)
```
- switch(x) x的数据类型
```java
byte short int  char  enum  类 
```

  - 类型转换

     - 小类型到大类型自动转换

     - 大类型到小类型需要手动强转

     - final 类型变量进行计算时不会进行类型转换，计算结果看右边类型

     - 在进行运算时，byte 、short、char会自动转换为int

     - +=会将表达式中的变量自动强转

     - 三目运算符会进行自动类型转换和自动拆箱（自动拆箱的缺点）

       ``` Java
       	//在进行运算时，byte 、short、char会自动转换为int    
           byte a=2,b=4;
        	byte c=a+b;//编译出错
       	int i=a+b;//编译正确
       	
       	//+=会将表达式中的变量自动强转
       	a+=b//编译正确+
        	a=a+b;//编译错误
       
       	Integer integer=null;
       	System.out.println(true?integer:1.0)//编译不出错，但运行时NPE
           System.out.println((double)integer)//反编译结果，先自动拆箱再自动类型转换
           System.out.println(true?1:1.0)//输出1.0 int类型的1转换为double类型的1.0
               
           //final 类型变量进行计算时不会进行类型转换，计算结果看右边类型（自动强转）
           final byte b1=1,b2=2;
       	byte b=b1+b2;
       	int  i=b1+b3;
       ```

      	

- 变量
  - 局部变量（赋值时才创建变量--分配空间）
  - 成员变量
    - 实例变量（无static修饰的变量）
    - 静态变量（类变量）

- 计算优先级
  
  - 以字符串为分界符，字符串前面的正常计算，字符串后面的当作字符拼接，有括号先计算括号里的

- 方法

  - 静态方法

    - 静态方法中不能出现this和super关键字

  - 实例方法

  - 抽象方法

    

    

- Java中创建对象的四种方式

  - 使用new关键字创建对象

  - 使用反射创建对象

  - 使用克隆创建对象

  - 使用反序列化创建对象

    ```java
      //通过构造器获得对象
            Object o1=new Object();//通过new关键字获得对象
            Object o2 = Object.class.getDeclaredConstructor().newInstance();//通过反射获得对象
            //通过内存获得对象
            Object o = new ObjectInputStream(new FileInputStream("需要获得对象的文件路径"))
                    .readObject();//通过反序列化获得对象  //通过构造器获得对象
            Object o1=new Object();//通过new关键字获得对象
            Object o2 = Object.class.getDeclaredConstructor().newInstance();//通过反射获得对象
            //通过内存获得对象
            Object o = new ObjectInputStream(new FileInputStream("需要获得对象的文件路径"))
                    .readObject();//通过反序列化获得对象
    ```

    

- Java中方法参数传递为值传递

```java
 public static void main(String[] args) {
        String str = "hrc";
        string(str);
        System.out.println(str);//输出结果为 hrc
        StringBuilder sb = new StringBuilder(str);
        System.out.println(sb);//输出结果为 hrc
        stringBuilder(sb);
        System.out.println(sb);//输出结果为 hrchut
    }
   
    public static void string(String str) {
        str = "hrc";
    }

    public static void stringBuilder(StringBuilder sb) {
        sb.append("hut");
    }
```

[TOC]

#### 异常

- try-catch  try-finally  try-catch-finally  异常处理只有这三种形式
- instanceof  二元运算符，用来判断左边的对象是否为右边类的子类，接口或抽象类的实现类
```java
        Object o = new Object();
        if (o instanceof String) {
            String str = (String) o;
            System.out.println("该对象是其子类或其子类的实例对象，并且将该对象强转为String类");
        }
        //Java14、15为preview版，Java16为正式版
        if (o instanceof String str) {
            System.out.println("该对象是其子类或其子类的实例对象，并且将该对象强转为String类");
        }
```

#### 泛型

```java
        //引入泛型原始的写法
        ArrayList<String> arrayList1 = new ArrayList<String>();
        //Java7写法
        ArrayList<String> arrayList2 = new ArrayList<>();
        //Java10的写法，只能用于局部变量,且必须初始化(数据类型只能为引用类型）和不能复合声明变量即一次只能声明一个变量
        var arrayList3 = new ArrayList<String>();
        //反编译字节码文件中写法
        ArrayList<String> arrayList4=new ArrayList();
```

#### API

- round 、floor、ceil
```java
round(x) 返回值为 x+0.5 floor(x+0.5)  向下取整
floor  地板 向下取整
ceil  天花板 向上取整
```

- 数组复制
  - System.arraycopy;
  - Arrays.copyOf

```java
//当目标数组容量大于等于源数组时使用
public static native void arraycopy(Object src,  int  srcPos,
                                        Object dest, int destPos,
                                        int length);
//底层使用System.arraycopy,但是无需手动创建目标数组
 public static <T,U> T[] copyOf(U[] original, int newLength, Class<? extends T[]> newType)
```

- 程序执行顺序
  - 如果类还没有被加载： 
    1、先执行父类的静态代码块和静态变量初始化，并且静态代码块和静态变量的执行顺序只跟代码中出现的顺序有关。 
    2、执行子类的静态代码块和静态变量初始化。 
    3、执行父类的实例变量初始化 
    4、执行父类的构造函数 
    5、执行子类的实例变量初始化 
    6、执行子类的构造函数 
  - 如果类已经被加载： 
    则静态代码块和静态变量就不用重复执行，再创建类对象时，只执行与实例相关的变量初始化和构造方法

- 加载器
  - 启动类加载器（Bootstrap ClassLoader)
  - 扩展类加载器（Extension ClassLoader)
  - 应用程序类加载器(Application ClassLoader)又称系统类加载器

#### 继承

- 构造器
    - 子类中的父类有参构造器必须在子类构造器的第一行
    - 父类没有空参构造器
      - 拥有有参构造器
        - 子类构造器中必须显性的调用父类的有参构造器
      - 没有有参构造器
        - 编译器为父类加上空参构造器
        - 子类构造器隐性调用父类的无参构造器
    - 父类拥有空参构造器
        - 子类构造器随意
- 重写方法的规则（两同两小一大）（发生在继承关系中）
     - 两同：方法名和参数列表必须相同
     - 两小：返回值或声明异常比父类小（或相同）
     - 一大：访问修饰符比父类大（或相同）
     - 注意：重写接口中的方法的访问修饰符只能为public
- 父类的public/protected final方法子类不能覆盖  只有private final方法可以覆盖
- 对象为子类，调用的方法从子类向父类层层去找方法   this 为调用者

#### 并发编程 
- 锁
  - synchronized修饰非静态方法锁的是this对象,修饰静态方法锁的是Class对象
  - 同步代码块锁的是任意对象
- Java用监视器机制实现了线程之间的同步执行

#### 接口与抽象类

- 接口

    - 接口之间可以多继承
    - 变量修饰符默认且只能为public static final
    - 方法 默认修饰符为public abstract
       - JDK 1.7  public abstract 抽象方法
       - JDK 1.8 添加 public static 静态方法  public default 默认方法
       - JDK 1.9 添加 private 私有方法

#### 计算机基础

- 位运算符
    - 按位与`&`
    - 按位非`~` ~n=-n-1
    - 按位或`|`
    - 按位异或`^`
 ```java
 在计算机中数字参与运算使用的是补码--机器码，真值--原码，输出的结果为真值
     补码+1=反码 整数的原码、反码、补码相等 最高位为符号位0为整数1为负数
int a=5;//0000 0000 0000 0101
int b=-3;//1111 1111 1111 1101 //1111 1111 1111 1100 // 1000 0000 0000 0011
按位与（&）运算符在两个操作数对应的二进位都为 1 时，该位的结果值才为 1。有0则为0 
   a&b=1;//0000 0000 0000 0101
按位非（~）将操作数的位反转。0变为 1 ，1 变为 0。
    //是用公式 ~n=-n-1  -5-1
    ~a=-6;//1111 1111 1111 1010补码  //1111 1111 1111 1001反码  //1000 0000 0000 0110原码
	~b=2 ;//0000 0000 0000 0010  
按位或（|）运算符在其中一个或两个操作数对应的二进制位为 1 时，该位的结果值为 1。有1则为1
    a|b=-3 //1111 1111 1111 1101
按位异或（^）相同为0，不同为1
   	a^b= -8;//1111 1111 1111 1000 //1111 1111 1111 0111 //1000 0000 0000 1000
    
 ```
