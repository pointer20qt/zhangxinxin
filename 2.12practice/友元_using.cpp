/*1.ʹ��using����Ԫ���ڴ����������ô�*/
#include<iostream>
using namespace std;
#include <string>
class people
{
	int age = 0;
public:
	friend void hhh(people &h);               /****��Ԫ����****/
	friend class animal;                             /****��Ԫ��****/
};
void hhh(people &h)
{
	cout << h.age<<"-----people�ĺ���hhh" << endl;
}
class animal                                             /****��Ԫ��****/
{
public:
	void sss(people &p)
	{
		cout << p.age << "-----animal�ĺ���hhh" << endl;
	}
};
/******using,typedef******/
int ss(char a, char b)
{
	cout << "����1" << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}

void bb(int a, const string& b)
{
	cout << "����1" << endl;
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



