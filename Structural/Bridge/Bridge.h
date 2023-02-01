#include "iostream"
using namespace std;
struct Renderer
{
    virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer
{
    void render_circle(float x, float y, float radius) override
    {
        cout << "Rasterizing circle of radius " << radius << endl;
    }
};

struct RasterRenderer : Renderer
{
    void render_circle(float x, float y, float radius) override
    {
        cout << "Drawing a vector circle of radius " << radius << endl;
    }
};

struct Shape
{
protected:
    Renderer &renderer;
    Shape(Renderer &renderer) : renderer{renderer} {}

public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape
{
    float x, y, radius;

    void draw() override
    {
        renderer.render_circle(x, y, radius);
    }
    // 이 패턴은 쉽게 눈에 들어온다. 당연하게도 draw() 멤버 함수가 가장 흥미롭다. 브릿지를 이용해 Circle(원의 중심 좌표와 지름 정보를 가진)을 렌더링 절차에 연결하는 부분이 draw()안에 구현된다.
    //  여기서 브릿지는 Renderer이다. 예를 들어

    void resize(float factor) override
    {
        radius *= factor;
    }

    Circle(Renderer &renderer, float x, float y, float radius)
        : Shape{renderer}, x{x}, y{y}, radius{radius} {}
};

int main()
{
    RasterRenderer rr;
    Circle raster_circle{rr, 5, 5, 5};
    raster_circle.draw();
    raster_circle.resize(2);
    raster_circle.draw();
    return 0;
}