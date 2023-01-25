#include <vector>
#include <memory>
// 존재 함.
// < 그리기 객체 >

// struct VectorObject
// {
//   virtual std::vector<line>::iterator begin()=0
//   virtual std::vector<line>::iterator end()=0
// }

// 변환 작업에 해당하는 Method가 존재하여야함.
struct Point
{
    int x,y;
};

struct Line
{
    Point start,end;
};


struct VectorObject
{
  virtual std::vector<Line>::iterator begin()=0;
  virtual std::vector<Line>::iterator end()=0;
};

// 이렇게 하면 사각형 Rectangle을 다음과 같이 그 시작점과 크기를 입력받아 생성하고, 
// 사각형을 구성하는 선분들을 vector<Line> 타입 필드에 저장하여 그 꼭짓점들만 노출하는 방식으로 정의할 수 있다.
struct VectorRectangle : VectorObject
{
    VectorRectangle(int x, int y, int width, int height)
    {
        lines.emplace_back(Line{ Point{x,y}, Point{x + width,y} });
        lines.emplace_back(Line{ Point{x + width,y}, Point{x+width, y+height} });
        lines.emplace_back(Line{ Point{x,y}, Point{x,y+height} });
        lines.emplace_back(Line{ Point{ x,y + height }, Point{ x + width, y + height } });    
    }
    std::vector<Line>::iterator begin() override 
    {
        return lines.begin();
    }
    std::vector<Line>::iterator end() override 
    {
        return lines.end();
    }
    private:
    std::vector<Line> lines;
};

class CPaintDC;

void DrawPoints(CPaintDC& dc, std::vector<Point>::iterator start, std::vector<Point>::iterator end)
{
    for (auto i = start; i != end; ++i)
    {
        dc.SetPixel(i->x, i->y, 0);
    }
}
//  그리기 인터페이스는 점을 찍는 것밖에 없지만 우리는 선분을 그려야 한다
// 선분을 점의 집합으로 변환하는 작업은 생성자에서 일어난다. 
struct LineToPointAdapter
{
    typedef std::vector<Point> Points;
    LineToPointAdapter(Line& line)
    {
        int left = std::min(line.start.x, line.end.x);
        int right = std::max(line.start.x, line.end.x);
        int top = std::min(line.start.y, line.end.y);
        int bottom = std::max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;
        if (dx == 0)
        {
            for (int y = top; y <= bottom; ++y)
            {
                points.emplace_back(Point{ left,y });
            }

        }
        else if (dy == 0)
        {
            for (int x = left; x <= right; ++x)
            {
                points.emplace_back(Point{ x, top });

            }


        }
    }
    virtual Points::iterator begin() { return points.begin(); }
    virtual Points::iterator end() { return points.end(); }
    private :
    Points points;

}
void ex1()
{
    std::vector<std::shared_ptr<VectorObject>> vectorObjects{
        std::make_shared<VectorRectangle>(10,10,100,100),
        std::make_shared<VectorRectangle>(30,30,60,60)
    };
    for (auto& obj : vectorObjects)
    {
        LineToPointAdapter lpo{ line };
        DrawPoints(dc, lpo.begin(), lpo.end());
    }


}
void ex2()
{
    std::vector<std::shared_ptr<VectorObject>> vectorObjects
    {
        std::make_shared<VectorRectangle>(10,10,100,100),
        std::make_shared<VectorRectangle>(30,30,60,60)
    };

  std::vector<Point> points;
  for (auto& o : vectorObjects)
   {
     for (auto& l : *o)
    {
       LineToPointAdapter lpo{ l };
       for (auto& p : lpo)
        points.push_back(p);
     }
 }
    


}

// with  가지 방법은 캐싱을 이용하는 것이다. 즉, 모든 Point를 애플리케이션이 기동할 때 미리 어댑터를 이용해 정의해 두고 재활용하는 것이다.
