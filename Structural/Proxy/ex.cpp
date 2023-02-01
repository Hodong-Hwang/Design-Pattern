
/*
가장 단순하면서도 직접적인 프록시 패턴의 예는 스마트 포인터이다. 스마트 포인터는 포인터의 참조 횟수를 관리하고, 몇몇 연산자를 오버라이딩하는 래퍼이다
스마트 포인터는 일반 포인터가 사용될 자리에 대신 들어갈 수도 있다.
예를 들어 if (ba) { ... }와 같은 구문에서 ba가 포인터일 때 의미 있는 동작을 한다면 스마트 포인터여도 의미 있는 동작을 한다
이런 식으로 포인터가 사용될 자리에 스마트 포인터가 대신 사용될 수 있다.
*/
#include <string>
#include <iostream>
using namespace std;
// Property PRoxy

template <typename T>
struct Property
{
    T value;
    Property(const T initial_value)
    {
        *this = initial_value;
    }
    operator T()
    {
        // get 작업 수행
        return value;
    }
    T operator=(T new_value)
    {
        // set 작업 수행
        return value = new_value;
    }
};
struct Creature
{
    Property<int> strength{10};
    Property<int> agility{5};
};

void ex()
{
    Creature creature;
    creature.agility = 20;
    auto x = creature.strength;
}

// 위 코드에는 get/set 함수를 대신해서 get 작업, set 작업에 해당하는 동작이 구현되어야 할 위치가 각각 주석으로 표시되어 있다.
// 보통 이 부분들은 상황에 맞게 커스터마이징이 된다(당연하지만 커스터마이징이 필요 없다면 굳이 프록시를 쓸 이유가 없다).

// Vritual Proxy

// “느긋한 인스턴스화(lazy instantiation) : 어떤 경우에는 객체를 생성하되 불필요하게 일찍 자원이 할당되는 것을 원하지 않을 수도 있다.
// 시점에 이러한 느긋한 동작 방식이 필요한지 알고 있다면 사전에 계획해서 특별히 준비해 둘 수 있다.
// 간주되는 객체를 대리하는 프록시를 만들어 “느긋한” 동작을 하게 만들 수 있다.
// 실제 존재하지 않는 객체를 나타낼 수도 있기 때문에 이러한 프록시를 버추얼 프록시라 부른다. 버추얼 프록시를 이용하면 실제 인스턴스에 접근하는 대신 무언가 가상의 것에 접근하게 된다.

struct Image
{
    virtual void draw() = 0;
};

struct Bitmap : Image
{
    Bitmap(const string &filename)
    {
        cout << "Loading image from " << filename << endl;
    }

    void draw() override
    {
        cout << "Drawing image " << filename << endl;
    }
};

//  그렇게 “느긋한” 동작 방식으로 바꾸고 싶지만 Bitmap이 외부 라이브러리여서 코드를 수정할 수 없다고 가정하자. 그리고 다른 여러 가지 가상의 이유로 상속을 이용할 수도 없다고 가정하자.

struct LazyBitmap : Image
{
    LazyBitmap(const string &filename)
        : filename(filename) {}
    ~LazyBitmap() { delete bmp; }
    void draw() override
    {
        if (!bmp)
            bmp = new Bitmap(filename);
        bmp->draw();
    }

private:
    Bitmap *bmp{nullptr};
    string filename;
};

void draw_image(Image &img)
{
    cout << "About to draw the image" << endl;
    img.draw();
    cout << "Done drawing the image" << endl;
}
// 단지 그림 파일의 이름만 저장하고 실제 파일 로딩 작업은 수행하지 않는다.
// “느긋한” 동작의 실행은 draw()에서 일어난다.
// draw()에서는 포인터 bmp를 검사하여 객체가 생성되었는지(bmp의 “성급한” 동작이 수행되었는지) 확인하고, 만약 생성되지 않았으면 생성한 후 실제 그림을 그리는 bmp의 draw()를 호출한다.