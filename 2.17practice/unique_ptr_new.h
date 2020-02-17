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

//命名空间为了解决函数名和库函数名一样的问题
namespace z{
	template<class T>
	class x_unique_ptr{
		T* obj = nullptr;
	public:
		x_unique_ptr(T* ptr) :obj(ptr){
			//obj = ptr;
		}
		x_unique_ptr(const T&) = delete;//在x_unique_ptr中不使用拷贝构造
		x_unique_ptr& operator = (x_unique_ptr<T>&& ptr) = delete;
		x_unique_ptr() = default;//无参构造方法
		~x_unique_ptr(){
			delete obj;
		}
		//移动构造
		x_unique_ptr(x_auto_ptr<T>&& ptr) :obj(ptr.release()){

		}
		x_unique_ptr& operator = (x_auto_ptr<T>&& ptr){
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
}
