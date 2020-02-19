#include<iostream>
#include<string>
#include<memory>
#include"auto_new.h"
#include"unique_ptr_new.h"
#include"shared_ptr_new.h"
using namespace std;
class tool{
public:
	int value;
	tool(){
		cout << "tool构造" << endl;
	}
	tool(int a){
		cout << "tool单参构造" << endl;
	}
	tool(const tool&){
		cout << "tool拷贝构造" << endl;
	}
	tool(tool&&){
		cout << "tool移动构造" << endl;
	}
	~tool(){
		cout << "tool析构" << endl;
	}
	tool& operator = (const tool&){
		cout << "tool拷贝赋值" << endl;
		return *this;//返回当前对象
	}
	tool& operator = (tool&&){
		cout << "tool移动赋值" << endl;
		return *this;
	}
};

void nomall(){
	z::x_shared_ptr<tool>ptr1;
	cout << "计数对象：" << ptr1.use_count() << endl;
	z::x_shared_ptr<tool>ptr2(ptr1);
	z::x_shared_ptr<tool>ptr3;
	ptr3 = ptr2;
	cout << "计数对象：" << ptr1.use_count() << endl;
	cout << "计数对象：" << ptr2.use_count() << endl;
	cout << "计数对象：" << ptr3.use_count() << endl;
	(*ptr3).value;
	ptr2->value;
}
class node{
public:
	z::x_weak_ptr<node> pre;
	z::x_weak_ptr<node> next;
	~node(){
		cout << "结点析构" << endl;
	}
};
int main()
{
	z::x_shared_ptr<node> node1 = { new node };
	z::x_shared_ptr<node> node2 = { new node };
	cout << node1->next.use_count() << endl;
	//node1->next.operator=(node2);
	//node2->pre.operator=(node1);//使用移动赋值，提高性能
	node1->next = node2;
	node2->pre = node1;
	cout << node1.use_count() << endl;
	return 0;
}