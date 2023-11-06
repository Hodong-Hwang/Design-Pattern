#include <iostream>
template <typename T> struct Node
{
    T data;
    Node* next;
    Node(const T& a, Node* n): data(d),next(n){}
};
template <typename T> class slist
{
    Node<T*> head = 0;
public:
    void push_front(const T& a)
    {
        head=new Node<T>(a,head);
    }
};
// 배열과 list이동 방법이 다름
// ++ vs p->next
// 접근방법
// *p vs p->data
// efind를 사용해서 위를 같ㅊ이 적용할 수 있또록.


int main()
{
    slist<int> s; //head 0
    s.push_front(10);  // 100 (10, 0)
    s.push_front(20); // 200 (20,*100)
    s.push_front(30); // 30 (30,*200)


}