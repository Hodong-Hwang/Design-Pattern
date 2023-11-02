//인터페이스를 template으로 교체하자.
// Policy based-> Template 인자로 바꿔야함.
// 가상함수가아니기 때문에 빠름.

template <typename T, typename Ax=std::allocator<T>>
class Vector
{
    T* ptr;
    // 널유무 체크하늑네 안전
    Ax ax;
public:

// Strategy를 적용
    void resize(std::size_t newsize)
    {
        // 표준 문서에다가 문서화해서 약속을 해주어야함.
        //
        ptr =ax.allocate(size);
        ax.deallocate(ptr,size);
    }

};
template <typename T> struct Malloc_allocator 
{
    inline T* allocate(std::size_t size) {return static_cast<T*>(malloc(sizeof(T)*size));}
    inline void deallocate (T* ptr, std::size_t size) {free(ptr);}
    // 가상함수이기 때문에 느림.
    // 이를 개선하기 위해서 Policy based 기반으로 하는게 중요함.
    
};


int main()
{
    Vector<int,Malloc_allocator<int>> v;
}