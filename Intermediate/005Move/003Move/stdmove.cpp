#include <iostream>
#include <type_traits>
class Object
{
    public:
    Object() = default ;
    Object (const Object& obj) { std::cout << "copy ctor" <<std::endl;}
    Object(Object&& obj) {std::cout << "move ctor" <<std::endl;}
};

Object foo()
{
    Object obj;
    return obj;
}

// T& lvalue만 받겠다.
// forwarding referecne는 모두 받겠다.
template <class T>
constexpr std::remove_reference_t<T>&& move(T&& obj) noexcept
{
    //return static_cast <T&&>(obj); // rvalue 캐스팅이 아님. -> Object&가 나옴.
    // T 안에 참조를 제거해주어야함.
    return static_cast <std::remove_reference_t<T> &&>(obj);
}
int main ()
{
    Object obj1;
    Object obj2;
    Object obj3 = foo();
    Object obj4=static_cast<Object&&>(obj1); // move 
    // 안만들었을 때 문제가 될건 없음. 
    Object obj5=std::move(obj2);
    Object obj6=move(Object()); //임시객체 전달에 대한 문제
    Object obj7=move(obj5); // copy가 발생함. -> T&& rvalue만 받아서 쓸 수 잇음

}