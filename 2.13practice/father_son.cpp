/*1�����������ָ��ʵ�ֶ�̬Ч����ʵ����������ʵ�� ���ء�*/
#include<iostream>
#include<string>
using namespace std;
class school{
protected:
	string schoolName;//ѧУ
public:
	school(std::string schoolName){
		cout << "����school" << endl;
		this->schoolName = schoolName;
	}
	//school(){}//����û�й����ʱ��ֻ�и������Ĭ�Ϲ���
	virtual~school(){
		cout << "����school" << endl;
	}
	school(const school& p){
		cout << "����school" << endl;
	}
	virtual void schoolopen()//ʹ���麯�� 
	{
		cout << this->schoolName << "��ѧ" << endl;
	}
};
//�̳лὫ���г�Ա������
class university :public school{
	int typ;
public:
	university() :school("uu_school"){
		cout << "university����" << endl;
	}
	~university(){
		cout << "����university" << endl;
	}
	void schoolopen()                       /**********�Ӻ͸�����һ��ʱ��������***********/
	{
		cout << "university��ѧ" << endl;
	}
};
class small :public school{
public:
	small() :school("ss_school"){//��ʼ�������б�
		cout << "small����" << endl;
	}
	void schoolopen()                       /**********������virtual������д***********/
	{
		cout << "small��ѧ" << endl;
	}
};
//��̬�ĵ��÷���
void printsch(school * sch)
{
	sch->schoolopen();
	delete sch;
}
void printsch(school&  sch)
{
	sch.schoolopen();
	delete &sch;
}
int main(){
	university u;
	u.schoolopen();
	//�ȿ����࣬���������и����ʼ�������ȵ��ó�ʼ�����࣬�ٹ�������
	small sm;
	sm.schoolopen();
	/*����ָ��ָ���������ɵ������෽��
	university u2;
	school*s1 = &u2;
	school&s2 = u2;
	printsch(s1);
	*/
	school*s1 = new university;//����ָ�붨���������	�������麯����һ��Ҫ��������,��������ڴ�й©
	printsch(s1);
	cout << "main����" << endl;
	return 0;
}