#include <iostream>
#include"标头.h"
#include"B.h"
#include"C.h"
using namespace std;
#if 0 //看if后的值为真就可以调用，为假就不可食用
int a;
#endif;
#if DEBUG
#error 123;   //error与#ifndef一起使用，判断一些未被定义的宏
#endif;
int main()
{
	A a;
	a.run();
	/*C c;
	B b;*/
}
void A::run()
{
	cout << "123" << endl;
}
/*
任务2：练习使用 ifndef防止代码重复包含
*/