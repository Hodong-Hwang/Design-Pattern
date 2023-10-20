#include <iostream>
class CompilerGenerateName
{
    public:
    inline int operator()(int a, int b) const
    {
        return a+b;
    }
    using FP = int(*) (int,int);
    static int _invoke(int a, int b)
    {
        return a+b;
    }

    // int(*f)(int,int)=CompilerGenerateName{}; //<< 오류 발생
    operator FP() const {return &CompilerGenerateName::_invoke;};

    };

int main()
{
    auto f1=[](int a, int b){return a+ b;};
    int(*f2)(int,int)=f1;
    // 함수 객체가 함수 포인터로 변환이됨.
    // 변환 연산자를 제공하고 있다.
    int(*f)(int,int)=CompilerGenerateName{};
    std::cout << f(3,4) <<std::endl;    
}