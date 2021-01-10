#ifndef LOCK_FREE_QUEUE
#define LOCK_FREE_QUEUE
#include<vector>
#include<atomic>
#include<thread>
#include<assert.h>
using namespace std;

//��֤TӦ����trival
//����ѭ��������н���������
template<typename T>
class LockFreeArrayQueue {
public:
	//push or pop ���ò���
	enum class Strategy {
		ABANDON, //����
		FORCE,  //����õ�
		YIELD,  //����õ����������yield
	};
public:
	//��֤��ʼ���ڵ��߳������
	LockFreeArrayQueue(int capacity) :_data(capacity), _capacity(capacity) {
		islockfree = capacity == 0 || _data.front().is_lock_free();
	}
	~LockFreeArrayQueue() {}

	bool is_lock_free() {
		return islockfree;
	}
	int size();
	bool isFull() { return _size.load() == _capacity; }
	bool isEmpty() { return _size.load() == 0; }

	bool push(T val, Strategy strategy = Strategy::FORCE);
	bool pop(T& val, Strategy strategy = Strategy::FORCE);

private:
	//const T Empty = 0;  //Ԫ��Ϊ0ʱ����ʾΪ��
	const int Exclude = -1;  //front or rearΪ-1ʱ����ʾ�����߳��Ѽ��������ڲ�������

	const int _capacity;  //�����������
	std::vector<atomic<T>>_data;
	std::atomic<int>_size = { 0 };  //��ǰsize
	std::atomic<int>_front = { 0 };  //ͷָ��
	std::atomic<int>_rear = { 0 };   //βָ��
	bool islockfree;
};

template<typename T>
bool LockFreeArrayQueue<T>::push(T val, Strategy strategy) {
	int rear = _rear.load();
	while (true) { //check with loop
		if (rear == Exclude || isFull()) {
			switch (strategy) {
			case Strategy::YIELD:
				std::this_thread::yield();
			case Strategy::FORCE:
				rear = _rear.load();
				continue;
			}
			return false;
		}
		//��rear��
		if (_rear.compare_exchange_weak(rear, Exclude)) { //Atomically compares the  *this with that of expected, and if those are bitwise-equal, replaces the former with desired (performs read-modify-write operation). Otherwise, loads the actual value stored in *this into expected (performs load operation).
			//������ʧ�ܽ�������
			if (isFull()) {
				int excepted = Exclude;
				bool flag = _rear.compare_exchange_weak(excepted, rear);
				assert(flag);
				continue;
			}
			break;
		}
	}
	_data[rear].store(val);
	++_size; //�����ڽ���ǰ��
	int excepted = Exclude;
	//�ͷ�rear��
	bool flag = _rear.compare_exchange_weak(excepted, (rear + 1) % _capacity);
	assert(flag);
	return true;
}

template<typename T>
bool LockFreeArrayQueue<T>::pop(T& val, Strategy strategy) {
	int front = _front.load();
	while (true) {
		if (front == Exclude || isEmpty()) {
			switch (strategy) {
			case Strategy::YIELD:
				std::this_thread::yield();
			case Strategy::FORCE:
				front = _front.load();
				continue;
			}
			return false;
		}
		//���� �鿴ͷָ���Ƿ�ı�
		if (_front.compare_exchange_weak(front, Exclude)) {
			//�գ�ʧ�ܽ�������
			if (isEmpty()) {
				int excepted = Exclude;
				bool flag = _front.compare_exchange_weak(excepted, front);
				assert(flag);
				continue;
			}
			break;
		}
	}
	val = _data[front].load();
	//_data[front].store(Empty);
	--_size; //�����ڽ���ǰ��
	int excepted = Exclude;
	bool flag = _front.compare_exchange_weak(excepted, (front + 1) % _capacity);
	assert(flag);
	return true;
}



template<typename T>
int LockFreeArrayQueue<T>::size() {
	return _size.load();
}


#endif // !LOCK_FREE_QUEUE
