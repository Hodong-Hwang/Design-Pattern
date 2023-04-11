#include <iostream>

using namespace std;

template<typename T> struct Node
{
    T data;
    Node* next;
    Node(T d ,Node* n) : data(d), next(n){}
};



template<typename T>class slist
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