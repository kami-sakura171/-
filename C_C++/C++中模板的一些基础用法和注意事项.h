#pragma once

//���ļ�˵��ģ���е�һЩ����

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
	//�������߼�ʵ�ִ��롣
}
template<typename T1>
size_t List<T1>::length()
{
	return 1;
}
/*
* ���ϴ�����Ҫ˵���ˣ���ģ���ģ�庯�����壬��һ����ģ���ڲ���ģ�庯��ʱ���ⲿ����Ҫ�ֱ�д����ģ�����͡�
* ͬ��ʵ������ģ���а�������ģ�塣
*/
template<typename T>
union MyUnion
{
	T object;
	unsigned char byte[sizeof(T)];
};
/*
* ����ʾ��������������Ҳ������ģ�����͡�
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
* ����ʾ������������ģ������Ҳ������ȱʡ����ʵ��
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
	//fill(*array);						����Value����û��Ĭ�Ϲ��캯������ôȱʡʵ�ν���ʧ�ܣ�
}
/*
* �����������Ҫ�����ˣ���Ĭ��ȱʡʵ�β����ڹ��캯��ʱ�����ܻᵼ�±������
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
* ��Ա����ģ�岻����ʹ���麯����Ӳ��Ҫ��
* ��ͨ��Ա���Ա�����Ϊ�麯����
* ģ������ֱ�����Ψһ�ġ�
*/

template<typename T>
static void internal(){}

/*
* һ��ģ�嶼�����ⲿ�������ԡ�����
* ʹ��static���ε�ģ����Ȼ���߱��ⲿ��������
*/

template<typename T>
class Box;				//����һ������ģ��

/*
* ģ���������������м����š�
* ������м����ž�����������һ���ػ��汾��
*/

template<typename, int>
class X;

/*
* ģ��Ĳ��������ʹ�ã�����ʡ�Բ�д
*/

template<typename T, T* Root, template<T*> class Buf>
class Strucsure;

template<typename T, typename T::Allocator* alloc>
class Y;

/*
* ģ��Ĳ���������Ŀ���ʹ��ǰ��ģ�����ǰ�治��ʹ�ú���ġ�
*/

template<int* buf> class Lexer;

template<int length> class Buffer;

/*�����ǣ�ģ��ķ����Ͳ���*/

template<template<typename T,typename a = std::allocator<T>> class C>
void f(C<int>* p){}

template<template<typename T, typename a = std::allocator<T> > class Cortainer>
class Adaptation 
{
public:
	Cortainer<int> obj;			//����ȱʡ�Ĳ���������ʡ�Բ�д
};
template<template<typename T, typename = std::allocator<T> > class Cortainer>
class Adaptation2
{
public:
	Cortainer<int> obj;			//��ʾ�����������ģ���ģ����������ں�����ʹ�ÿ���ʡ�Բ�д��
};

/*
* ����˵����ģ���ģ��������Ծ���ȱʡֵ��
* ģ���ģ�����ȱʡֵ��ֻ������һ�Σ��������ظ��������ػ�ʱ�Եø���ע�⡣
* ȱʡ��ʵ�Σ������ǴӺ�����ǰ������
* ֻ����ģ������ģ������������в�����ģ�����,�����к���ʵ�Ρ�
*/


//8.3