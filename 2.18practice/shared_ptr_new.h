#pragma once
namespace z{
	//资源计数类
	template<class T>
	class Ref{
		int r_count = 0;//shared的计数
		int w_count = 0;//weak的计数
		T* object = nullptr;
	public:
		Ref(T* target):object(target){
			++r_count;
		}
		inline void increase(){//实用接口避免出现调用函数出现错误的麻烦
			r_count++;
		}
		inline void increase_w(){
			w_count++;
		}
		inline void reduce(){
			r_count--;//直至计数对象为0时进行析构
			if (r_count == 0){
				delete object;
				object = nullptr;
				if (w_count == 0){//w_count也为0时全部都析构
					delete this;
				}
			}
		}
		inline void reduce_w(){
			w_count--;//加上r_count==0条件是为了更好的判断引用计数对象是否为0
			if (w_count == 0&&r_count==0){
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
	template<class T> class x_weak_ptr;
	template<class T> class x_shared_ptr{
		friend class x_weak_ptr<T>;
		Ref<T>* ref = nullptr;
	public:
		x_shared_ptr() = default;
		x_shared_ptr(Ref<T> *newRef){
			//ref = new Ref<T>(newp);
			ref = newRef;
			if (ref){
				ref->increase();
			}
		}
		x_shared_ptr(T* newP){
			ref = new Ref<T>(newP);
		}
		~x_shared_ptr(){
			if (ref){
				ref->reduce();
			}
		}
		x_shared_ptr(const x_shared_ptr<T>& other){
			ref = other.ref;
			if (ref){
				ref->increase();
			}
		}
		x_shared_ptr(x_shared_ptr<T>&& other){
			swap(ref, other.ref);//直接就可以将两个的内容进行交换
		}
		x_shared_ptr& operator = (const x_shared_ptr<T>& other){
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
		void swap(x_shared_ptr<T>& other){
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
		bool unique(){
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

	/*可以指定一个引用计数对象，在需要时获取shared_ptr;
	无参构造，传递一个shared_ptr构造。拷贝构造，拷贝赋值，移动构造，移动赋值
	user_count()获得指定对象的引用计数（shared_ptr的计数）
	lock()获得一个shared_ptr
	expired()判断对象是否被删除
	sawp(),reset()释放
	*/
	template<class T>
	class x_weak_ptr{
		Ref<T>* ref = nullptr;
	public:
		x_weak_ptr() = default;
		x_weak_ptr(x_shared_ptr<T>& other):ref(other.ref){
			cout << "传递一个shared_ptr构造" << endl;
			if (ref){
				ref->increase_w();
			}
		}
		x_weak_ptr(const x_weak_ptr<T>& other) :ref(other.ref){//拷贝构造
			if (ref){
				ref->increase_w();
			}
		}
		x_weak_ptr(x_weak_ptr<T>&& other){//移动构造
			swap(ref,other.ref)
		}
		x_weak_ptr<T>& operator =(const x_weak_ptr<T>& other){
			cout << "调用了weak的拷贝赋值运算符" << endl;
			if (ref){
				ref->reduce_w();
			}
			ref = other.ref;
			if (ref){
				ref->increase_w();
			}
			return *this;
		}
		x_weak_ptr<T>& operator = (x_weak_ptr<T>&& other){
			cout << "调用了weak的移动赋值运算符" << endl;
			if (ref){
				ref->reduce_w();
			}
			ref = other.ref;
			other.ref = nullptr;
			return *this;
		}
		int use_count(){
			if (ref){
				return ref->get_count();
			}
			else{
				return 0;
			}
		}
		bool expired(){
			if (ref){
				return ref->get_count() > 0;
			}
			else{
				return false;
			}
		}
		x_weak_ptr<T> lock(){
			x_shared_ptr<T> tem(ref);
			return tem;
		}
		void sawp(x_weak_ptr<T>& other){
			swap(ref, other.ref);
		}
		void reset(){
			ref->reduce_w();
			ref = nullptr;
		}
	};
}