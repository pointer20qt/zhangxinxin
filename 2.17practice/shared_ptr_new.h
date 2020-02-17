#pragma once
namespace z{
	//资源计数类
	template<class T>
	class Ref{
		int r_count = 0;
		T* object = nullptr;
	public:
		Ref(T* target):object(target){
			++r_count;
		}
		inline void increase(){
			r_count++;
		}
		inline void reduce(){
			r_count--;//直至计数对象为0时进行析构
			if (r_count == 0){
				delete object;
				delete this;
			}
		}
		//获得对对象
		T* get(){
			return object;
		}
		int get_count(){
			return r_count;
		}
	};
	/*无参构造，传递指针构造，拷贝，移动，析构，拷贝赋值，移动复制，
	reset(T*)替换对象reset()销毁对象
	operator*(),operator->()
	get()获得裸指针
	use_count()获得引用计数
	unque()判断当前是否唯一use_count=1
	operator bool()*/
	template<class T>
	class x_shared_ptr{
		Ref<T>* ref = nullptr;
	public:
		x_shared_ptr() = default;
		x_shared_ptr(T* newp){
			ref = new Ref<T>(newp);
		}
		~x_shared_ptr(){
			if (ref){
				ref->reduce();
			}
		}
		x_shared_ptr(const x_shared_ptr& other){
			ref = other.ref;
			if (ref){
				ref->increase();
			}
		}
		x_shared_ptr(x_shared_ptr&& other){
			swap(ref, other.ref);//直接就可以将两个的内容进行交换
		}
		x_shared_ptr& operator = (const x_unique_ptr<T>& other){
			//之前的存不存在，不存在附成新的
			if (ref){
				ref->reduce();
			}
			ref = other.ref;
			if (ref)
			{
				ref->reduce();
			}
			return *this;
		}
		x_shared_ptr& operator = (x_shared_ptr<T>&& other){
			if (ref)
			{
				ref->reduce();
			}
			ref = other.ref;
			other.ref = nullptr;
			return *this;
		}
		void swap(x_shared_ptr& other){
			swap(ref, other.ref);
		}
		void reset(T* target = nullptr){
			if (ref){
				ref->reduce();
			}
			if (target != nullptr){
				ref = new Ref<T>(target);
			}
			else{
				ref = nullptr;
			}
		}
		T& operator*(){
			if (ref)
			{
				return *ref->get();
			}
			else{
				return *(T*)nullptr;
			}
		}
		T* operator->(){
			if (ref)
			{
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		T* get(){
			if (ref)
			{
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		int use_count(){
			if (ref)
			{
				return ref->get_count();
			}
			else{
				return 0;
			}
		}
		bool unque(){
			if (ref){
				return ref->get_count() == 1;
			}
			else
			{
				return false;
			}
		}
		//判断当前指针是否和对象有关联
		operator bool(){
			return ref != nullptr;
		}
	};
}