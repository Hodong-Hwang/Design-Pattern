#include <iostream>
#include <list>

using namespace std;


template <typename T> struct IVisitor
{
    virtual void visit (T& elem) = 0 ;
    virtual ~IVisitor() {}
};

template <typename T> class TwiceVisitor : public IVisitor<T>
{
    public:
    virtual void visit(T& elem) {elem = elem *2;}
};

template <typename T> class ShowVisitor : public IVisitor<T>
{
    public: 
    virtual void visit(T& elem) {cout << elem << endl;}
};

template <typename T> struct IAcceptor
{
    virtual void accept(IVisitor <T>* p)=0;
    virtual ~ IAcceptor(){}
};

template <typename T> class List : public list<T>, public IAcceptor<T>
{
    public:
    using list<T>::list;
    virtual void accept(IVisitor<T>* p)
    {
        for (auto& e : *this)
        {
            p->visit(e);
        }
    }
    using list
};

int main ()
{
    List<int> s= {1,2,3,4,5,6,7,8,9,10};

    TwiceVisitor<int> tv;
    s.accept(&tv);

    ShowVisitor<int> sv;
    s.accept(&tv);

}