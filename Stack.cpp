//顺序栈
#include <iostream>
using namespace std;
template <class T>
class Stack
{

public:
	bool push(T data)
	{
		//top是下标，length是长度，最大下标等于长度减一
		if (top + 1 >= length)
		{
			cout << "栈已满，请先出栈" << endl;
			return false;
		}
		top++;
		this->data[top] = data;
		count++;
		return true;
	}
	bool pop()
	{
		if (count == 0)
		{
			cout << "栈已空" << endl;
			return false;
		}
		top--;
		return true;
	}
	int getStackCount()
	{
		return this->count;
	}
	T &getTop()
	{
		if (top == -1)
		{
			//用的是模板，所以只能返回第0个元素，自己定义的也不知道存什么类型的数据
			cout << "空栈没有数据,返回数据时出错" << endl;
			return data[0];
		}
		return data[top];
	}
	void clearStack()
	{
		this->top = -1;
	}
	int getStackNum() //返回当前栈的个数
	{
		return num;
	}
	bool empty()
	{
		return this->top == -1;
	}
public:
	Stack(int length)
	{
		data = new T[length];
		this->length = length;
		count = 0;
		top = -1;
		num++;
	}
	~Stack()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
	void operator=(Stack &Stack)
	{
		this->count = Stack.count;
		this->length = Stack.length;
		this->top = Stack.top;
		if (this->data != nullptr)
		{
			delete[] data;
		}
		this->data = new T[length];
		if (this->data == nullptr)
		{
			cout << "内存申请失败" << endl;
			exit(0);
		}
		for (int i = 0; i < length; i++)
		{
			data[i] = Stack.data[i];
		}
	}

private:
	T *data;
	int top;
	int length;
	int count;
	static int num;
};
template <class T>
int Stack<T>::num = 0;
//两栈共享空间
template <class T>
class StackDouble
{
public:
	T &getTop(int stack_num = 1) //传入要获取那个栈的栈顶元素，默认是第一个
	{
		if (stack_num == 1 && top_1 != -1)
		{
			return data[top_1];
		}
		else if (stack_num == 1 && top_1 == -1)
		{
			cout << "栈1为空栈，返回数据是出错" << endl;
			return data[0];
		}
		else if (stack_num == 2 && top_2 != length)
		{
			return data[top_2];
		}
		else if (stack_num == 2 && top_2 == length)
		{
			cout << "栈2为空栈，返回数据是出错" << endl;
			return data[length - 1];
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}
	bool push(T data, int stack_num = 1) //传入要将数据压入哪一个栈，默认为1
	{
		if (top_1 + 1 == top_2)
		{
			cout << stack_num << "号栈已满,入栈失败" << endl;
			return false;
		}
		if (stack_num == 1)
		{
			top_1++;
			this->data[top_1] = data;
			this->count_1++;
		}
		else if (stack_num == 2)
		{
			top_2--;
			this->data[top_2] = data;
			this->count_2++;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			return false;
		}
		return true;
	}
	bool pop(int stack_num = 1)
	{
		if (stack_num == 1 && top_1 == -1)
		{
			cout << "1号栈已空,弹栈失败" << endl;
			return false;
		}
		else if (stack_num == 2 && top_2 == length)
		{
			cout << "2号栈已空，弹栈失败" << endl;
			return false;
		}
		else if (stack_num == 1 && top_1 >= 0)
		{
			top_1--;
			this->count_1--;
			return true;
		}
		else if (stack_num == 2 && top_2 < length)
		{
			this->top_2++;
			this->count_2--;
			return true;
		}
		else
		{
			cout << "输入有误" << endl;
			return false;
		}
	}
	int getCount(int stack_num = 1)
	{
		if (stack_num == 1)
		{
			return count_1;
		}
		else if (stack_num == 2)
		{
			return count_2;
		}
		else //如果stack_num既不是也不是2
		{
			cout << "输入有误" << endl;
			return -1;
		}
	}
	bool empty(int stack_num = 1)
	{
		if (stack_num == 1)
			return this->top_1 == -1;
		else if (stack_num == 2)
		{
			return this->top_2 == length;
		}
	}
public:
	StackDouble(int length)
	{
		this->length = length;
		this->data = new T[length];
		this->top_1 = -1;
		this->top_2 = length;
		count_1 = count_2 = 0;
	}
	~StackDouble()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
	void operator=(StackDouble &stack_double)
	{
		this->count_1 = stack_double.count_1;
		this->count_2 = stack_double.count_2;
		this->top_1 = stack_double.top_1;
		this->top_2 = stack_double.top_2;
		this->length = stack_double.length;
		if (this->data != nullptr)
			delete this->data;
		this->data = new T[length];
		if (this->data == nullptr)
		{
			cout << "内存不足" << endl;
			exit(0);
		}
		for (int i = 0; i <= top_1; i++)
		{
			this->data[i] = stack_double.data[i];
		}
		for (int i = length * 2; i >= top_2; i--)
		{
			this->data[i] = stack_double.data[i];
		}
	}

private:
	T *data;
	int top_1;
	int top_2;
	int length;
	int count_1;
	int count_2;
};
int main()
{
	Stack<int> stack(10);
	for (int i = 0; i < 11; i++)
	{
		stack.push(i + 1);
	}
	cout << "出栈" << endl;
	while (!stack.empty())
	{
		cout << "top---->" << stack.getTop() << endl;
		stack.pop();
	}
	cout << "--------------------------------" << endl;
	StackDouble<int> stack_double(10);
	stack_double.push(10, 1);
	stack_double.push(20, 2);
	stack_double.push(30, 1);
	stack_double.push(40, 2);
	stack_double.push(50, 1);
	stack_double.push(60, 2);
	stack_double.push(70, 1);
	stack_double.push(80, 2);
	stack_double.push(90, 1);
	stack_double.push(100, 2);

	cout << "栈一:"<<endl;
	while (!stack_double.empty())
	{
		cout <<"top_1--->"<<stack_double.getTop() <<endl;
		stack_double.pop();
	}
	cout << endl;
	cout << "--------------------------------" << endl;
	cout << "栈二:" << endl;
	while (!stack_double.empty(2))
	{
		cout << "top_2--->" << stack_double.getTop(2) << endl;
		stack_double.pop(2);
	}
	cout << endl;
	system("pause");
	return 0;
}