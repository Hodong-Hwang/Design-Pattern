#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d ,Node* n) : data(d), next(n){}
};


class slist
{

Node* head = 0;
public:
    void push_front(int n) {head = new Node(n,head);}
    int front(){return head->data;}

};
