

// T를 사용하지 않는 모든 멤버는 기반 클래스로 만들어 주어야함.

class VectorBase
{
    protected:
        int sz;
    public:
        int size() const{}
        bool empty() const{}
};

template <typename T> class Vector : VectorBase
{
    T* buff;
    void push_front (const T& a){}
    T& front() {}
};

int main()
{

    
}