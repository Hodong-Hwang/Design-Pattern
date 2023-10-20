
// Policy Based Design << ㄷksdlf 

template <typename T>
class List
{
public :
    void push_front (const T& a)
    {
        // lock()
        // ...
        //  unlock()
    } 
};


template <typename T, typename ThreadModel>
class SafeList
{
    ThreadModel tm;
public :
    void push_front (const T& a)
    {
        tm.lock();
        // lock()
        // ...
        //  unlock()
        tm.unlock();
    } 
};

class NoLock
{
    public:
    inline void lock() {}
    inline void unliock () {}
};

List<int> s;
SafeList<int,NoLock> ss;
int main()
{
    s.push_front(10);
}