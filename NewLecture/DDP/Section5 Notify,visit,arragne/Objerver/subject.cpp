#include <vector>

class IChart
{
public:
    void update(int data);
};

class Subject // 관찰자 대상의 기본 로직을 제공한다.
{
    std::vector<IChart*> v;
public:
    virtual ~Subject(){}
    void attach(IChart* p)  {v.push_back(p);}
    void detach (IChart* p) {}
    void notify(int data)
    {
        for(auto p:v)
            p->update(data);
    }
};