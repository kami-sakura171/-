### 1.枚举类型常量

常量名对应的枚举值默认从0开始，依次递增。可以指定。

枚举类型常量是全局性的。

```c++
#include <iostream>

using namespace std;

int main() 
{
	enum Days { Monday = 1 , Tuesday, Webnessday, Thursday, Friday, Saturday ,Sunday};
Days today;
today = Monday;
scanf("%d", &today);
switch (today)
{
case Monday:
	puts("\n Monday");
	break;
case Tuesday:
	puts("\n Tuesday");
	break;
case Webnessday:
	puts("\n Webnessday");
	break;
case Thursday:
	puts("\n Thursday");
	break;
case Friday:
	puts("\n Friday");
	break;
case Saturday:
	puts("\n Saturday");
	break;
case Sunday:
	puts("\n Sunday");
	break;
default:
	break;
}
return 0;
}
```
Monday、Tuesday、Webnessday等都不是变量，它们不占用数据区（常量区、全局数据区、栈区和堆区）的内存，而是直接被编译到命令里面，放到代码区，所以不能用`&`取得它们的地址.。

### 2.数组

int a[5] = {1,2,3,4,5};

注意：

​	DO 初始化数组

​	DO 记住，数组的第一个成员的偏移量(下标)是0

### 3.枚举和数组结合使用

```c++
#include <iostream> 
using namespace std;

int main()
{
	enum Weeks {Mon,Tue,Wed,Thu,Fri,Sat,Sun,DaysInWeek};//下标从 0 到 7 
	int ArrayWeek[DaysInWeek] = {10,20,30,40,50,60,70};
	cout<<"The value at Thuesday is: "<<ArrayWeek[Tue];

	return 0;
}
```
结果：

The value at Thuesday is: 20

### 4.二维数组

可延伸至多维数组

```c++
int array[5][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{10,11,12},
	{13,14,15}
};
//another form
int array[5][3] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
```

深刻理解：

```c
int a[3][3] = {

    {1, 2, 3},

    {4, 5, 6},

    {7, 8, 9}};
```

二维数组名a是指向指针的指针,指向a[0] , (a+1)指向a[1] 

a[0]指向第一行，a[0]+1为第一行第二个的元素的地址

a[1]指向第二行

a[2]指向第三行

验证：

```c
#include <stdio.h>

int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    printf("a ----->指向 %d\n", **a);
    printf("a+1---->指向 %d\n", **(a + 1));
    printf("*(a)+1->指向 %d\n", *(*(a) + 1));
    printf("a[0]--->指向 %d\n", *(a[0]));
    printf("a[0]+1->指向 %d\n", *(a[0] + 1));
}
```

输出结果：

a --------->指向 1

a+1------>指向 4

*(a)+1--->指向 2

a[0]------>指向 1

a[0]+1-->指向 2

二维数组作为参数传递：

```c
//方法一  形参给出第二维的长度
void func(int a[][size])
{
  a[i][j];//正确
}

int main()
{
  int a[3][3];
  func(a);
}
//方法二 形参声明为指向数组的指针
void func(int (*a)[size])
{
  a[i][j];//正确
}
int main()
{
  int a[3][3];
  func(a);
}

//方法三 形参声明为指针的指针
void func(int **a)
{
	a[i][j];//错误，编译器不知道第二维长度，无法定位
  *(a + row_size*i + j);
}
```

注意：

`int *a[]`声明指向数组的指针

int (*a)[] 声明直向特定长度的数组的指针

函数返回二维数组：

堆栈上面的数组是不能直接返回的会在函数退出的时候销毁掉

其他方法：
1、把二维数组定义为全局变量 这样可以直接在另一个函数中调用
2、把二维数组作为指针传入到第一个函数中 然后同样作为指针传到另一个函数中
3、动态分配内存 在赋值函数中动态分配 并用返回值返回，在另一个函数中进行访问

### 5.字符数组

```c++
char Greeting[] = "Hello World";//Hello 5字节，World 5字节，空格一字节，末尾一个空字节 
```

```c++
# include <iostream>
using namespace std;
int main()
{
	char buffer[80] = {'\0'};
	
	cout<<"Enter the string: ";
	cin>>buffer;			
	cout<<"\nHere's the buffer:"<<buffer<<endl;
	
	return 0;
}
```

### 6.cin.get()函数

cin 接收字符以空格，回车为结束标志。

解决这个问题，使用cin.get()函数。

cin.get()第一个版本：`cin.get(name,Arsize);`

接收两个参数：数组名（字符串（char*类型）的地址）和Arsize(int类型的整数)。

第二个版本：`cin.get()`接受一个char参数

get()有三个参数：

​	①要填充的缓冲区

​	②要获取的最大字符数

​	③结束输入的分隔符

住：分隔符默认为换行符。

```c++
# include <iostream>

using namespace std;

int main()
{
	char buffer[80] = {'\0'};
	
	cout<<"Enter the string: ";
	cin.get(buffer,79);
	cout<<"\nHere's the buffer:"<<buffer<<endl;
	
	return 0;
}
```

### 7.字符串复制

strcpy()，将一个字符串的全部内容复制到指定的缓冲区中。

```c++
#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	char String1[] = "No man is an island";
	char String2[80] = {'\0'};
	
	strcpy(String2,String1);
	
	cout<<"String1: "<<String1<<endl;
	cout<<"String2: "<<String2<<endl;
	return 0;
}
```

strncpy()，将一部分字符从一个字符串复制到另一个字符串。

```c++
#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	const int MaxLength = 80;
	char String1[] = "No man is an island";
	char String2[MaxLength+1] = {'\0'};
	
	strncpy(String2,String1,MaxLength);
	
	cout<<"String1: "<<String1<<endl;
	cout<<"String2: "<<String2<<endl;
	return 0;
}
```

### 8.String类

c++继承了以null结尾的C风格字符串和包含strcpy()的函数库，但是这些函数没有集成到面向对象的框架中。像所有数组一样，字符数组是静态的。你定义它们的大小。它们总是在内存中占据很大的空间，即使你不需要全部。写入超过数组的末尾是灾难性的。

如上所示，使用c风格的函数(如strcpy())将内存管理的责任交给了程序员。例如，在使用strcpy之前，您需要确保目标缓冲区已分配了正确的容量，以便能够容纳要复制到其中的字符串;否则，您将写入超过缓冲区的末尾，并导致严重的问题。这个约束在存储长度可变的用户输入(例如)方面有一个很大的缺点。程序员需要动态分配目标缓冲区(这需要您确定源缓冲区的长度并进行适当的分配)，或者使用静态分配的缓冲区(例如数组)，其长度是一个乐观的估计——在运行时可能仍然不够。因此，复制字符串这样的活动(本来应该是微不足道的)充满了存在缺陷的危险，在最坏的情况下可能会导致应用程序宕机。

为了解决这些经常发生的需求，c++标准库包括了一个string类，通过提供封装的数据集使处理字符串变得容易，以及用于操作字符串数据的函数。这个类被称为std::string，它处理内存分配细节，并使字符串的复制或赋值成为一个容易的活动。

```c++
#include <iostream>
#include <string.h>

using namespace std;
int main() 
{
	string str1("hello world");
	cout<<"str1 = "<<str1<<endl;
	
	string str2;
	str2 = str1;
	cout<<"str2 = "<<str2<<endl;
	str2 = "hello poi!";
	cout<<"str2 = "<<str2<<endl;
	string add;
	add = str1+str2;
	cout<<"str1 +sre2 = "<<add<<endl;
	
	return 0;
}
```

### 9.goto语句（不建议使用）

```c++
#include <iostream> 
using namespace std;

int main()
{
	int counter = 0;
	
loop: //标签
	counter++;
	cout<<"counter = "<<counter<<endl;
	if(counter < 5)
		goto loop;
	cout<<"Complete. Counter = "<<counter<<endl;
	return 0;
}
```

在第9行声明一个称为loop的标签，标记循环的顶部。执行goto语句， 这将导致程序执行跳回第9行的loop标签。 程序继续循环，直到计数器等于5，此时它“通过”循环并打印最终输出。

一般来说，程序员避免使用goto，而且有充分的理由。 Goto语句可以导致跳转到源代码中的任何位置，向后或向前。 不分青红皂白地使用goto语句造成了被称为意面代码的混乱、悲惨、无法阅读的程序。

### 12.const关键字

const 是 constant 的缩写，本意是不变的，不易改变的意思。在 C++ 中是用来修饰内置类型变量，自定义对象，成员函数，返回值，函数参数。

C++ const 允许指定一个语义约束，编译器会强制实施这个约束，允许程序员告诉编译器某值是保持不变的。如果在编程中确实有某个值保持不变，就应该明确使用const，这样可以获得编译器的帮助

**一、const修饰普通类型的变量**

```c++
const int a = 8;
int b = a;  //正确
a = 9;		//错误
```

a 被定义为一个常量，并且可以将 a 赋值给 b，但是不能给 a 再次赋值。对一个常量赋值是违法的事情，因为 a 被编译器认为是一个常量，其值不允许修改。

**二、const修饰指针变量**

const 修饰指针变量有以下三种情况：

- A: const 修饰指针指向的内容，则内容为不可变量。
- B: const 修饰指针，则指针为不可变量。
- C: const 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量。

对于 A:

```c++
const int *p = 8;
```

则指针指向的内容8不可改变。简称左定值，因为const位于*号左边。

对于B：

```c++
int a = 8;
int * const p = &a;
*p = 9;
int b = 7;
p = &b;   //错误!!!
```

对于 const 指针 p 其指向的内存地址不能够被改变，但其内容可以改变。简称，右定向。因为 const 位于 * 号的右边。

对于C:

```c++
int a = 8;
const int * const p = &a;
```

这时，const p 的指向的内容和指向的内存地址都已固定，不可改变。

对于 A，B，C 三种情况，根据 const 位于 * 号的位置不同，我总结三句话便于记忆的话：**"左定值，右定向，const修饰不变量"**。

**三、const传递参数和函数返回值**

**1.传递参数分以下三种情况：**

A：值传递的 const 修饰传递，一般这种情况不需要 const 修饰，因为函数会自动产生临时变量复制实参值。

```c++
#include<iostream>
 
using namespace std;
 
void Cpf(const int a)
{
    cout<<a;
    // ++a;  是错误的，a 不能被改变
}
 
int main(void)
 
{
    Cpf(8);
    system("pause");
    return 0;
}
```

B：当const参数为指针时，可以防止指针被意外篡改

```c++
#include<iostream>
 
using namespace std;
 
void Cpf(int *const a)
{
    cout<<*a<<" ";
    *a = 9;
}
 
int main(void)
{
    int a = 8;
    Cpf(&a);
    cout<<a; // a 为 9
    system("pause");
    return 0;
}
```

C：自定义类型的参数传递，需要临时对象复制参数，对于临时对象的构造，需要调用构造函数，比较浪费时间，因此我们采取 const 外加引用传递的方法。

并且对于一般的 int、double 等内置类型，我们不采用引用的传递方式。

```c++
#include<iostream>
 
using namespace std;
 
class Test
{
public:
    Test(){}
    Test(int _m):_cm(_m){}
    int get_cm()const
    {
       return _cm;
    }
 
private:
    int _cm;
};
 
 
 
void Cmf(const Test& _tt)
{
    cout<<_tt.get_cm();
}
 
int main(void)
{
    Test t(8);
    Cmf(t);
    system("pause");
    return 0;
}
```

**2.修饰函数的返回值**

A：const 修饰内置类型的返回值，修饰与不修饰返回值作用一样。

```c++
#include<iostream>
 
using namespace std;
 
const int Cmf()
{
    return 1;
}
 
int Cpf()
{
    return 0;
}
 
int main(void)
{
    int _m = Cmf();
    int _n = Cpf();
 
    cout<<_m<<" "<<_n;
    system("pause");
    return 0;
}
```

B: const 修饰自定义类型的作为返回值，此时返回的值不能作为左值使用，既不能被赋值，也不能被修改。

C: const 修饰返回的指针或者引用，是否返回一个指向 const 的指针，取决于我们想让用户干什么。

**四、const修饰类成员函数**

const 修饰类成员函数，其目的是防止成员函数修改被调用对象的值，如果我们不想修改一个调用对象的值，所有的成员函数都应当声明为 const 成员函数。

**注意：**const 关键字不能与 static 关键字同时使用，因为 static 关键字修饰静态成员函数，静态成员函数不含有 this 指针，即不能实例化，const 成员函数必须具体到某一实例。

下面的 get_cm()const; 函数用到了 const 成员函数：

```c++
#include<iostream>
using namespace std;
 
class Test
{
public:
    Test(){}
    Test(int _m):_cm(_m){}
    int get_cm()const
    {
       return _cm;
    }
 
private:
    int _cm;
};
 
void Cmf(const Test& _tt)
{
    cout<<_tt.get_cm();
}
 
int main(void)
{
    Test t(8);
    Cmf(t);
    system("pause");
    return 0;
}
```

如果 get_cm() 去掉 const 修饰，则 Cmf 传递的 const _tt 即使没有改变对象的值，编译器也认为函数会改变对象的值，所以我们尽量按照要求将所有的不需要改变对象内容的函数都作为 const 成员函数。

如果有个成员函数想修改对象中的某一个成员怎么办？这时我们可以使用 mutable 关键字修饰这个成员，mutable 的意思也是易变的，容易改变的意思，被 mutable 关键字修饰的成员可以处于不断变化中，如下面的例子。

```c++
#include<iostream>
using namespace std;
class Test
{
public:
    Test(int _m,int _t):_cm(_m),_ct(_t){}
    void Kf()const
    {
        ++_cm; // 错误
        ++_ct; // 正确
    }
private:
    int _cm;
    mutable int _ct;
};
 
int main(void)
{
    Test t(8,7);
    return 0;
}
```

这里我们在 Kf()const 中通过 ++_ct; 修改 _ct 的值，但是通过 ++_cm 修改 _cm 则会报错。因为 ++_cm 没有用 mutable 修饰。

### 13.浅拷贝，深拷贝，引用计数拷贝（写时拷贝）

**浅拷贝**：对于指针成员不可行。多个对象共用同一块空间，同一内存地址。

问题： 浅拷贝对于指针成员不可行。多个对象共用同一块空间，同一内存地址，但是在调用析构函数释放空间的时候，多次调用析构函数，这块空间被释放了多次，此时程序就会崩溃

**深拷贝**：采取在堆中申请新的空间来存取数据，这样数据之间相互独立。址拷贝。

**写时拷贝**：当读取到这个空间的时候，并不会开辟出一个一 模一样 的空间出来，当真正需要拷贝的时候，他才会开辟出空间。也就是拖延版的深拷贝。

写时拷贝技术是通过"引用计数"实现的，在分配空间的时候多分配4个字节，用来记录有多少个指针指向块空间，当有新的指针指向这块空间时，引用 计数加一，当要释放这块空间时，引用计数减一 (假装释放)，直到引用计数减为0时才真的释放掉这块空间。当有的指针要改变这块空间的值时，再 为这个指针分配自己的空间(注意这时引用计数的变化，旧的空间的引用计数减一，新分配的空间引 用计数加一)。

### 15.迭代器

要访问顺序容器和关联容器中的元素，需要通过“迭代器（iterator）”进行。迭代器是一个变量，相当于容器和操纵容器的算法之间的中介。迭代器可以指向容器中的某个元素，通过迭代器就可以读写它指向的元素。从这一点上看，迭代器和[指针](http://c.biancheng.net/c/80/)类似。

通过迭代器可以读取它指向的元素，`*迭代器名`就表示迭代器指向的元素。通过非常量迭代器还能修改其指向的元素。

迭代器都可以进行`++`操作。反向迭代器和正向迭代器的区别在于：

- 对正向迭代器进行`++`操作时，迭代器会指向容器中的后一个元素；
- 而对反向迭代器进行`++`操作时，迭代器会指向容器中的前一个元素。

按定义方式分类：

**1) 正向迭代器：**

容器类名::iterator 迭代器名;


**2) 常量正向迭代器：**

容器类名::const_iterator 迭代器名;


**3) 反向迭代器：**

容器类名::reverse_iterator 迭代器名;


**4) 常量反向迭代器：**

容器类名::const_reverse_iterator 迭代器名;

示例1：

```c++
#include <iostream>
#include <vector> 
using namespace std;

int main()
{
	vector<int> v;
	for(int n = 0;n < 5;n++)
	{
		v.push_back(n);
	}
	vector<int>::iterator i;
	for(i = v.begin();i != v.end();i++)
	{
		cout<<*i<<" ";
		*i *= 2;
	}
	cout<<endl;
	for(vector<int>::reverse_iterator j = v.rbegin();j != v.rend();++j)
	{
		cout<<*j<<" ";
	}
	return 0;
}
```

程序的输出结果是：
0 1 2 3 4
8 6 4 2 0

第 6 行，vector 容器有多个构造函数，如果用无参构造函数初始化，则容器一开始是空的。

第 10 行，begin 成员函数返回指向容器中第一个元素的迭代器。++i 使得 i 指向容器中的下一个元素。end 成员函数返回的不是指向最后一个元素的迭代器，而是指向最后一个元素后面的位置的迭代器，因此循环的终止条件是`i != v.end()`。

第 16 行定义了反向迭代器用以遍历容器。反向迭代器进行`++`操作后，会指向容器中的上一个元素。rbegin 成员函数返回指向容器中最后一个元素的迭代器，rend 成员函数返回指向容器中第一个元素前面的位置的迭代器，因此本循环实际上是从后往前遍历整个数组。

如果迭代器指向了容器中最后一个元素的后面或第一个元素的前面，再通过该迭代器访问元素，就有可能导致程序崩溃，这和访问 NULL 或未初始化的指针指向的地方类似。

第 10 行和第 16 行，写`++i`、`++j`相比于写`i++`、`j++`，程序的执行速度更快。回顾`++`被重载成前置和后置运算符的例子如下：

```c++
CDemo CDemo::operator++ ()
{  //前置++
    ++n;
    return *this;
}
CDemo CDemo::operator ++(int k)
{  //后置++
    CDemo tmp(*this);  //记录修改前的对象
    n++;
    return tmp;  //返回修改前的对象
}
```

后置`++`要多生成一个局部对象 tmp，因此执行速度比前置的慢。同理，迭代器是一个对象，[STL](http://c.biancheng.net/stl/) 在重载迭代器的`++`运算符时，后置形式也比前置形式慢。在次数很多的循环中，`++i`和`i++`可能就会造成运行时间上可观的差别了。因此，本教程在前面特别提到，对循环控制变量i，要养成写`++i`、不写`i++`的习惯。

注意，容器适配器 stack、queue 和 priority_queue 没有迭代器。容器适配器有一些成员函数，可以用来对元素进行访问。

功能分类：

不同容器的迭代器，其功能强弱有所不同。容器的迭代器的功能强弱，决定了该容器是否支持 STL 中的某种算法。例如，排序算法需要通过随机访问迭代器来访问容器中的元素，因此有的容器就不支持排序算法。

常用的迭代器按功能强弱分为输入、输出、正向、双向、随机访问五种，这里只介绍常用的三种。

1) 正向迭代器。假设 p 是一个正向迭代器，则 p 支持以下操作：++p，p++，*p。此外，两个正向迭代器可以互相赋值，还可以用`==`和`!=`运算符进行比较。

2) 双向迭代器。双向迭代器具有正向迭代器的全部功能。除此之外，若 p 是一个双向迭代器，则`--p`和`p--`都是有定义的。`--p`使得 p 朝和`++p`相反的方向移动。

3) 随机访问迭代器。随机访问迭代器具有双向迭代器的全部功能。若 p 是一个随机访问迭代器，i 是一个整型变量或常量，则 p 还支持以下操作：

- p+=i：使得 p 往后移动 i 个元素。
- p-=i：使得 p 往前移动 i 个元素。
- p+i：返回 p 后面第 i 个元素的迭代器。
- p-i：返回 p 前面第 i 个元素的迭代器。
- p[i]：返回 p 后面第 i 个元素的引用。


此外，两个随机访问迭代器 p1、p2 还可以用 <、>、<=、>= 运算符进行比较。`p1<p2`的含义是：p1 经过若干次（至少一次）`++`操作后，就会等于 p2。其他比较方式的含义与此类似。

对于两个随机访问迭代器 p1、p2，表达式`p2-p1`也是有定义的，其返回值是 p2 所指向元素和 p1 所指向元素的序号之差（也可以说是 p2 和 p1 之间的元素个数减一）。

| vector         | 随机访问     |
| -------------- | ------------ |
| deque          | 随机访问     |
| list           | 双向         |
| set / multiset | 双向         |
| map / multimap | 双向         |
| stack          | 不支持迭代器 |
| queue          | 不支持迭代器 |
| priority_queue | 不支持迭代器 |

例如，vector 的迭代器是随机迭代器，因此遍历 vector 容器有以下几种做法。下面的程序中，每个循环演示了一种做法。

```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(100); //v被初始化成有100个元素
    for(int i = 0;i < v.size() ; ++i) //size返回元素个数
        cout << v[i]; //像普通数组一样使用vector容器
    vector<int>::iterator i;
    for(i = v.begin(); i != v.end (); ++i) //用 != 比较两个迭代器
        cout << * i;
    for(i = v.begin(); i < v.end ();++i) //用 < 比较两个迭代器
        cout << * i;
    i = v.begin();
    while(i < v.end()) { //间隔一个输出
        cout << * i;
        i += 2; // 随机访问迭代器支持 "+= 整数"  的操作
    }
}
```

list 容器的迭代器是双向迭代器。假设 v 和 i 的定义如下：

```c++
list<int> v;
list<int>::const_iterator i;
```

则以下代码是合法的：

```c++
for(i=v.begin(); i!=v.end(); ++i)
cout << *i;
```

以下代码则不合法：

```c++
for(i=v.begin(); i<v.end(); ++i)
cout << *i;
```

因为双向迭代器不支持用“<”进行比较。以下代码也不合法：

```c++
for(int i=0; i<v.size(); ++i)
cout << v[i];
```

因为 list 不支持随机访问迭代器的容器，也不支持用下标随机访问其元素。

在 [C++](http://c.biancheng.net/cplus/) 中，数组也是容器。数组的迭代器就是指针，而且是随机访问迭代器。例如，对于数组 int a[10]，int * 类型的指针就是其迭代器。则 a、a+1、a+2 都是 a 的迭代器。

**迭代器的辅助函数**

STL 中有用于操作迭代器的三个函数模板，它们是：

- advance(p, n)：使迭代器 p 向前或向后移动 n 个元素。
- dis[tan](http://c.biancheng.net/ref/tan.html)ce(p, q)：计算两个迭代器之间的距离，即迭代器 p 经过多少次 + + 操作后和迭代器 q 相等。如果调用时 p 已经指向 q 的后面，则这个函数会陷入死循环。
- iter_swap(p, q)：用于交换两个迭代器 p、q 指向的值。


要使用上述模板，需要包含头文件 algorithm。下面的程序演示了这三个函数模板的 用法。

```c++
#include <list>
#include <iostream>
#include <algorithm> //要使用操作迭代器的函数模板，需要包含此文件
using namespace std;
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    list <int> lst(a, a+5);
    list <int>::iterator p = lst.begin();
    advance(p, 2);  //p向后移动两个元素，指向3
    cout << "1)" << *p << endl;  //输出 1)3
    advance(p, -1);  //p向前移动一个元素，指向2
    cout << "2)" << *p << endl;  //输出 2)2
    list<int>::iterator q = lst.end();
    q--;  //q 指向 5
    cout << "3)" << distance(p, q) << endl;  //输出 3)3
    iter_swap(p, q); //交换 2 和 5
    cout << "4)";
    for (p = lst.begin(); p != lst.end(); ++p)
        cout << *p << " ";
    return 0;
}
```

程序的输出结果是：
1) 3
2) 2
3) 3
4) 1 5 3 4 2

### 16.容器

**定义：**用于存放数据的类模板。容器中可以存放基本类型的变量，也可以存放对象。对象或基本类型的变量被插入容器中时，实际插入的是对象或变量的一个复制品。

STL 中的许多算法（即函数模板），如排序、查找等算法，在执行过程中会对容器中的元素进行比较。这些算法在比较元素是否相等时通常用运算符进行，比较大小通常用`<`运算符进行，因此，被放入容器的对象所属的类最好重载`==`和`<`运算符，以使得两个对象用`==`和`<`进行比较是有定义的

**优点：**不需要你预先告诉它你要存储多少对象，只要你创建一个容器对象，并合理的调用它所提供的方法，所 有的处理细节将由容器来自身完成。它可以为你申请内存或释放内存，并且用最优的算法来执行你的命令。

**分类：**顺序容器，关联容器

**顺序容器：**可变长动态数组 vector、双端队列 deque、双向链表 list

**①vector**：向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。

特性：

容器使用一个内存分配器对象来动态地处理它的存储需求。

顺序容器中的元素按照严格的线性顺序排序。可以通过元素在序列中的位置访问对应的元素

支持对序列中的任意元素进行快速直接访问，甚至可以通过指针算述进行该操作。操供了在序列末尾相对快速地添加/删除元素的操作。

它们之所以被称为顺序容器，是因为元素在容器中的位置同元素的值无关，即容器不是排序的。将元素插入容器时，指定在什么位置（尾部、头部或中间某处）插入，元素就会位于什么位置。

**关联容器：**set、multiset、map、multimap。关联容器内的元素是排序的。插入元素时，容器会按一定的排序规则将元素放到适当的位置上，因此插入元素时不能指定位置

默认情况下，关联容器中的元素是从小到大排序（或按关键字从小到大排序）的，而且用`<`运算符比较元素或关键字大小。因为是排好序的，所以关联容器在查找时具有非常好的性能。

容器都是类模板。它们实例化后就成为容器类。用容器类定义的对象称为容器对象。

例如，`vector<int>`是一个容器类的名字，`vector<int> a;`就定义了一个容器对象 a，a 代表一个长度可变的数组，数组中的每个元素都是 int 类型的变量；`vector<double> b;`定义了另一个容器对象 b，a 和 b 的类型是不同的。本教程后文所说的“容器”，有时也指“容器对象”，读者需要根据上下文自行判别。

任何两个容器对象，只要它们的类型相同，就可以用 <、<=、>、>=、==、!= 进行词典式的比较运算。假设 a、b 是两个类型相同的容器对象，这些运算符的运算规则如下。

- a == b：若 a 和 b 中的元素个数相同，且对应元素均相等，则`a == b`的值为 true，否则值为 false。元素是否相等是用`==`运算符进行判断的。
- a<b：规则类似于词典中两个单词比较大小，从头到尾依次比较每个元素，如果发生 a 中的元素小于 b 中的元素的情况，则`a<b`的值为 true；如果没有发生 b 中的元素小于 a 中的元素的情况，且 a 中的元素个数比 b 少，`a<b`的值也为 true；其他情况下值为 false。元素比较大小是通过`<`运算符进行的。
- a != b：等价于 !(a == b)。
- a > b：等价于 b < a。
- a <= b：等价于 !(b < a)。
- a >= b：等价于 !(a < b)。


所有容器都有以下两个成员函数：

- int size()：返回容器对象中元素的个数。
- bool empty()：判断容器对象是否为空。


顺序容器和关联容器还有以下成员函数：

- begin()：返回指向容器中第一个元素的迭代器。
- end()：返回指向容器中最后一个元素后面的位置的迭代器。
- rbegin()：返回指向容器中最后一个元素的反向迭代器。
- rend()：返回指向容器中第一个元素前面的位置的反向迭代器。
- erase(...)：从容器中删除一个或几个元素。该函数参数较复杂，此处省略。
- clear()：从容器中删除所有元素。


如果一个容器是空的，则 begin() 和 end() 的返回值相等，rbegin() 和 rend() 的返回值也相等。

顺序容器还有以下常用成员函数：

- front()：返回容器中第一个元素的引用。
- back()：返回容器中最后一个元素的引用。
- push_back()：在容器末尾增加新元素。
- pop_back()：删除容器末尾的元素。
- insert(...)：插入一个或多个元素。该函数参数较复杂，此处省略。

------

除了以上两类容器外，STL 还在两类容器的基础上屏蔽一部分功能，突出或增加另一部分功能，实现了

**三种容器适配器**：栈 stack、队列 queue、优先级队列 priority_queue。

**栈模板**

```c++
template <class T, class Sequence = deque<T> > class stack;
```

**队列模板**

```c++
template <class T, class FrontInsertionSequence = deque<T> > class queue;
```

栈可以用任何一种顺序容器作为基础容器，而队列只允许用前插顺序容器（双端队列或列表）

**栈和队列共同支持的操作**

- s1 op s2 op可以是==、!=、<、<=、>、>=之一，它会对两个容器适配器之间的元素按字典序进行比较
- s.size() 返回s的元素个数
- s.empty() 返回s是否为空
- s.push(t) 将元素t压入到s中
- s.pop() 将一个元素从s中弹出，对于栈来说，每次弹出的是最后被压入的元素，而对于队列，每次被弹出的是最先被压入的元素
- 不支持迭代器，因为它们不允许对任意元素进行访问

**栈和队列不同的操作**

- 栈的操作

- - s.top() 返回栈顶元素的引用

- 队列操作

- - s.front() 获得队头元素的引用
  - s.back() 获得队尾元素的引用

例：利用栈反向输出单词

```c++
int main() {
    stack<char> s;
    string str;
    cin >> str; //从键盘输入一个字符串
    //将字符串的每个元素顺序压入栈中
    for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
        s.push(*iter);
    //将栈中的元素顺序弹出并输出
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}
```

### 17.for range 循环

有以下几种形式：
1） for(auto elem : range)
创建range的拷贝，遍历时无法修改range中的元素。
2） for(auto& elem : range)
不创建range的拷贝，可以直接修改range中的元素，但一般用以下这种形式。
for(auto&& elem : range)
3)） for(const auto & elem : range)
不创建range的拷贝，只读range中的元素。

（elem接收range的元素，range被遍历的容器）

例：

```c++
int main() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	for (auto elem : vec) {
		cout << elem << endl;           //输出容器的遍历 1   2   3   4
	}
	return 0;
}
```

**auto标识符**

编程时常常需要把表达式的值赋给变量，这就要求在声明变量的时候清楚知道表达式的类型。然而要做到这一点并非那么容易，有时候甚至根本做不到。为了解决这个问题，C++11标准引入了auto类型说明符，用它就能让编译器替我们去分析表达式所属的类型。

与原来那些只对应一种特定类型的说明符不同，auto让编译器通过初值来推算变量类型。显然，auto定义的变量必须要有初始值。

使用auto具有以下几点好处：

可靠性：如果表达式的类型发生更改（包括函数返回值发生更改的情况），它也能工作。
性能：确保将不会进行转换。
可用性：不必担心类型名称拼写困难和拼写有误。
效率：代码会变得更高效。

```c++
auto item = val1 + val2; // 由val1和val2相加的结果推断出item的类型

auto i=0, *p = &i; // i是整数，p是整型指针
```


使用auto能在一条语句中声明多个变量。但是一条声明语句只能有一个基本数据类型，所以该语句中所有变量的初始基本数据类型都必须一致：

```c++
auto sz = 0, pi = 3.14; // Error!
```


编译器推断出的auto类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则，例如：

使用auto会删除引用

```c++
int count = 10;
int& countRef = count;
auto myAuto = countRef;

countRef = 11;
cout << count << " "; // print 11

myAuto = 12;
cout << count << endl; // print 11
```


你可能会认为 myAuto 是一个 int 引用，但它不是。它只是一个 int，因为输出为 11 11，而不是 11 12；如果 auto 尚未删除此引用，则会出现此情况。

const限定符
先引入一种表述：顶层const表示指针本身是个常量，底层const表示指针所指的对象是一个常量。一般auto会忽略掉顶层const，同时底层const则会保留下来，例如：

```c++
int i = 0;
const int ci = i, &cr = ci;
auto b = ci;  // b 是一个整数（ci的顶层const特性被忽略掉）
auto c = cr;  // c 是一个整数（cr是ci的别名，ci本身是一个顶层const）
auto d = &i;  // d 是一个整型指针（整数的地址就是指向整数的指针）
auto e = &ci; // e 是一个指向整数常量的指针（对常量对象取地址是一种底层const）
```


如果希望推断出的auto类型是一个顶层const，需要明确指出：

```c++
const auto f = ci; // ci 的推演类型是int，f是const int类型
```


还可以将引用的类型设置为auto，此时原来的初始化规则仍然适用：

```c++
auto &g = ci; // g是一个整型常量引用，绑定到ci
auto &h = 42; // Error: 不能为非常量引用绑定字面值
const auto &j = 42; // OK: 可以为常量引用绑定字面值
```




切记，符号*和&只从属于某个声明，而非基本数据类型的一部分，因此初始值必须是同一类型：

```c++
auto k = ci, &l = i; // k是整数，l是整型引用
auto &m = ci, *p = &ci; // m是对整型常量的引用，p是指向整型常量的指针
auto &n = i, *p2 = &ci; // Error: i的类型是int，而&ci的类型是const int
```

附上更多示例代码：

下面的声明等效。在第一个语句中，将变量j 声明为类型 int。在第二个语句中，将变量 k 推导为类型 int，因为初始化表达式 (0) 是整数

```c++
int j = 0;  // Variable j is explicitly type int.
auto k = 0; // Variable k is implicitly type int because 0 is an integer.
```

以下声明等效，但第二个声明比第一个更简单。使用 auto 关键字的最令人信服的一个原因是简单

```c++
map<int,list<string>>::iterator i = m.begin(); 
auto i = m.begin(); 
```

使用 iter 和 elem 启动循环时

```c++
#include <deque>
using namespace std;

int main()
{
    deque<double> dqDoubleData(10, 0.1);

for (auto iter = dqDoubleData.begin(); iter != dqDoubleData.end(); ++iter)
{ /* ... */ }

// prefer range-for loops with the following information in mind
// (this applies to any range-for with auto, not just deque)

for (auto elem : dqDoubleData) // COPIES elements, not much better than the previous examples
{ /* ... */ }

for (auto& elem : dqDoubleData) // observes and/or modifies elements IN-PLACE
{ /* ... */ }

for (const auto& elem : dqDoubleData) // observes elements IN-PLACE
{ /* ... */ }

}
```


下面的代码片段使用 new 运算符和指针声明来声明指针

```c++
double x = 12.34;
auto *y = new auto(x), **z = new auto(&x);
```

下一个代码片段在每个声明语句中声明多个符号。请注意，每个语句中的所有符号将解析为同一类型。

```c++
auto x = 1, *y = &x, **z = &y; // Resolves to int.
auto a(2.01), *b (&a);         // Resolves to double.
auto c = 'a', *d(&c);          // Resolves to char.
auto m = 1, &n = m;            // Resolves to int.
```

此代码片段使用条件运算符 (?:) 将变量 x 声明为值为 200 的整数：

```c++
int v1 = 100, v2 = 200;
auto x = v1 > v2 ? v1 : v2;
```

下面的代码片段将变量 x 初始化为类型 int，将变量 y初始化对类型 const int 的引用，将变量 fp 初始化为指向返回类型 int 的函数的指针。

```c++
int f(int x) { return x; }
int main()
{
    auto x = f(0);
    const auto & y = f(1);
    int (*p)(int x);
    p = f;
    auto fp = p;
    //...
}
```

下一个代码片段在每个声明语句中声明多个符号。请注意，每个语句中的所有符号将解析为同一类型。

```c++
auto x = 1, *y = &x, **z = &y; // Resolves to int.
auto a(2.01), *b (&a);         // Resolves to double.
auto c = 'a', *d(&c);          // Resolves to char.
auto m = 1, &n = m;            // Resolves to int.
```

此代码片段使用条件运算符 (?:) 将变量 x 声明为值为 200 的整数：

```c++
int v1 = 100, v2 = 200;
auto x = v1 > v2 ? v1 : v2;
```

下面的代码片段将变量 x 初始化为类型 int，将变量 y初始化对类型 const int 的引用，将变量 fp 初始化为指向返回类型 int 的函数的指针。

### 18.getline函数

虽然可以使用 cin 和 >> 运算符来输入字符串，但它可能会导致一些需要注意的问题。

当 cin 读取数据时，它会传递并忽略任何前导白色空格字符（空格、制表符或换行符）。一旦它接触到第一个非空格字符即开始阅读，当它读取到下一个空白字符时，它将停止读取。以下面的语句为例：

cin >> namel;

可以输入 "Mark" 或 "Twain"，但不能输入 "Mark Twain"，因为 cin 不能输入包含嵌入空格的字符串。下面程序演示了这个问题：

```c++
// This program illustrates a problem that can occur if
// cin is used to read character data into a string object.
#include <iostream>
#include <string> // Header file needed to use string objects
using namespace std;

int main()
{
    string name;
    string city;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Enter the city you live in: ";
    cin >> city;
    cout << "Hello, " << name << endl;
    cout << "You live in " << city << endl;
    return 0;
}
```

程序输出结果：

Please enter your name： John Doe
Enter the city you live in: Hello, John
You live in Doe

请注意，在这个示例中，用户根本没有机会输入 city 城市名。因为在第一个输入语句中，当 cin 读取到 John 和 Doe 之间的空格时，它就会停止阅读，只存储 John 作为 name 的值。在第二个输入语句中， cin 使用键盘缓冲区中找到的剩余字符，并存储 Doe 作为 city 的值。

为了解决这个问题，可以使用一个叫做 getline 的 [C++](http://c.biancheng.net/cplus/) 函数。此函数可读取整行，包括前导和嵌入的空格，并将其存储在字符串对象中。

getline 函数如下所示：

getline(cin, inputLine);

其中 cin 是正在读取的输入流，而 inputLine 是接收输入字符串的 string 变量的名称。下面的程序演示了 getline 函数的应用：

```c++
// This program illustrates using the getline function
//to read character data into a string object.
#include <iostream>
#include <string> // Header file needed to use string objects
using namespace std;

int main()
{
    string name;
    string city;
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Enter the city you live in: ";
    getline(cin, city);
    cout << "Hello, " << name << endl;
    cout << "You live in " << city << endl;
    return 0;
}
```

程序输出结果：

Please enter your name: John Doe
Enter the city you live in: Chicago
Hello, John Doe
You live in Chicago

但是在实际运行当中，很有可能出现读入的次数和预想的不一样。比如在循环中使用getline函数，会出现输入次数少1的情况。这是因为getline函数捕捉了你输入的换行。也就是说，你以为循环的第一次，实际上已经是第二次了。

解决方法：

```c++
//在getline函数之前添加语句
cin.get();
//或
cin.ignore();
//或
getline(cin,name,'\n');
```

### 19.std常用函数

#### std::remvoe()

remove(beg,end,val)

remove_if(beg,end,unarryPred)

其中，beg，end为迭代器，也可以为指针

机理为：通过用保存的元素覆盖元素而从序列中“移去”元素。remove移去的元素为等于val值，remove_if移去的是当unarryPred为真的那些元素，然后返回一个迭代器，该迭代器指向未移去的最后一个元素的下一个位置。

我们需要注意的是，remove函数是通过覆盖移去的，如果容器最后一个值刚好是需要删除的，则它无法覆盖掉容器中最后一个元素

#### **std::erase()**

三种用法：
（1）string &erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
（2）iterator erase(position);删除position处的一个字符(position是个string类型的迭代器)
（3）iterator erase(first,last);删除从first到last之间的字符（first和last都是迭代器）

### 20.cctype字符函数库

```c++
#include<cctype>

isalnum();//如果参数是字母数字，返回true

isalpha();//检查字符是否为字母字符，
    
iscntrl();//如果参数是控制字符，返回true

isdigit();//检查字符是否为数字字符

isgraph();//如果参数是处空格之外的打印字符，返回true

islower();//如果参数是小写字母，返回true

isupper();//如果参数是大写字母，返回true

isprint();//如果参数是打印字符（包括空格），返回true

isxdigit();//如果参数是十六进制数字，即0~9,a~f,A~F,返回true

tolower();//如果参数是大写字符，则返回其小写，否则返回该参数

toupper();//如果参数是小写字符，则返回其大写，否则返回该参数

isspace();//如果参数是标准空白字符，如空格''，换页'\f'，换行'\n',回车'\r',水平制表符'\t',垂直制表符'\v'

ispunct();//检查字符是否为标点符号
```

### 21.指针

解除引用运算符  *

##### 使用new分配内存：

```c++
int *p = new int;
```

new分配的内存块通常与常规变量声明分配的内存块不同。类似int i = 10;i的值被存在栈的内存区域中，而new从被称为堆或自由存储的内存区域分配内存。

##### delete释放内存

使用时要加上指向内存块的指针（最初用new分配的），

```c++
delete p；
```

将释放p指向的内存，但不会删除指针p本身。之后可以将p重新指向另一个新分配的内存块。

**注：一定要配对使用new和delete，否则将发生内存泄漏**

##### 使用new创建动态数组

```c++
int *p = new int[10];
```

new运算符返回第一个元素的地址

释放时使用delete

```c++
delete [] p;
```

数组名被解释为其第一个元素的地址，而对数组名应用地址运算符时，得到的是整个数组的地址：

```c++
shrot tell[10];

cout << tell << endl;

cout << &tell << endl;
```

从数字上说，这两个地址相同；但从概念上说，tell是一个两字节内存块的地址，而&tell是一个20字节内存块的地址。因此，tell + 1 将地址值加2，而&tell + 2 将地址加 20 。

### 22.简单文件输入输出

使用cin输入，程序将输入视为一系列的字节，其中每个字节都被解释为字节编码。不管目标数据类型是什么，输入一开始都是字符数据——文本数据。然后，cin对像负责将文本转换为其他类型。

##### 写入到文本文件中

准备：

1.包含头文件iostream，（定义了一个用于处理输出的ostream类，声明了一个名为cout的ostream变量（对象））。

2.指明名称空间std；

3.可以结合使用cout和运算符<<来显示各种类型的数据。

4.必须包含头文件fstream，（定义了一个用于处理输出的ofstream类），需要声明一个或多个ofstream变量（对象），并命名。

5.需要将ofstream对象与文件关联起来。方法之一是open（）方法。

6.使用完文件后，应使用close（）方法将其关闭。

7.可结合使用ofstream对象和运算符<<来输出各种类型的数据。

注意：虽然头文件iostream提供了一个预先定义好的名为cout的ostream对象，但必须声明自己的ofstream对象，为其命名，并将其同文件关联起来。

```c++
//声明
ofstream outFile;
ofstream fout;
//关联
outFile.open("fish.txt");
---------------------------------------
char filename[50];
cin>>filename;
fout.open(filename);
```

```c++
//写入
double wt = 126.7;
outFile << wt;  //将wt的内容写入outFile打开的fish.txt中
---------------------------------------
char line[80] = "hello world";
fout << line << endl;  //将line的内容写入fout打开的filename数组中
```

完整代码示例：

```c++
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;
    outFile.open("carinfo.txt");

    cout << "Enter the make and model of automobile:" << endl;
    cin.getline(automobile, 50);
    cout << "Enter the original asking price:";
    cin >> a_price;
    d_price = 0.913 * a_price;

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model:" << automobile << endl;
    cout << "Year:" << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model:" << automobile << endl;
    outFile << "Year:" << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;
    outFile.close();

    return 0;
}
```

如果carinfo.txt不存在，open方法将新建一个，若已经存在，默认情况下，open方法将首先截断该文件，即将其长度截短到零——丢其原有的内容，然后将新的输出加入到该文件中。

##### 读取文本文件

准备：

1.包含头文件iostream，（定义了一个用于处理输入的istream类，声明了一个名为cin的istream变量（对象））。

2.指明名称空间std；

3.可以结合使用cin和运算符>>来显示各种类型的数据。

4.可以使用cin和get方法来读取一个字符，使用cin和getline来读取一行字符

5.可以结合使用cin和eof（），fail（）方法来判断输入是否成功

6.必须包含头文件fstream，（定义了一个用于处理输入的ifstream类），需要声明一个或多个ifstream变量（对象），并命名。

7.需要将ifstream对象与文件关联起来。方法之一是open（）方法。

8.使用完文件后，应使用close（）方法将其关闭。

9.可结合使用ifstream对象和运算符>>来读取各种类型的数据。

10.ifstream对象本身被用作测试条件时，如果最后一个读取操作成功，他将被转化为布尔值true，否则被转化为false

注意：虽然头文件iostream提供了一个预先定义好的名为cin的istream对象，但必须声明自己的ifstream对象，为其命名，并将其同文件关联起来。

```c++
//声明对象
ifstream inFile;
ifstream fin;
```

```c++
//关联
inFile.open("bowling.txt");
------------------------------
char filename[50];
cin >> filename;
fin.open(filename);
```

```c++
//使用
double wt;
inFile >> wt;
------------------------------
char line[81];
fin.getline(line,81);
```

### 23.函数和C风格字符串

c风格字符串由一系列字符组成，以空值字符结尾。

将字符串作为参数时意味着传递的是地址。但可以使用const来禁止对字符串参数进行修改。

假设要将字符串作为参数传递给函数，则表示字符串的方式有三种：

**·**char数组

**·**用引号括起来的字符串常量（也称字符串字面值）

**·**被设置为字符串的地址的char指针

但是，实际上传递的是字符串第一个字符的地址。这意味着字符串函数原型应将其表示字符串的形参声明为char *类型。

C风格字符串与常规char数组之间的一个重要区别是，字符串有内置的结束字符（包含字符，但不以空值字符结尾的char数组只是数组，而不是字符串）。这意味着不必将字符串长度作为参数传递给函数，而函数可以使用循环依次检查字符串中的每个字符，直到遇到结尾的控制字符为止。

注：

当以`char *p = "hello";`的方式声明字符串变量时，会出现如下警告

> warning: ISO C++ forbids converting a string constant to ‘char*‘ [-Wwrite-strings]

这是因为在赋值操作的时候，等号两边的变量类型不一样，那么编译器会进行一种叫做 隐式转换(implicit conversion) 的操作来使得变量可以被赋值。上面的表达式中，等号右边的"hello"是一个不变常量，在c++中叫做string literal，type是const char *，而p则是一个char指针。如果强行赋值就是将右边的常量强制类型转换成一个指针，结果就是我们在修改一个const常量。编译运行的结果会因编译器和操作系统共同决定，有的编译器会通过，有的会抛异常，就算过了也可能因为操作系统的敏感性而被杀掉。

修改方法：`const char  *p = "hello";`

### 24.从键盘输入值给字符数组赋值

在我们定义一个字符串变量的时候如需使用键盘输入数据给字符串赋值一般会用到三种方式，记录一下三种方式的区别。

如我们定义一个字符串 char name[10];(10代表字符串的长度)。

scanf：

```c++
char name[10];
scanf("%s",name);
printf("输入的name是:[%s]",name);
```

如果此时输入的字符含有空格 ，在给字符串赋值的时候就会出现 明明空格后面还有字符，并且长度不超过9位的情况下，字符串缺只被赋值到了空格处 如：zhang san，此时name值却只为 zhang。原来在字符被存到缓冲区的时候，空格代表着结束字符，scanf方法对字符串赋值的时候，读取到空格处就默认结束了。

gets:

```c++
char name[10];
gets(name);
printf("输入的name是[%s]",name);
```

在使用gets方法给字符串赋值的时候，不会遇到有空格就停止的问题。但是有一个情况是如果我们输入的字符串长度大于所定义的字符串长度减1的时候，如：zhang san feng，此时name所被赋予的值是 zhang san feng，此时字符串长度竟然有14位，所定义的字符串长度仅有10位，会造成数组越界的后果。

fgets：

```c++
char name[10];
//name 字符串 ，10 长度， stdin默认输入设备
fgets(name,10,stdin);
printf("输入的name是[%s]",name);
```

此方法有三个参数，其中第二个代表字符串所定义的长度，可有效避免数组越界

当我们输入 zhang san feng的时候。

可以看到，我们获取到的输出结果是 zhang san 。空格算一个字符所以刚好有十个字符

### 25.typedef与#define的区别

typedef 是用来定义一种类型的新别名的，它不同于宏（#define），不是简单的字符串替换。它的新名字具有一定的封装性，所以新命名的标识符具有更易定义变量的功能，它是语言编译过程的一部分，但它并不实际分配内存空间。

而 #define 只是简单的字符串替换（原地扩展），它本身并不在编译过程中进行，而是在这之前（预处理过程）就已经完成了。因此，它不会做正确性检查，不管含义是否正确它照样会带入，只有在编译已被展开的源程序时才会发现可能的错误并报错。

接下来看下面的示例代码：

```c++
typedef char * PCHAR1;
#define PCHAR2 char*
/* c1、c2 都为char *，typedef为char *引入了一个新的别名*/
PCHAR1 c1, c2；
/*相当于char * c3， c4；c3是char *，而c4是char   */
PCHAR2 c3, c4；
```

在定义上述的变量时，c1、c2 与 c3 按照预期都被定义成 char* 类型。值得注意的是，c4 却被定义成 char 类型，而不是我们所预期的 char*。其根本原因就在于 #define 只是简单的字符串替换，而 typedef 则是为一个类型引入一个新的别名。

### 26.[]运算符

`arr [ n ] =  *( arr + n)`   也就是说，也可以写成 n[ arr ]













































