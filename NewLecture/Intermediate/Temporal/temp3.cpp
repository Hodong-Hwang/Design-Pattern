#include <iostream>
class Point
{
    public:
    int x,y;

Point (int x, int y) :x(x),y(y) {std::cout << "Point"<<std::endl;}
~Point()  {std::cout << "~Point"<<std::endl;}
    void set(int x, int y) {x=x;y=y;}
};



void foo(const Point& pt)
{
    std::cout <<"foo" << std::endl;
}
//std::string_view -> const std::string& 보다 효율적임.
Point gpt(1,2);

Point f3()
{
    return gpt; // return by value -> 임시객체가 반환됨.
}
Point& f4()
{
    return gpt; // return by value -> 임시객체가 생성되지 않음.
}
Point& f5()
{
    Point pt(1,2);
    return pt; // 지역변수가 파괴됨.
}

class Counter
{
    int count {0};
public:
    //Counter increment() // 값 리턴은 임시객체다!
    Counter& increment()
    {
        ++count;
        return *this;
    }
    ~Counter()
    {
        std::cout <<"~Counter()" <<std::endl;
    }
    int get() const {return count;}
};

int main()
{
    Point pt(1,2);
    foo(pt);
    //foo 한테만 보내도록 객체를 만듦.
    // 객체가 함수 인자로만 사용된다면, temporary가 효율적일 수 있음.
    foo(Point(1,2)); // foo (Point{1,2})
    foo({1,2});// foo (Point{1,2})

    std::cout <<"----------------" <<std::endl;

   // f3().x=10;// error -> Return 용 임시객체가 생성됨.
    f4().x=10;// 객체가 오기 때문에 error가 아님.
    Counter c;
    c.increment().increment().increment();
    // 임시객체 임시 객체 임시객체가 ㅏㄴ듦.
    // -> 3 2 1 
    std::cout <<c.get() <<std::endl;
    std::cout <<"----------------" <<std::endl;

}