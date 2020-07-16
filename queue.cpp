#include<iostream>
using namespace std;
template<class T>
class Queue
{
public:

	//清空
	void clearQueue(){
		size = 0;
	}

	//返回队首元素
	T& getHead()
	{
		if (!isEmpty())
		{
			return data[head];
		}
		else
		{
			cout << "队列已空返回数据时出错" << endl;
			return data[head];
		}

	}

	//入队
	void enQueue(T& node)
	{

		if (size>length)
		{
			//一点五倍的速度扩容
			length *= 1.5;
			T* temp = new T[length];
			for (int i = 0; i<size; i++){
				temp[i] = data[i];
			}
			temp[size] = node;
			delete[] data;
			data = temp;
		}
		else
		{
			data[size] = node;       //end是队尾元素的下标 
		}
		end++;
		size++;
	}
	//出队
	void deQueue()
	{
		if (!isEmpty())
		{
			//这里的出队没有用到循环队列，，只是选择了效率很低下的向前盖
			for (int i = 0; i< size - 1; i++)
			{
				data[i] = data[i + 1];
			}
			end--;
			size--;
		}
	}
	//输出队列元素
	void out_()
	{
		for (int i = 0; i<size; i++)
		{
			cout << data[i] << "\t";
		}
		cout << endl;
	}
	//判断是否为空
	bool isEmpty()
	{
		if (size == 0)
			return true;
		else
		{
			return false;
		}
	}


public:
	Queue()
	{

		end = -1;            //这里让end的初始值为-1是为了让end当作下标
		length = 10;
		data = new T[length];
		size = 0;
	}
	~Queue()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
protected:
	const int head = 0;
	int end;
	T* data;
	int length;
	int size;

};


void test()
{
	Queue<int> queue;
	for (int i = 0; i<10; i++)
	{
		queue.enQueue(i);
	}

	queue.out_();
	cout << queue.getHead() << endl;
	queue.deQueue();
	queue.deQueue();
	queue.out_();
	queue.clearQueue();
	queue.out_();

}

int main()
{
	test();
	system("pause");
	return 0;
}