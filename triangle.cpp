#include<iostream>
using namespace std;
#include<stack>

void printTriangle()
{
	size_t n;
	unsigned result = 0;
	cout << "请输入要生成多少行杨辉三角:" << endl;
	cin >> n;
	if (n <= 0)
	{
		cout << "输入错误" << endl;
		return;
	}
	for (int i = 0; i < n - 1; i++)
		cout << "  ";
	cout << "1" << endl;					//输入的数是大于0的数,所以一定会输出第一行
	stack<unsigned> triangle;
	//先将0和1入栈
	stack<unsigned> _triangle;
	triangle.push(1);
	triangle.push(0);						//先将 1 和 0 入栈
	for (int i = 1; i < n; i++)
	{
		while (!triangle.empty())
		{
			result = triangle.top();		//获取栈顶元素
			triangle.pop();
			if (!triangle.empty())			//获取栈顶元素之前先判断一下栈内是否还有元素
			{
				result += triangle.top();
			}
			_triangle.push(result);			//入栈
		}
		_triangle.push(0);
		triangle = _triangle;		//赋值操作
		
        
        
        //格式化输出，先打印前面的空格，在打印后面的数字，每个数字字宽为3，附带一个空格
        
        for (int j = 0; j < n - 1 - i; j++)
		{
			cout << "  ";
		}
		_triangle.pop();
		while (!_triangle.empty())
		{
			printf("%-3d ", _triangle.top());
			_triangle.pop();
		}
		cout << endl;
	}
}

int main()
{
	printTriangle();
	system("pause");
	return 0;
}
