#include<cassert>

const int SIZE=100;

template<typename T>
class queue{
private:
	bool empty;
	int front,back;
	T q[SIZE];

public:
	queue(){
		front=back=0;
		empty=true;
	}

	bool isEmpty()const{return empty;};
	bool isFull()const{return (!empty)&&(front==back);};

	void enqueue(const T& item){
		assert(!isFull());
		q[back]=item;
		back=(back+1)%SIZE;
		empty=false;
	}

	T dequeue(){
		assert(!isEmpty());
		T result=q[front];
		front=(front+1)%SIZE;
		if(front==back)
			empty=true;
		return result;		
	}

};

