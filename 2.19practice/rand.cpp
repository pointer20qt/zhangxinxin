#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;
//����0��100���������������жϳɹ�,�ɹ�����true
bool probability(int n){
	int p = rand() % 100;
	if (p <n){
		return true;
	}
	else{
		return false;
	}
}
//����0��1�ĸ��������жϸ���
//��ôͨ��rand����[0,20)����rand()%20
//��ôͨ��rand����[0,a)����rand()%a
//��ôͨ��rand����[5,20)����rand()%(20-5)+5
//��ôͨ��rand����[a,b)����rand()%(b-a)+a
//��ô����һ��0~1�����С��double
//��ô����a~b�����С��
//����0��1��double���������жϳɹ����ɹ�����ture��
bool probability(double n){
	double p = ((double)rand()) / RAND_MAX;
	if (p <n){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	//��ʼ���������
	//��������ȡ�࣬���� ���Ӻ���
	//time(0)��1970�����ڵ�����
	srand(time(0));
	//����������0~RAND_MAX
	int t = 0, f = 0;
	for (int i = 0; i < 100; i++)
	{
		if (probability(0.05)){
			cout << "����" << endl;
			t++;
		}
		else
		{
			f++;
		}
	}
	cout << t << "��" << f << endl;
}