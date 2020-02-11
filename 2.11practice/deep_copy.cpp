/*2.写一个不用深拷贝技术就会出问题的类，并实现拷贝构造*/
#include<iostream>
using namespace std;
class people{
private:
	char *name;
public:
	people()
	{
		cout << "创建name" << endl;
		name = (char*)malloc(20);
		strcpy(name, "12345");
	}
	char* getName()
	{
		return name;
	}
	people(const people& h)
	{
		cout << "拷贝name" << endl;
		this->name = (char*)malloc(20);  //新开一部分空间防止同一个空间被释放两次
		strcpy(this->name, h.name);
	}
	/*people(const people& h)
	{
		cout << "拷贝name" << endl;
		this->name = h.name;
	}*/
	~people()
	{
		cout << "析构name" << endl;
		delete name;//浅拷贝将name释放2次
	}
};
int main()
{
	people p;
	cout << p.getName() << endl;
	people p2(p);
	cout << p2.getName() << endl;//析构p2
	return 0;//析构p
}
