#include <compare>
class Int32
{
public:
    int value;
    explicit Int32(int v=0) : value(v){}
    // 비교연산자인 경우 9개를 만들어줘야함.
    //friend bool operator< (const Int32& obj){return obj.vau}

    auto operator<=>(const Int32& other) const {return value<=>other.value;}
   // 항등 여부는  그냥 함. -> 속도 저하 문제가 발생함.
    auto operator==(const Int32& other) const {return value == other.value; }
    auto operator<=>(const int other) const {return value<=>other;}
    auto operator==(const int other) const {return value == other; }
};