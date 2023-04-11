#include <iostream>

using namespace std;

struct Object
{
    virtual ~Object(){}
};

class Dialog : public Object{};
class Point : public Object{};

//

struct Node
{
    Object* data;
    Node* next;
    Node(Object* d ,Node* n) : data(d), next(n){}
};


class slist
{

Node* head = 0;
public:
    void push_front(Object* n) {head = new Node(n,head);}
    Object* front(){return head->data;}

};

int main ()
{
    slist s;
    s.push_front(new Point);
    s.push_front(new Point);

    Point* p = static_cast<Point*> (s.front());
}