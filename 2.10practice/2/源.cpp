#include <iostream>
#include"��ͷ.h"
#include"B.h"
#include"C.h"
using namespace std;
#if 0 //��if���ֵΪ��Ϳ��Ե��ã�Ϊ�پͲ���ʳ��
int a;
#endif;
#if DEBUG
#error 123;   //error��#ifndefһ��ʹ�ã��ж�һЩδ������ĺ�
#endif;
int main()
{
	A a;
	a.run();
	/*C c;
	B b;*/
}
void A::run()
{
	cout << "123" << endl;
}
/*
����2����ϰʹ�� ifndef��ֹ�����ظ�����
*/