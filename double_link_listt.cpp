//单链表的优点：实现了动态申请内存，而且删除和插入的操作效率很高，但是我感觉效率
//删除的效率也就是一般般，因为在删除之前要先定位到这个节点，时间复杂度为O(n)
//也就是在插入的时候效率高点，查找删除效率都是O(n)，和顺序表相比就是在插入的时候
//效率更高一点

//在单链表中如果要查看最后一个节点， 那么时间复杂度为O(n)，而且，单链表中的游标指针就像是、
//象棋里的卒合兵，只能前进不能后退

//双链表解决了这个两个问题


#include <iostream>
using namespace std;

class Node
{
public:
    //返回前驱指针
    Node* GetNext()const
    {
        return this->pnext;
    }    
    Node* GetPrv()const
    {
        return this->pprv;
    }
    int GetData()
    {
        return this->data;
    }
    void SetPnext(Node* pnext)
    {
        this->pnext = pnext;
    }
    void SetPprv(Node* pprv)
    {
        this->pprv = pprv;
    }
    void SetData(int data)
    {
        this->data = data;
    }
public:
    Node():pprv(nullptr),pnext(nullpttr),data(0)
    {}
    Node(int data,Node* pprv,Ndoe* pnext):data(data),pprv(pprv),pnext(pnext)
    {

    }
    ~Node()
    {
     
          
    }
private:
    Node* pnext;    //前驱指针
    Node* pprv;     //后继指针
    int data;       //数据
};

class DoubleLinkList
{
public:
    void Cout()
    {
        cout<<"正序输出"<<endl;
        for(Node* temp = this->head->GetNext();temp!=tail;temp = temp->GetNext())
        {
            cout<<temp->GetData()<<"  ";
        }
        cout<<endl;
        cout<<"逆序输出"<<endl;
        for(Node* temp = this->tail->GetPrv();temp != this->head;temp = temp->GetPrv())
        {
            cout<<temp->GetData()<<"  ";
        }
        cour<<endl;
    }
    void Insert(int data,int pos)
    {
       
    }
    void Push_Back(int data)
    {
        Node* NewNode = new Node(data,this->tail->GetPrv(),this->tail);
        this->tail->GetPrv()->SetPnext(NewNode);
        this->tail->SetPprv(NewNode);
        this->count++;
    }
    void Front(int data)
    {
        Node* NewNode = new Node(data,this->head,this->head->GetNext());
        _Connect(this->head,NewNode);
        _Connect(NewNode,this->head->GetNext());
        this->cout++;
    
    }
public:
    DoubleLinkList()
    {
        head = new Node;
        tail = new Node;
        head->SetPprv(nullptr);
        head->SetPnext(tail);
        tail->SetPnext(nullptr);
        tail->SetPprv(head);
        count = 0;
    }
    ~DoubleLinkList()
    {
     _DelNode(head);
    }
private:
    void _DelNode(Node* head)
    {
        if(head!=tail)
        {       
            Node* cur = head->GetNext();    
            while(cur!=nullptr)
            {
                Node* temp = cur;
                cur = cur->GetNext();
                delete temp;
            }
            delete head;
            head = nullptr;
            tail = nullptr;
        }
    }
    static void _Connect(Node* pprv,Node* pnext)
    {
        pprv->SetPnext(pnext);
        pnext->SetPprv(pprv);
    }
private:
    Node* head;
    Node* tail;
    int count;
}

int main()
{
    DoubleLinkList L;
    for(int i = 0; i<10 ;i++)
    {
        L.Push_Back(i);
    }
    L.Cout();
    cin.get();
    return 0;
}