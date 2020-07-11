#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int next;
	int data;
}Node;
typedef struct
{
	Node link[1000];
	int length;
	const static int SIZE = 1000;
}StaticLink;
void Free_SSL(StaticLink& L, int pos);
int Malloc_SSL(StaticLink& link);
void InitList(StaticLink& L)
{
	for (int i = 0; i < L.SIZE - 1; i++)
	{
		L.link[i].next = i + 1;
	}
	L.link[L.SIZE - 1].next = 0;
	L.length = 0;
	return;
}
void InsertHead(StaticLink& L, int data);
bool Insert(StaticLink& link, int data, int pos)
{
	if (pos <1 || pos > link.length + 1)
	{
		printf("插入失败！\n");
		return false;
	}
	int k, j, l;
	k = link.SIZE - 1;
	j = Malloc_SSL(link);			 //获取空闲的元素位置,并且更新空闲位置
	for (l = 1; l<= pos - 1; l++)      //指针的偏移，next不断地向下偏移，一直到pos的前一个位置停下
	{
		k = link.link[k].next;
	}
	link.link[j].data = data;
	// j 代表的是 空闲的位置  k代表的是要插入的位置
	link.link[j].next = link.link[k].next;    //将空闲位置的指针指向前一个节点指向的下一个节点
	link.link[k].next = j;					 //将要插入的节点的前驱节点的指针指向插入的位置
	link.length++;
	return true;
}






int Malloc_SSL(StaticLink& link)
{
	int i = link.link[0].next;    //0(nullptr)代表着结束，第一个元素的next始终指向第一个空闲的那个位置
	if (link.link[0].next)
	{
		link.link[0].next = link.link[i].next;    //将头结点位置更新
	}
	return i;
}

bool DleNode(StaticLink& L, int pos)
{
	if (pos < 1 || pos > L.length)
	{
		return false;
	}
	int k, j, l;
	k = L.SIZE - 1;
	for (l = 1; l<=pos - 1; l++)
	{
		//游标指针的偏移
		k = L.link[k].next;
	}
	// k------->要删除节点的前驱节点
	// j------->要删除的节点的位置
	j = L.link[k].next;
	L.link[k].next = L.link[j].next;    //将k的后继指针，指向要删除的节点的下一个节点
	Free_SSL(L, j);						//更新头结点指针域的指向
	L.length--;
	return true;
}

void Free_SSL(StaticLink& L, int pos)
{
	L.link[pos].next = L.link[0].next;    //将要删除的指针指向头结点的指针指向的节点
	L.link[0].next = pos;                //将头结点指针，指向删除的节点的位置
}

void Print(StaticLink& L)
{
	printf("data\tindex\tnext\n");
	for (int i = 1; i <= L.length; i++)
		printf("%d\t%d\t%d\n", L.link[i].data,i,L.link[i].next);
	puts("");
}

int main()
{
	StaticLink link;
	InitList(link);
	for (int i = 1; i <= 10; i++)		//插入第一个数之前，头指针指向空，插入第一个数之后，第一个数的后继指针指向空（0），插入第三个数之后，第三个数的next指向空（0）
	{
		Insert(link, i * 3, i);
	}
	Print(link);

	if (DleNode(link, 1))
	{
		printf("%d\n", link.link[0].next);
		Print(link);
	}
	else
		printf("删除失败");

	system("pause");
	return 0;
}