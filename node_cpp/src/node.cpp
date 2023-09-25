#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include "node.hpp"

template <class  T>
List_Node<T>::List_Node(int n)
{   
    head=new Node<T>;
    Node<T> *p =head;
    std::default_random_engine e(time(0));
    std::uniform_int_distribution<T>u(0,200);
    for(int i=0;i<n;i++)
    {
        Node<T> *node=new Node<T>;
        node->data=u(e);
        p->next=node;
        p=node;
    }
    std::cout<<"init is done\n";
}

template <class  T>
List_Node<T>::~List_Node()
{
    Node<T> * p=head->next;
    Node<T>*q;
    while(p){
        q=p;
        p=p->next;
        delete q;
    }
    std::cout<<"delet done\n";
}

template <class  T>
void List_Node<T>::Display(){
    Node<T> * p=head->next;
    while(p)
    {
        std::cout<<p->data<<"->";
        p=p->next;
    }
    std::cout<<"nullptr\n";

}

