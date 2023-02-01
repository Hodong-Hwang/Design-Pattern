// Code의 확장, 원본 ㅗㅋ드는 수정하지 않음.
// 부모 코드에서 자식 클래스를 만들어 새로욱ㄴ 기능을 추가함.
// 몇개의 코드는 오버라이등해서 수정..
// >> 상속의 경우 선호하는 옵션은 아님 (ex. Virtual -> Vector 소멸자 X)
// SRP의 단일 책임 원칙에 위반함.
// 이를 방지 우ㅏ기 위하여 에커레이터 패턴을 이용 (타입 코드에 수정을 피할 수 있게함.)
// 여기에 더해서 파생해야 할 타입의 개수가 과도하게 늘어나는 것도 막을 수 있다.
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;
    explicit Circle(const float radius_) : radius(radius_) {}

    void resize(float factor) { radius *= factor; }

    string str() const override
    {
        ostringstream oss;
        oss << "A Circle of raidus" << radius;
        return oss.str();
    }
};

// Dynamic Decerator
struct ColoredShape : Shape
{
    Shape &shape;
    string color;
    ColoredShape(Shape &shape, const string &color) : shape{shape}, color{color} {}
    string str() const override
    {
        ostringstream oss;
        // basic Shape.strt () + add current fucntion
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape &shape;
    uint8_t transparency;
    TransparentShape(Shape &shape, const uint8_t transparency) : shape{shape}, transparency{transparency} {}

    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f
            << "% transparency";
        return oss.str();
    }
};

/*
Square square{3};
TransparentShape demiSquare{square, 85};
cout << demiSquare.str();
1   TransparentShape myCircle{
2     ColoredShape{
3       Circle{23}, "green"
4     }, 64
5   };
6   cout << myCircle.str();
7   // 출력 결과 "A circle of radius 23 has the color green has 25.098% transparency"

“빨간색이면서 노란색이다”와 같이 모순된 상황을 야기한다. OOP의 테크닉들을 활용하면 예로든 중복 합성이 방지되도록 할 수 있을 것이다. 하지만 아래와 같은 경우는 어떻게 될까?
*/
// 1   ColoredShape<TransparentShape<Square>> square{"blue"};
// 2   square.size = 2;
// 3   square.transparency = 0.5;
// 4   cout << square.str();
// 5   // 이제 square의 어떤 멤버든 접근 가능
// 6   square.resize(3);

//// Static Decerator