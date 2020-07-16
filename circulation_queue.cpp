
#include<stdio.h>
#include<stdlib.h>
const int MAXSIZE = 10;
typedef int QEmletype;
typedef struct {
	QEmletype data[MAXSIZE];
	int font;
	int rear;
}Queue;
//初始化队列
void initQueue(Queue* queue)
{
	queue->font = 0;
	queue->rear = 0;
}
//返回当前队列的元素个数
int getSize(Queue* queue)
{   //MAXSIZE的调和作用
	return (queue->rear - queue->font + MAXSIZE) % MAXSIZE;
}
//入队
bool enQueue(QEmletype data, Queue* queue)
{
	if ((queue->rear + 1) % MAXSIZE == queue->font)
	{
		printf("队列已满\n");
		return false;
	}
	else
	{
		queue->data[queue->rear] = data;
		queue->rear = (queue->rear + 1) % MAXSIZE;
		return true;
	}

}
bool deQueue(Queue* queue)
{
	if (queue->rear == queue->font)
	{
		printf("队列已空，没有出队元素");
		return false;
	}

	queue->font = (queue->font + 1) % MAXSIZE;
	return true;
}
bool isEmpty(Queue* queue)
{
	if (queue->font >= queue->rear)
		return true;
	else
		return false;
}
QEmletype getFont(Queue* queue)
{
	if (isEmpty(queue))
	{
		printf("队列已空，没有元素，返回数据出错\n");
		return queue->data[queue->font];

	}
	else
	{
		return queue->data[queue->font];
	}

}

void test()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	initQueue(queue);
	for (int i = 0; i<MAXSIZE; i++)
	{
		enQueue(i, queue);
	}
	printf("当前元素个数：%-3d\n", getSize(queue));
	printf("\n");
	while (!isEmpty(queue))
	{
		printf("%-3d出队\n", getFont(queue));
		deQueue(queue);
	}
	printf("\n");
	free(queue);
}

int main()
{
	test();
	system("pause");
	return 0;
}