

struct Rect
{
    int x,y,w,h;
    Rect(int x, int y, int w, int h):x{x},y{y},w{w},h{h}{}

    //auto인 경우 strong으로 반환함.
    std::weak_ordering operator<=>(const Rect& r)const
    {
        return (w*h)<=>(r.w*r.h);
    }

    auto operator<=>(const Rect& r)const
    {
        return (w*h)<=>(r.w*r.h);
    }

};

int square(int a){return a*a;}

void ex01()
{
    Rect r1 (1,1,5,2);
    Rect r2 (1,1,2,5);
    auto ret = r1<=>r2 ;
    if(ret ==std::strong_ordering::equal)
    {
        //r1,r2를 완전히 같닥 ㅗ봤을때 return 하는 역할
        
    }
}