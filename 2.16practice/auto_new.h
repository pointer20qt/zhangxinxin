#pragma once
//模板化，可以接受任意类型参数
//构造方法，赋值一个指针
//析构方法，释放指针
//不标准的复制构造（转移内部指针控制权）
//不标准的复制赋值（转移内部指针控制权）
//reset  释放之前的，获取新的指针
//release  释放控制权，返回指针
//operator*()  模拟指针访问方法
//operator->()  模拟指针箭头方式访问方法
//get()  获得指针指向的指针
template<class T>
class x_auto_ptr{
	T* obj = nullptr;
public:
	x_auto_ptr(T* ptr) :obj(ptr){
		//obj = ptr;
	}
	x_auto_ptr() = default;//无参构造方法
	~x_auto_ptr(){
		delete obj;
	}
	//模板类附上模板类型才可以
	x_auto_ptr(x_auto_ptr<T>& ptr) :obj(ptr.release()){
		//obj = ptr.obj;
		//ptr.obj = nullptr;
	}
	x_auto_ptr& operator = (x_auto_ptr<T>& ptr){
		/*delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;*/
		obj = ptr.release();
		return *this;
	}
	void reset(T*newptr = nullptr){
		delete obj;
		obj = newptr;
	}
	T* release(){
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T& operator*(){
		return *obj;
	}
	T* operator->(){
		return obj;
	}
	T* get(){
		return obj;
	}
};