#pragma once

//本文件说明模板中的一些概念

template<typename T1>
class List
{
public:
	size_t length();

	template<typename T2>
	List(List<T2> const& other);
};

template<typename T1>
	template<typename T2>
List<T1>::List(List<T2> const& other)
{
	//。。。逻辑实现代码。
}
template<typename T1>
size_t List<T1>::length()
{
	return 1;
}
/*
* 以上代码主要说明了，类模板的模板函数定义，当一个类模板内部有模板函数时，外部定义要分别写两个模板类型。
* 同样实用于类模板中包含的类模板。
*/
template<typename T>
union MyUnion
{
	T object;
	unsigned char byte[sizeof(T)];
};
/*
* 以上示例表明，联合体也可以是模板类型。
*/

template<typename T>
void report_top(std::stack<T> const&, T number = 10);

template<typename T>
void fill(std::array<T,5> const&, T const& number = T());

template<typename T>
void report_top(std::stack<T> const& other, T number){}
template<typename T>
void fill(std::array<T,5> const& other, T const& number){}

/*
* 以上示例表明，函数模板声明也可以有缺省调用实参
*/
class Value
{
public:
	Value(int){}
};

void init(std::array<Value, 5>* array)
{
	Value value(0);
	fill(*array, value);
	//fill(*array);						由于Value类型没有默认构造函数，那么缺省实参将会失败！
}
/*
* 上面的例子主要表明了，当默认缺省实参不存在构造函数时，可能会导致编译错误。
*/

template<typename T>
class Dyname
{
public:
	virtual ~Dyname(){}

	template<typename T2>
	/* virtual */ void copy(T2 const& other){}
};

/*
* 成员函数模板不允许使用虚函数，硬性要求。
* 普通成员可以被声明为虚函数。
* 模板的名字必须是唯一的。
*/

template<typename T>
static void internal(){}

/*
* 一般模板都具有外部连接属性。但是
* 使用static修饰的模板仍然不具备外部链接属性
*/

template<typename T>
class Box;				//声明一个基本模板

/*
* 模板的声明不允许带有尖括号。
* 如果带有尖括号就是类似声明一种特化版本。
*/

template<typename, int>
class X;

/*
* 模板的参数如果不使用，可以省略不写
*/

template<typename T, T* Root, template<T*> class Buf>
class Strucsure;

template<typename T, typename T::Allocator* alloc>
class Y;

/*
* 模板的参数，后面的可以使用前面的，但是前面不能使用后面的。
*/

template<int* buf> class Lexer;

template<int length> class Buffer;

/*以上是，模板的非类型参上*/

template<template<typename T,typename a = std::allocator<T>> class C>
void f(C<int>* p){}

template<template<typename T, typename a = std::allocator<T> > class Cortainer>
class Adaptation 
{
public:
	Cortainer<int> obj;			//具有缺省的参数，可以省略不写
};
template<template<typename T, typename = std::allocator<T> > class Cortainer>
class Adaptation2
{
public:
	Cortainer<int> obj;			//本示例表明，如果模板的模板参数名字在后续不使用可以省略不写。
};

/*
* 以上说明了模板的模板参数可以具有缺省值。
* 模板的模板参数缺省值，只能声明一次，不允许重复声明，特化时显得格外注意。
* 缺省的实参，必须是从后面向前声明。
* 只有类模板中有模板参数。函数中不能有模板参数,可以有函数实参。
*/


//8.3