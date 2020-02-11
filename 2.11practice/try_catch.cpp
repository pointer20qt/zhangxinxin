/*�������ҵ��1.��ϰʹ�� try catch���׳��Զ��������쳣�����Բ���out_of_range��*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> v = { 2, 3, 6, 8, 3, 5, 1 };
	try {
		cout << "star_fir" << endl;
		v.at(10) = 100;  //���� out_of_range �쳣
	}
	catch (out_of_range & e) {
		cout << "������Χ" << endl;
	}
	double m, n;
	m = 0, n = 1;
	try {
		cout << "star_sec" << endl;
		if (n == 0)
			throw  1;  //�׳������쳣
		else if (m == 0)
			throw  0.1;  //���� double ���쳣
		else
			cout << m / n << endl;
		cout << "���쳣" << endl;
	}
	catch (double d) {
		cout << "catch (double)" << d << endl;
	}
	catch (...) {
		cout << "catch (...)" << endl;
	}
	cout << "finished" << endl;

	return 0;
}