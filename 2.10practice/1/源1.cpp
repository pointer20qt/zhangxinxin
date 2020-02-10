/*
任务1： 创建一个静态链接库，并在其他项目中调用其中方法
*/
#include <iostream>
//预先生成一个库，.lib文件（起到cpp文件 的作用）保密的作用
#include"text.h"
using namespace std;
#pragma  comment(lib,"LibText.lib")
int main()
{
	cout << "开始" << endl;
	text t;
	t.run();
}