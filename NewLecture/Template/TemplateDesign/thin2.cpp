

// T를 사용하지 않는 모든 멤버는 기반 클래스로 만들어 주어야함.

class VectorBase
{
    protected:
        void* buff;
        int sz;
    public:
        int size() const{}
        bool empty() const{}
        void push_front (const void* a){}
        void* front() {}
};

// void*를 바로사용하면 캐스팅의 불편함이 어렵다.
// 캐스팅을 책임 지는 템플릿으로함.
template <typename T> class Vector : private VectorBase
{
public:
    int size() const{ return VectorBase::size();}
    bool empty() const{return VectorBase::empty();}
    inline void push_front(const T& a) {VectorBase::push_front(static_cast<void*>(a));}
    inline T& front() {return static_cast<T&> (VectorBase::front());};
};

int main()
{

    
}