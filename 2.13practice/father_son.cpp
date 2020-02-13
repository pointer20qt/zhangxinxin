/*1：子类对象父类指针实现多态效果，实现虚析构。实现 隐藏。*/
#include<iostream>
#include<string>
using namespace std;
class school{
protected:
	string schoolName;//学校
public:
	school(std::string schoolName){
		cout << "构造school" << endl;
		this->schoolName = schoolName;
	}
	//school(){}//子类没有构造的时候，只有父类存在默认构造
	virtual~school(){
		cout << "析构school" << endl;
	}
	school(const school& p){
		cout << "拷贝school" << endl;
	}
	virtual void schoolopen()//使用虚函数 
	{
		cout << this->schoolName << "开学" << endl;
	}
};
//继承会将所有成员，函数
class university :public school{
	int typ;
public:
	university() :school("uu_school"){
		cout << "university构造" << endl;
	}
	~university(){
		cout << "析构university" << endl;
	}
	void schoolopen()                       /**********子和父函数一致时函数隐藏***********/
	{
		cout << "university开学" << endl;
	}
};
class small :public school{
public:
	small() :school("ss_school"){//初始化参数列表
		cout << "small构造" << endl;
	}
	void schoolopen()                       /**********父含有virtual函数重写***********/
	{
		cout << "small开学" << endl;
	}
};
//多态的调用方法
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
	//先看子类，看到子类有父类初始化，优先调用初始化父类，再构造子类
	small sm;
	sm.schoolopen();
	/*父类指针指向子类对象可调用子类方法
	university u2;
	school*s1 = &u2;
	school&s2 = u2;
	printsch(s1);
	*/
	school*s1 = new university;//父类指针定义子类对象	父类有虚函数是一定要有虚析构,否则会有内存泄漏
	printsch(s1);
	cout << "main结束" << endl;
	return 0;
}