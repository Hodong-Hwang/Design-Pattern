#include <iostream>
//반복자 이름은 iterator로 접근함.
// 반복자 타입의 이름은 Container ::iterator로 적용
template <typename T> class slist_iterator;

template <typename T> struct Node
{
    T data;
    Node* next;
public:

    Node(const T& d, Node* n): data(d),next(n){}
};
template <typename T> class slist
{
    Node<T*> head = 0;
public:
    using iterator = slist_iterator<T>;

    void push_front(const T& a)
    {
        head=new Node<T>(a,head);
    }
    iterator begin()
    {
        return iterator(head);
    }
    iterator end()
    {
        return iterator(0);
    }
};

template <typename T> class slist_iterator
{
    Node<T>* current =0;
public:
    slist_iterator(Node<T>* p=0) : current(p){};

    slist_iterator& operator++()
    {
        //
        current = current->next;
        return *this;
    }
    T& operator*() {return current->data;}
    bool operator==(const slist_iterator& it)
    {
        return current == it.current;
    }
    bool operator!=(const slist_iterator& it)
    {
        return current !=it.current;
    }

};
// efinder가 처음을 가리키는 주소와, 마지막을 가르키는 주소가 필요함.
// begin -> 처음 Node를 가리키도록, end는 마지막 노드를 가리키는 iterator

int main()
{

    slist<int> s; //head 0
    s.push_front(10);  // 100 (10, 0)
    s.push_front(20); // 200 (20,*100)
    s.push_front(30); // 30 (30,*200)
    s.push_front(40); // 30 (30,*200)
    s.push_front(50); // 30 (30,*200)

    slist<int>::iterator p = s.begin(); // 300
    std::cout << *p <<std::endl;
    ++p;
    std::cout <<*p <<std::endl;
    while(p !=s.end())
    {
        std::cout << *p <<std::endl;
    }
}