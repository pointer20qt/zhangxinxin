#include<iostream>
#include<string>
using namespace std;

class tool{
public:
	int value=0;
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
int x(){
	int t = 1;//t是左值，1是右值
	return t;
}
tool func(){
	tool t;//t是左值
	return t;
}
int main1123(){
	int a = 2;//a是左值，2是右值
	x();//返回的是右值，临时的变量
	//func();//返回t临时的变量
	int& la = a;//左值引用就是普通引用，内部是一个引用绑定一个左值
	int&& ra = 2;//右值引用,将一个右值对象的生命周期延长，和引用的时间一样长，左值引用不可引用右值
	{
		tool&& t = func();
		cout << "-------" << endl;
	}
	cout << "结束" << endl;
	const int d = 1;//常量左值
	const int& ld = d;
	return 0;
}