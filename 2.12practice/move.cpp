/*2.����һ���࣬��д�ƶ����죬��ʹ��*/
#include<iostream>
using namespace std;
class principal{
	string name;
public:
	principal(string sname){
		this->name = sname;
	}
	~principal(){
		cout << "������ʦ" << endl;
	}
};
class school{
public:
	std::string schoolName;//ѧУ
	principal* master;

	~school(){
		cout << "������ѧ" << endl;
		delete master;
	}
	school(std::string schoolName){
		cout << "��ͨ���캯��" << endl;
		this->schoolName = schoolName;
		master = new principal("��ʦ");
	}
	//������һ��һ����
	school(const school& p){
		cout << "�������캯��" << endl;
		master = new principal(*(p.master));
	}
	school(school&& other) :schoolName(other.schoolName){
		cout << "�ƶ����캯��" << endl;
		master = other.master;
		other.master = NULL;
	}
};
school getschool(){
	school s2("��ѧ");
	return s2;
}
int main(){
	school s1(getschool());       /****�����ƶ����캯��****/
	school s3("��ѧ");
	school s4(s3);                    /****���ÿ������캯��****/
	cout << "����" << endl;   /****��������ʦ��������s1��s3��s4��****/
	return 0;
}
