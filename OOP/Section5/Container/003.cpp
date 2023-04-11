#include <iostream>

using namespace std;

struct Node
{
    void* data;
    Node* next;
    Node(void* d ,Node* n) : data(d), next(n){}
};


class slistImp
{

Node* head = 0;
public:
    void push_front(void* n) {head = new Node(n,head);}
    void* front(){return head->data;}

};


template<typename T>class slist : public slistImp
{

Node* head = 0;
public:
    inline void push_front(T n) {slistImp::push_front(void* n);}
    inline T front(){return (T)(slistImp::front());}

};


int main ()
{
    slist<int> s;
    s.push_front(10);
    s.push_front(20);
    int n = s.front();
}