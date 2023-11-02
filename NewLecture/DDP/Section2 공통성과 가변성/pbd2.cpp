template <typename T> struct IAllocator
{
    virtual T* allocate(std::size_t size) {return new T[size];}
    virtual void deallocate (T* ptr, std::size_t size){delete[] ptr;}
};


template <typename T>
class Vector
{
    T* ptr;
    // 널유무 체크하늑네 안전
    IAllocator<T>* ax=nullptr;
public:

// Strategy를 적용
    void resize(std::size_t newsize)
    {
        ptr =ax->allocate(size);
        ax->deallocate(ptr,size);
    }

};
template <typename T> struct Malloc_allocator : public IAllocator<T>
{
    virtual T* allocate(std::size_t size) override {return static_cast<T*>(malloc(sizeof(T)*size));}
    virtual void deallocate (T* ptr, std::size_t size) override {free(ptr);}
    // 가상함수이기 때문에 느림.
    // 이를 개선하기 위해서 Policy based 기반으로 하는게 중요함.
    
};
