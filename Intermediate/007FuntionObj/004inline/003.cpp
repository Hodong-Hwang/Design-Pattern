# include <iostream>
#include <algorithm>

struct Less
{
    inline bool operator()(int a, int b) const {return a<b;}
};

struct Greater
{
    inline bool operator()(int a, int b) const {return a>b;}
};

template <class T>
void sort(int* x, int sz, T cmp)
{
    for (int i=0; i<sz-1;i++)
    {
        for (int j=i+1;j<sz;j++)
        {
            if(cmp(x[i],x[j])) std::swap(x[i],x[j]);
        }
    }
}


int main ()
{
    int x[10]= {1,3,5,7,9,2,4,6,8,10};
    Less f1; f1(1,2); sort(x,10,f1);
    for (auto e : x) std:: cout << e << ",";
    std::cout<<std::endl;
    Greater f2; sort(x,10,f2);
    for (auto e : x) std:: cout << e << ",";
    std::cout<<std::endl;
}