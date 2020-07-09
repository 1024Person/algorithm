#include<cstdio>
typedef struct 
{
    int data;
    Node* next;
}Node;
typedef struct
{
    Node* head;
    int length;
    Node* tail;
}Link;

//initalize linklist,and let head -->malloc a Node,then let head->next = nullptr,and tail---->head
//this linklist own a headNode ,and use a Node pointer to record tail
void InitList(Link& L)
{
    L.head =(Node*) malloc(sizeof(Node));
    L.head->next=nullptr;
    L.tial = L.head;
}

bool InsertNode(Link& L,int pos,int data)
{
    ////  empty  /////
}
bool DelNode(Link& L,int pos)
{
    ///  empty  /////
}

int main()
{
    Link  L1,L2;
    InitList(L1);
    InitList(L2);
    //circulate linklist 
    L1.tail->next = L1.head;
    L2.tail->next = L2.head;
    //merge tow linklist
    L1.tail->next = L2.head;
    L2.tail->next = L1.head;
}