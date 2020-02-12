/*2.创建一个类，重写移动构造，并使用*/
#include<iostream>
using namespace std;
class principal{
	string name;
public:
	principal(string sname){
		this->name = sname;
	}
	~principal(){
		cout << "析构老师" << endl;
	}
};
class school{
public:
	std::string schoolName;//学校
	principal* master;

	~school(){
		cout << "析构大学" << endl;
		delete master;
	}
	school(std::string schoolName){
		cout << "普通构造函数" << endl;
		this->schoolName = schoolName;
		master = new principal("老师");
	}
	//拷贝出一个一样的
	school(const school& p){
		cout << "拷贝构造函数" << endl;
		master = new principal(*(p.master));
	}
	school(school&& other) :schoolName(other.schoolName){
		cout << "移动构造函数" << endl;
		master = other.master;
		other.master = NULL;
	}
};
school getschool(){
	school s2("大学");
	return s2;
}
int main(){
	school s1(getschool());       /****调用移动构造函数****/
	school s3("大学");
	school s4(s3);                    /****调用拷贝构造函数****/
	cout << "结束" << endl;   /****有三个老师被析构，s1，s3，s4，****/
	return 0;
}
