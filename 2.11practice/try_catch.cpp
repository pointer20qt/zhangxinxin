/*今天的作业：1.练习使用 try catch，抛出自定义类型异常，尝试捕获out_of_range。*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> v = { 2, 3, 6, 8, 3, 5, 1 };
	try {
		cout << "star_fir" << endl;
		v.at(10) = 100;  //拋出 out_of_range 异常
	}
	catch (out_of_range & e) {
		cout << "超出范围" << endl;
	}
	double m, n;
	m = 0, n = 1;
	try {
		cout << "star_sec" << endl;
		if (n == 0)
			throw  1;  //抛出整型异常
		else if (m == 0)
			throw  0.1;  //拋出 double 型异常
		else
			cout << m / n << endl;
		cout << "无异常" << endl;
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