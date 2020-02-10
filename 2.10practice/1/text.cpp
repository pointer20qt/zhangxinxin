#include "text.h"
#include<iostream>
using namespace std;

text::text()
{
	cout << "创建text" << endl;
}

text::~text()
{
	cout << "析构text" << endl;
}
void text::run()
{
	cout << "创建run" << endl;
}
