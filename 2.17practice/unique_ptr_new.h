#pragma once
//ģ�廯�����Խ����������Ͳ���
//���췽������ֵһ��ָ��
//�����������ͷ�ָ��
//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ��
//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ�����Ȩ��
//reset  �ͷ�֮ǰ�ģ���ȡ�µ�ָ��
//release  �ͷſ���Ȩ������ָ��
//operator*()  ģ��ָ����ʷ���
//operator->()  ģ��ָ���ͷ��ʽ���ʷ���
//get()  ���ָ��ָ���ָ��

//�����ռ�Ϊ�˽���������Ϳ⺯����һ��������
namespace z{
	template<class T>
	class x_unique_ptr{
		T* obj = nullptr;
	public:
		x_unique_ptr(T* ptr) :obj(ptr){
			//obj = ptr;
		}
		x_unique_ptr(const T&) = delete;//��x_unique_ptr�в�ʹ�ÿ�������
		x_unique_ptr& operator = (x_unique_ptr<T>&& ptr) = delete;
		x_unique_ptr() = default;//�޲ι��췽��
		~x_unique_ptr(){
			delete obj;
		}
		//�ƶ�����
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
