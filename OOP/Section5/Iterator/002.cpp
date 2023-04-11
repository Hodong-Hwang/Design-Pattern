#include <iostream>
template<typename T> struct Node
{
    T data;
    Node* next;
    Node(T d ,Node* n) : data(d), next(n){}
};

template<typename T> struct IEnumerator
{
    virtual ~IEnumerator(){}
    virtual bool MoveNext() = 0;
    virtual T& GetObject()=0;

};

template<typename T> 
class SlistEnumrator : public IEnumerator<T>
{
    Node<T>* current = 0;
    public:

    SlistEnumrator(Node<T>* p=0) : current(p){}
    virtual bool MoveNext () 
    {
        current = current->next;
        return current;
    } 
    virtual T& GetObject() {return current->data;};
};


//  

template <typename T> struct  Ienumerable
{
    virtual ~Ienumerable(){}
    virtual IEnumerator<T>* GetEnumerator() = 0;
};


template<typename T> class slist : public Ienumerable<T>
{

    Node<T>* head = 0;
    public:
    virtual IEnumerator<T>* GetEnumerator()
    {
        return new SlistEnumrator<T>(head);
    }

    void push_front(T n) {head = new Node<T>(n,head);}
    T front(){return head->data;}

};

int main()
{
    slist<int>s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);

    IEnumerator<int>* p = s.GetEnumerator();

    int n = p->GetObject();
    std::cout << n <<std::endl;
    p->MoveNext();
    std::cout << p->GetObject() <<std::endl;

}