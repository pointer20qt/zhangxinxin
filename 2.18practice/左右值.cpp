#include<iostream>
#include<string>
using namespace std;

class tool{
public:
	int value=0;
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
int x(){
	int t = 1;//t����ֵ��1����ֵ
	return t;
}
tool func(){
	tool t;//t����ֵ
	return t;
}
int main1123(){
	int a = 2;//a����ֵ��2����ֵ
	x();//���ص�����ֵ����ʱ�ı���
	//func();//����t��ʱ�ı���
	int& la = a;//��ֵ���þ�����ͨ���ã��ڲ���һ�����ð�һ����ֵ
	int&& ra = 2;//��ֵ����,��һ����ֵ��������������ӳ��������õ�ʱ��һ��������ֵ���ò���������ֵ
	{
		tool&& t = func();
		cout << "-------" << endl;
	}
	cout << "����" << endl;
	const int d = 1;//������ֵ
	const int& ld = d;
	return 0;
}