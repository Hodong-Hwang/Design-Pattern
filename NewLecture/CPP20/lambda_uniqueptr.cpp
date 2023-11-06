

template <typename T, typename D> class unique_ptr
{
    T* obj;
public:
    explicit  unique_ptr (T* p=0) : obj(p){

    }
    ~unique_ptr()
    {
        D d; // Default 생성자가 필요함. C++ 20에서는 제공하지만 C++ 그이하에서는 안됨.
        d(obj);
    }
    
};

int main()

{
    //unique_ptr<int, decltype([](int* p){delete p}) p1(new int);
    auto f = [](int* p){delete p;};
    unique_ptr<int, decltype(f)> p1(new int);
    unique_ptr<int, decltype(f)> p1(new int);


}