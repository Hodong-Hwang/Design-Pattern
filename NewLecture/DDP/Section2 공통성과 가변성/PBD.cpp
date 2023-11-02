template <typename T>
class Vector
{
    T* ptr;
public:
// Resize의 알고리즘은 변하지 않음.
// 방식만 변화도록
    void resize(std::size_t newsize)
    {
            ptr =allocate(size);
            deallocate(ptr,size);
    }
    virtual T* allocate(std::size_t size) {return new T[size];}
    virtual void deallocate (T* ptr, std::size_t size){delete[] ptr;}
};

template <typename T>
class Malloc_Vector
{
public:

    void resize(std::size_t newsize)
    {
            ptr =allocate(size);
            deallocate(ptr,size);
    }
    virtual T* allocate(std::size_t size) {return static_cast<T*>(malloc(sizeof(T)*size));}
    virtual void deallocate (T* ptr, std::size_t size){free(ptr);}
};

//단점 메모리 할당하는 코드를 재사용하기 어렵다.
// vector, list, set, map 등도 메모리 할당 방식을 변경하려면 파생클래스를 만들어주어야함.

int main()
{

}
//memory 할당
// new, malloc, system call, memory pooling
