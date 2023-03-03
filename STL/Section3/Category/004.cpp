#include <iterator>
template<typename T> struct Node
{
    T data;
    Node* next;
    Node(const T& a, Node* n):data(a), next(n){}
};

template<typename Category,
        typename T,
        typename Distance=std::ptrdiff_t,
        typename Pointer=T*,
        typename Reference =T&> 
struct iterator
{
    using iterator_category =Category;
    using value_type = T;
    using pointer = Pointer;
    using reference =Reference;
    using difference_type = Distance; // 
};

template<typename T> class slist_iterator :
    public iterator<std::forward_iterator_tag,T>
{
    Node<T>* current = 0;
    public:
    using iterator_category =std::forward_iterator_tag;
    using value_type = T;
    using Pointer = T*;
    using reference = T&;
    using difference_type = std::ptrdiff_t; // 

    slist_iterator(Node<T>* p = 0 ): current(p) {}

    slist_iterator& operator++()
    {
        current = current->next;
        return *this;
    }
    T& operator* () {return current->data;}

    bool operator == (const slist_iterator& it)
    {
        return current ==it.current;
    }
    bool operator!= (const slist_iterator& it)
    {
        return current!=it.current;
    }

};
