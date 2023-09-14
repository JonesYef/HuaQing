#ifndef __USER_NODE__H_
#define __USER_NODE__H_


template <typename  T>
struct Node {
    T data;
    Node * next;
};

template <class  T>
class List_Node
{

public:
    /*随机生成n个节点*/
    List_Node(int n);

    void Display();

    ~List_Node();
private:
    Node<T> *head=nullptr;
};

#endif

