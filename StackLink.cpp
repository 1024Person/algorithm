#include<iostream>
using namespace std;
template<class T>
class NodeLink
{

public:
	NodeLink* getPnext()
	{
		return this->pnext;
	}
	T& getData()
	{
		return this->data;
	}
	void setData(T& data)
	{
		this->data = data;
	}
	void setPnext(NodeLink* pnext)
	{
		this->pnext = pnext;
	}

public:
	NodeLink():pnext(nullptr)
	{}
	NodeLink(NodeLink* pnext, T& data) :pnext(pnext), data(data)
	{

	}
private:
	NodeLink* pnext;
	T data;
};
template<class T>
class StackLink
{

public:

	void push(T& data)
	{
		NodeLink<T>* new_node = new NodeLink<T>;
		if (new_node == nullptr)
		{
			cout << "内存不足" << endl;
			exit(0);
		}
		new_node->setData(data);
		new_node->setPnext(this->top);
		this->top = new_node;
		this->count++;
	}
	void pop()
	{
		if (this->top == nullptr)
		{
			cout << "栈已空" << endl;
			return;
		}

		NodeLink<T>* temp = this->top;
		this->top = this->top->getPnext();
		delete temp;
		count--;

	}
	T& getTopData()
	{
		return top->getData();
	}
	int getCount()
	{
		return this->count;
	}
public:
	StackLink():top(nullptr), count(0)
	{

	}

	~StackLink()
	{

		while (this->top != nullptr)
		{
			NodeLink<T>* temp = this->top;
			this->top = this->top->getPnext();
			delete temp;
		}

	}
private:
	NodeLink<T>* top;
	int count;			//入栈的个数

};


int main()
{
	StackLink<int> stack_link;
	for (int i = 0; i < 10; i++)
	{
		stack_link.push(i);
	}
	cout << "栈内元素:" << endl;
	while (stack_link.getCount())
	{
		cout << "top---->" << stack_link.getTopData() << endl;
		stack_link.pop();
	}
	cout << endl;
	system("pause");
	return 0;

}