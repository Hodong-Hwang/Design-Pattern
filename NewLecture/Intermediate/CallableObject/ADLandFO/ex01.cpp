#include <algorithm>
#include <string>
void object()
{
    auto ret1 =std::max(1,2);
    auto ret2 =std::ranges::max(1,2);
    // 함수 객체로 만든이유가 존재함 -> ADL을 해결하기 위함.
    auto ret3 =std::ranges::max.operator()(1,2);
}

namespace Graphics
{
    struct Point
    {
        int x, y;
    };
    void draw_pixel (const Point& pt){};
    Point operator+ (const Point& p1, const Point& p2)
    {
        return Point{p1.x+p2.x,p1.y+p2.y};
    }
};

void ADLEX()
{
    
    Graphics::Point pt{1,2};
    Graphics::draw_pixel(pt);
    // ADL (Argument Dependet Lookup)
    // 인자 기반으로 namepsace 찾음 인자가 포함된 name space를 가지고 찾음.
    // ADL은 연산자 재정의를 하기 위해서 정의됨
    draw_pixel(pt);
}

void ADLEX2()
{
    Graphics::Point p1{1,2};
    Graphics::Point p2{1,2};

    auto ret2 = p1+p2; // >>ADL이 없으면 어렵다.
    // 없는경우 아래와 같음
    auto ret1 = Graphics::operator+(p1,p2);
}

void ADLEX3()
{
    std::string s1 = "AA";
    std::string s2 = "BB";
    int n1=1, int n2=2;
    std::max(n1,n2);
    max(s1,s2);
    max(n1,n2);// << error
}
int main ()
{


}