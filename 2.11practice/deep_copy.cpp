/*2.дһ��������������ͻ��������࣬��ʵ�ֿ�������*/
#include<iostream>
using namespace std;
class people{
private:
	char *name;
public:
	people()
	{
		cout << "����name" << endl;
		name = (char*)malloc(20);
		strcpy(name, "12345");
	}
	char* getName()
	{
		return name;
	}
	people(const people& h)
	{
		cout << "����name" << endl;
		this->name = (char*)malloc(20);  //�¿�һ���ֿռ��ֹͬһ���ռ䱻�ͷ�����
		strcpy(this->name, h.name);
	}
	/*people(const people& h)
	{
		cout << "����name" << endl;
		this->name = h.name;
	}*/
	~people()
	{
		cout << "����name" << endl;
		delete name;//ǳ������name�ͷ�2��
	}
};
int main()
{
	people p;
	cout << p.getName() << endl;
	people p2(p);
	cout << p2.getName() << endl;//����p2
	return 0;//����p
}
