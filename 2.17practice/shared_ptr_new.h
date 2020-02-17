#pragma once
namespace z{
	//��Դ������
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
			r_count--;//ֱ����������Ϊ0ʱ��������
			if (r_count == 0){
				delete object;
				delete this;
			}
		}
		//��öԶ���
		T* get(){
			return object;
		}
		int get_count(){
			return r_count;
		}
	};
	/*�޲ι��죬����ָ�빹�죬�������ƶ���������������ֵ���ƶ����ƣ�
	reset(T*)�滻����reset()���ٶ���
	operator*(),operator->()
	get()�����ָ��
	use_count()������ü���
	unque()�жϵ�ǰ�Ƿ�Ψһuse_count=1
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
			swap(ref, other.ref);//ֱ�ӾͿ��Խ����������ݽ��н���
		}
		x_shared_ptr& operator = (const x_unique_ptr<T>& other){
			//֮ǰ�Ĵ治���ڣ������ڸ����µ�
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
		//�жϵ�ǰָ���Ƿ�Ͷ����й���
		operator bool(){
			return ref != nullptr;
		}
	};
}