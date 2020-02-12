/*1.使用using，友元并在代码中体现用处*/
#include<iostream>
using namespace std;
#include <string>
class people
{
	int age = 0;
public:
	friend void hhh(people &h);               /****友元函数****/
	friend class animal;                             /****友元类****/
};
void hhh(people &h)
{
	cout << h.age<<"-----people的函数hhh" << endl;
}
class animal                                             /****友元类****/
{
public:
	void sss(people &p)
	{
		cout << p.age << "-----animal的函数hhh" << endl;
	}
};
/******using,typedef******/
int ss(char a, char b)
{
	cout << "功能1" << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}

void bb(int a, const string& b)
{
	cout << "功能1" << endl;
	cout << a << endl;
	cout << b;
}
int main()
{
	people p;
	hhh(p);
	animal a;
	a.sss(p);

	typedef int(*A) (char, char);
	A aa;
	aa = ss;
	aa('a', 'b');
	using FP = void(*) (int, const string&);
	FP pp;
	pp = bb;
	bb('2', "222");
	return 0;
}



