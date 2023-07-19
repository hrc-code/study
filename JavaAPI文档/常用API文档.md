# 常用API文档

--------

#### 介绍

列举类中常用的方法

------

#### ArrayList

---

> java.util.ArrayList<E>

boolean add(E obj)

> 在数组列表末尾添加一个元素，永远返回true

int size()

> 返回数组列表中元素的个数

void ensureCapacity(int capacity)

>  确保数组列表在不重新分配内部存储数组的情况下有足够的容量存储给定数量的元素。

void trimToSize()

> 将数组容量大小变为数组元素的个数

E set(int index,E obj)

> 更改数组列表中指定索引元素，返回之前的内容。

E get(int idnex)

> 返回数组列表指定索引位置的元素

void  add(int index )

> 将元素插入数组列表中指定索引的位置

E remove(int index)

> 删除数组列表中指定索引位置元素，返回被删除的元素



#### Arrays

---

static int hashCode(xxx[] a)

> 返回数组a的散列码。xxx可以为8大基本类型和Object类型,重写父类的hashCode()

static boolean equals(xxx[] a, xxx[] b)

> 底层没看懂，大概a,b长度相等且各个位置元素相同返回true

> - 静态方法
>
> > - toString()
> > - copyOf()
> > - copyOfRange()
> > - sort()
> > - binarySearch()
> > - fill()
> > - equals()
>
> ![hrc_2023-07-10_22-10-21-1689068527302](常用API文档/hrc_2023-07-10_22-10-21-1689068527302.png)
> ![hrc_2023-07-10_22-10-29](常用API文档/hrc_2023-07-10_22-10-29-1689076566718.png)

#### BigInteger

> - 非静态方法
>
>   > - add
>   > - subtract()
>   > - multiply()
>   > - divide()
>   > - mod()
>   > - sqrt()
>   > - compareTo()
>   > - valueOf()
>
> - 静态方法
>   
>   - valueOf()
>
> ![hrc_2023-07-14_11-45-52](常用API文档/hrc_2023-07-14_11-45-52.png)

---

#### BigDecimal

> - 非静态方法
>
>   > - add()
>   > - subtract()
>   > - multiply()
>   > - divide()
>   > - compareTo()
>
> - 静态方法
>
>   > - valueOf()
>
> ![hrc_2023-07-14_11-46-04](常用API文档/hrc_2023-07-14_11-46-04.png)
>
> ![hrc_2023-07-14_11-46-10](常用API文档/hrc_2023-07-14_11-46-10.png)


#### Console

> - 静态方法
>
>   > - readPassword()
>   > - readLine()
>
> ![hrc_2023-07-14_11-43-12](常用API文档/hrc_2023-07-14_11-43-12.png)

#### Class

---

String getName()

> 返回调用者的类名

Class getSuperclass()

> 以Class对象的形式返回调用者的直接父类

#### Enum

---

> java.lang.Enum<E>  所有自定义的枚举类都是Enum的子类

static Enum valueOf(Class enumClass,String name)

> 返回给定类中有指定名的枚举常量

String toString()

> 返回枚举常量名

int ordinal()

> 返回枚举常量在enum声明中的位置，位置从0开始计数

int compareTo(E other)

> 如果枚举常量出现在other之前，返回一个负整数；如果this==other,则返回0；否则，返回一个正整数。



#### NumberFormat

---

> java.text.NumberFormat

Number parse(String s)

> 将String数字转换为Number类数字

#### Objects

---

static int hash(Object...objects)

> 返回一个散列码，底层调用的是Arrays.hashCode(Object[] a)

static boolean equals(Object a,Object b)

> 调用这个方法可以不用考虑a,b是否为null

static int hashCode(Object a)

> 如果a为null则返回0，否则调用自身的hashCode()

> - 静态方法 
>
> > - requireNonNull()
> > - requireNonNullElse()
> > - requireNonNullElseGet()
>
> ![hrc_2023-07-12_22-54-55](常用API文档/hrc_2023-07-12_22-54-55.png)

#### Object

----

int hashCode()

> 利用调用者的地址计算散列值

Class getClass()

> 返回调用者的类对象

boolean equals(Object obj)

> 比较调用者与otherObject的地址是否相同，建议子类重写

String toString()

> 将调用者变为字符串，建议子类重写

#### Path

> - 静态方法
>
>   > - of()
>
> ![hrc_2023-07-14_11-45-22](常用API文档/hrc_2023-07-14_11-45-22.png)

#### Random

> - 非静态方法
>
> > - Random()
> > - nextInt()
>
> ![hrc_2023-07-13_19-00-36](常用API文档/hrc_2023-07-13_19-00-36.png)


#### String

> - 非静态方法
>
>   > - charAt()
>   > - codePointAt()
>   > - offsetByCodePoints()
>   > - compareTo()
>   > - codePoints()
>   > - empty()
>   > - blankK()
>   > - equals()
>   > - equalsIgnoreCase()
>   > - startsWith()
>   > - endsWith()
>   > - indexOf()
>   > - lastIndexOf()
>   > - length()
>   > - codePointCount()
>   > - replace()
>   > - substring()
>   > - toLowerCase()
>   > - toUpperCase()
>   > - trim()
>   > - strip()
>   > - join()
>   > - repeat()
>
> ![hrc_2023-07-14_11-39-51](常用API文档/hrc_2023-07-14_11-39-51.png)
>
> ![hrc_2023-07-14_11-40-42](常用API文档/hrc_2023-07-14_11-40-42.png)
>
> ![hrc_2023-07-14_11-40-56](常用API文档/hrc_2023-07-14_11-40-56.png)
>
> ![hrc_2023-07-14_11-41-15](常用API文档/hrc_2023-07-14_11-41-15.png)

------

#### StringBuilder

> - 非静态方法
>
>   > - length()
>   > - append()
>   > - appendCodePoint()
>   > - setCharAt()
>   > - insert()
>   > - delete()
>   > - toString()
>
> ![hrc_2023-07-14_11-41-36](常用API文档/hrc_2023-07-14_11-41-36.png)
>
> ![hrc_2023-07-14_11-41-44](常用API文档/hrc_2023-07-14_11-41-44.png)

#### System

> - 静态方法
>
>   > - console()
>
> ![hrc_2023-07-14_11-43-05](常用API文档/hrc_2023-07-14_11-43-05.png)

#### Scanner

> - 非静态方法
>
>   > - nextLine()
>   > - next()
>   > - nextInt()
>   > - nextDouble()
>   > - hasNext()
>   > - hasNextInt()
>   > - hasNextDouble()
>
>   ![hrc_2023-07-14_11-41-56](常用API文档/hrc_2023-07-14_11-41-56.png)
>
>   ![hrc_2023-07-14_11-42-10](常用API文档/hrc_2023-07-14_11-42-10.png)
>
>   

#### 包装类

---


static int hashCode(xxx value)

> 返回给定值的散列码，这里 xxx指对应包装类类型的基本类型