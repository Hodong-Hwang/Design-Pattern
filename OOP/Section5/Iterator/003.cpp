#include <iostream>

template<typename T> struct Node
{
    T data;
    Node* next;
    Node(T d ,Node* n) : data(d), next(n){}
};


template <typename T> class slist_iterator
{
    Node<T>* current  = 0 ;

public:
    inline slist_iterator(Node<T>* p = 0) : current(p){}
    inline slist_iterator& operator++ ()
    {
        current = current->next;
        return *this;
    }
    inline T& operator*() {return current->data;}
};


template<typename T> class slist
{

    Node<T>* head = 0;
    public:
    slist_iterator<T> begin()
    {
        return slist_iterator<T>(head);
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

    slist_iterator<int> p = s.begin();
    std::cout << *p <<std::endl;
    ++p;
    std::cout << *p <<std::endl;

}