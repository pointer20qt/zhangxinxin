#include<iostream>
#include<string>
using namespace std;
class A{
public:
	virtual void play()
	{
		cout << "A��play" << endl;
	}
	void eat()
	{
		cout << "A��eat" << endl;
	}
	virtual void fun()
	{
		cout << "A��fun" << endl;
	}
};
class B:public A{
public:
	virtual void play()//B��д��play
	{
		cout << "B��play" << endl;
	}
	void eat()
	{
		cout << "B��eat" << endl;
	}
	virtual void drink()
	{
		cout << "B��drink" << endl;
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