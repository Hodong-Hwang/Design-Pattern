int p=0;
class Test{
    public:
    Test(){};
};

template <typename T>
int foo(T t)
{
    typename T::DWORD *p; //Value or Type...
    // value case 5*p;
    // typedef -> Type ( integer ..)
    
    return 0;
}

int main ()
{
    Test t;
    foo(t);
}
