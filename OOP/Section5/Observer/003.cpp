// 하나의 데이터가 업데이트 되었을 때, 나머지 데이터도 업데이트 하는 것을 Observer Pattern이라고 함.
#include <iostream>
#include <vector>
class Subject;

struct IGraph
{
    virtual void update(Subject*)=0;
    virtual ~IGraph(){}
};

class Subject
{
    std::vector<IGraph*> v;
public :
    void attach(IGraph *p) {v.push_back(p);}
    void detach (IGraph *p){}
    void notify ()
    {
        for (auto p : v)
        {
            p->update(this);
        }
    }
};

class Table : public Subject
{
    int data;
public:
    int GetData() {return data;}
    void SetData(int d )
    {
        data = d;
        notify();
    }

};

class PieGraph : public IGraph
{
public:
    virtual void update(Subject *p)
    {
        int n = static_cast<Table*>(p)->GetData();
        Draw(n);
    }
    void Draw(int n)
    {
        std::cout << "PieGraph : \n";
        for (int i = 0 ;  i<n; i++)
        {
            std:: cout << "*";
        }
        std::cout <<std::endl;

    }
};
class BarGraph : public IGraph
{
public:
    virtual void update(Subject *p)
    {
        int n = static_cast<Table*>(p)->GetData();
        Draw(n);
    }
    void Draw(int n)
    {
        std::cout << "BarGraph : \n";
        for (int i = 0 ;  i<n; i++)
        {
            std:: cout << "+";
        }
        std::cout <<std::endl;
    }
};

int main ()
{
    BarGraph bg;
    PieGraph pg;


    Table t;
    t.attach(&bg);
    t.attach(&pg);
    while (1)
    {
        int n ;
        std::cin >> n ;
        t.SetData(n);
    }

}