#include<iostream>
#include<string>
using namespace std;
class A{
public:
	virtual void play()
	{
		cout << "A的play" << endl;
	}
	void eat()
	{
		cout << "A的eat" << endl;
	}
	virtual void fun()
	{
		cout << "A的fun" << endl;
	}
};
class B:public A{
public:
	virtual void play()//B重写了play
	{
		cout << "B的play" << endl;
	}
	void eat()
	{
		cout << "B的eat" << endl;
	}
	virtual void drink()
	{
		cout << "B的drink" << endl;
	}
};
void show(A* p)
{
	p->play();
	p->eat();
}
int main()
{
	A a;
	a.eat();
	B b;
	b.eat();
	A* pb = &b;
	pb->play();
	pb->eat();
	pb->fun();
	show(&b);
	return 0;
}