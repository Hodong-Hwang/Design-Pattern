#include <iostream>
using namespace std;

struct ISync
{
    virtual void Lock()=0;
    virtual void UnLock() = 0 ;
    virtual ~ISync(){};
};

template <typename T> class List
{
    ISync* pSync = nullptr;
    public:
    void push_front(const T& a)
    {
        if(pSync !=nullptr) pSync->Lock();
        // ...
        if(pSync !=nullptr) pSync->UnLock();

    }
};

class MutexLock : public ISync
{
    public:
    virtual void Lock(){};
    virtual void UnLock(){};
};