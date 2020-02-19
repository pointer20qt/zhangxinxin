#include<iostream>
#include<string>
#include<memory>
#include"auto_new.h"
#include"unique_ptr_new.h"
#include"shared_ptr_new.h"
using namespace std;
class tool{
public:
	int value;
	tool(){
		cout << "tool����" << endl;
	}
	tool(int a){
		cout << "tool���ι���" << endl;
	}
	tool(const tool&){
		cout << "tool��������" << endl;
	}
	tool(tool&&){
		cout << "tool�ƶ�����" << endl;
	}
	~tool(){
		cout << "tool����" << endl;
	}
	tool& operator = (const tool&){
		cout << "tool������ֵ" << endl;
		return *this;//���ص�ǰ����
	}
	tool& operator = (tool&&){
		cout << "tool�ƶ���ֵ" << endl;
		return *this;
	}
};

void nomall(){
	z::x_shared_ptr<tool>ptr1;
	cout << "��������" << ptr1.use_count() << endl;
	z::x_shared_ptr<tool>ptr2(ptr1);
	z::x_shared_ptr<tool>ptr3;
	ptr3 = ptr2;
	cout << "��������" << ptr1.use_count() << endl;
	cout << "��������" << ptr2.use_count() << endl;
	cout << "��������" << ptr3.use_count() << endl;
	(*ptr3).value;
	ptr2->value;
}
class node{
public:
	z::x_weak_ptr<node> pre;
	z::x_weak_ptr<node> next;
	~node(){
		cout << "�������" << endl;
	}
};
int main()
{
	z::x_shared_ptr<node> node1 = { new node };
	z::x_shared_ptr<node> node2 = { new node };
	cout << node1->next.use_count() << endl;
	//node1->next.operator=(node2);
	//node2->pre.operator=(node1);//ʹ���ƶ���ֵ���������
	node1->next = node2;
	node2->pre = node1;
	cout << node1.use_count() << endl;
	return 0;
}