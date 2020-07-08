#include<iostream>
using namespace std;
template<typename T>
class Node
{
 public:
    int GetNext(){
        return this->cur;
    }   

  private:
    int cur; 
    T data;
}
template<typename T>
class StaticLink{
    public:
    using Node<T> Node;
    using Node<T>* NodePtr;
    int GetSize(){
        return size;
    }
    int GetCount(){
        return this->length;
    }

    bool Insert(int pos, T data){
        if(pos<1 || pos > this->length+1 )
        {  
            cout<<"插入失败"<<endl;
            return false;
        }
        int freepos = this->FreePos();          //空闲位置
       
      
       int k = SIZE - 1;
        if(freepos)
        {
            this->link[freepos].data = data;
            for(int l = 1;l < pos -1 ; l++)       //找到第pos的位置的前一个位置
            {
                //注意这里的指针偏移，千万不要想成了下标的操作
                k = this->link[k];
            }
            this->link[ freepos ].cur = this->link[k].cur;
            this->link[ k ].cur = freepos;
            return true;
        }

        else
        {
            cout<<"链表已满，插入失败"<<endl;
            return false;
        }
    }
    //删除操作
    bool DeleNode(int pos)
    {
        if(pos<1 || pos > this->length+1 )
        {  
            cout<<"删除失败"<<endl;
            return false;
        )
        int k,l,j;
        k = SIZE - 1;
        for(l = 1 ;l < pos -1 ; l++)
        {
            k = this->link[k];
        }
        this->link[k].cur = this->link[pos].cur;        //将前一个位置的cur指向当前的下一个
        this->link[pos].cur = this->link[0].cur;        //将当前要删除的指向头结点指向的节点
        this->link[0].cur = pos;                        //将头结点的后继指针指向当前位置
        return true;
    }

    //返回空闲节点的下标
    int FreePos(){

        int i = link[0].cur;
          //如果备用链表满啦，也就是说整个静态链表的内存空间用没了，那么就是第一个元素的指向为0
        if(link[0].cur){
            link[0].cur = link[i].cur;
        }
        
        return i;
    }
    public:
    StaticLink(){
        this->link = new Node[SIZE];
        length = 0;
    }
    ~StaticLink()
    {
        if(this->link != nullptr){
            delete this->link;
            this->link = nullptr;
        }
    }
    private:
    const int SIZE = 10000;
    int length;
    NodePtr link;
};
