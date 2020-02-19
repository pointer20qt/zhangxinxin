#pragma once
namespace z{
	//��Դ������
	template<class T>
	class Ref{
		int r_count = 0;//shared�ļ���
		int w_count = 0;//weak�ļ���
		T* object = nullptr;
	public:
		Ref(T* target):object(target){
			++r_count;
		}
		inline void increase(){//ʵ�ýӿڱ�����ֵ��ú������ִ�����鷳
			r_count++;
		}
		inline void increase_w(){
			w_count++;
		}
		inline void reduce(){
			r_count--;//ֱ����������Ϊ0ʱ��������
			if (r_count == 0){
				delete object;
				object = nullptr;
				if (w_count == 0){//w_countҲΪ0ʱȫ��������
					delete this;
				}
			}
		}
		inline void reduce_w(){
			w_count--;//����r_count==0������Ϊ�˸��õ��ж����ü��������Ƿ�Ϊ0
			if (w_count == 0&&r_count==0){
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
			swap(ref, other.ref);//ֱ�ӾͿ��Խ����������ݽ��н���
		}
		x_shared_ptr& operator = (const x_shared_ptr<T>& other){
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
		//�жϵ�ǰָ���Ƿ�Ͷ����й���
		operator bool(){
			return ref != nullptr;
		}
	};

	/*����ָ��һ�����ü�����������Ҫʱ��ȡshared_ptr;
	�޲ι��죬����һ��shared_ptr���졣�������죬������ֵ���ƶ����죬�ƶ���ֵ
	user_count()���ָ����������ü�����shared_ptr�ļ�����
	lock()���һ��shared_ptr
	expired()�ж϶����Ƿ�ɾ��
	sawp(),reset()�ͷ�
	*/
	template<class T>
	class x_weak_ptr{
		Ref<T>* ref = nullptr;
	public:
		x_weak_ptr() = default;
		x_weak_ptr(x_shared_ptr<T>& other):ref(other.ref){
			cout << "����һ��shared_ptr����" << endl;
			if (ref){
				ref->increase_w();
			}
		}
		x_weak_ptr(const x_weak_ptr<T>& other) :ref(other.ref){//��������
			if (ref){
				ref->increase_w();
			}
		}
		x_weak_ptr(x_weak_ptr<T>&& other){//�ƶ�����
			swap(ref,other.ref)
		}
		x_weak_ptr<T>& operator =(const x_weak_ptr<T>& other){
			cout << "������weak�Ŀ�����ֵ�����" << endl;
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
			cout << "������weak���ƶ���ֵ�����" << endl;
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