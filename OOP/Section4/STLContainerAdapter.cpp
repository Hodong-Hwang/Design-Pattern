#include <iostream>
#include <list>
#include <vector>
#include <deque>

using namespace std;

template <typename T> 
class stackS: private list<T>
{

public : 
    void push(const T& a) { list<T>::push_back(a);}
    void pop() {list<T>::pop_back();}
    T& top() {return list<T>::back(); }
};

template <typename T> 
class stackS2
{
    list<T> st;
public : 
    void push(const T& a) { st.push_back(a);}
    void pop() {st.pop_back();}
    T& top() {return st.back(); }
};


template <typename T,typename C =deque<T>> 
class stackS3
{
    C st;
public : 
    void push(const T& a) { st.push_back(a);}
    void pop() {st.pop_back();}
    T& top() {return st.back(); }
};


int main ()
{
    stackS<int> s;
    s.push(10);
    s.push(20);
    //s.push_back(20);
    cout<<s.top() <<endl;

}