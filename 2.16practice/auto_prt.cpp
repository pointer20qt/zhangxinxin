#include<iostream>
#include<string>
#include"auto_new.h"
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
	tool* p = new tool;
	auto_ptr<tool>ptr(p);
	ptr.reset(p);//reset释放之前的，附成新的
	//auto_ptr<tool>ptr1{ new tool };
	//auto_ptr<tool>ptr2(ptr1);
	//auto_ptr<tool>ptr3;
	//ptr3 = ptr2;//ptr1中的东西全给了ptr2，ptr3等于ptr2中的东西

	x_auto_ptr<tool>ptr1{ new tool };
	x_auto_ptr<tool>ptr2(ptr1);
	x_auto_ptr<tool>ptr3;
	ptr3 = ptr2;//ptr1中的东西全给了ptr2，ptr3等于ptr2中的东西
	(*ptr3).value;
	ptr2->value;
	return 0;
}