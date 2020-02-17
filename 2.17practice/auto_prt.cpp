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

int main()
{

	z::x_shared_ptr<tool>ptr1{ new tool };
	cout << "计数对象：" << ptr1.use_count() << endl;
	z::x_shared_ptr<tool>ptr2(ptr1);
	z::x_shared_ptr<tool>ptr3;
	ptr3 = ptr2;
	cout << "计数对象：" << ptr1.use_count() << endl;
	cout << "计数对象：" << ptr2.use_count() << endl;
	cout << "计数对象：" << ptr3.use_count() << endl;
	(*ptr3).value;
	ptr2->value;
	return 0;
}