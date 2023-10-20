
template <typename T> class allocator
{
    public:
    T* allocatoe(){};
    void deallocate() {};
}

template <typename T, typename Ax = allocator<T>> class TVector
{
    T* buff;
    public:
    void  resize (int n)
    {
            
    }

};