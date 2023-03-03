#include <iostream>
using namespace std;

class MutexLock
{
    public:
    inline void Lock(){cout << "mutex lock" <<endl;};
    inline void UnLock(){cout << "mutex UnLOck" <<endl;};
};

class NoLock
{
    public:
    inline void Lock(){};
    inline void UnLock(){};
};

template <typename T, typename ThreadModel = NoLock> class List
{
    ThreadModel tm;
    
    public:
    void push_front(const T& a)
    {
        tm.Lock();
        // ...
        tm.UnLock();
    }
};



List<int, MutexLock> s;
int main ()
{

}