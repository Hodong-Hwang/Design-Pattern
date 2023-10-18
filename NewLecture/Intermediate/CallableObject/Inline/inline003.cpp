#include <iostream>
#include <algorithm>
template <typename T>
struct Less
{
  inline bool operator() (T a, T b){ return a<b;}
};

template <typename T>
struct Greater
{
  inline bool operator() (T a, T b){ return a>b;}
};


template <typename T, typename compare=Greater<T>>
void sort (T* x, T sz, compare cmp=Greater<T>())
{
    for (int i =0 ;  i<sz-1; i++)
    {
        for (int j=i+1; j<sz; j++)
        {
            if(cmp(x[i],x[j])) // 비교 함수를 부르기 때문에 느려짐.
            {
                std::swap(x[i],x[j]);
            }
        }
    }
}


int main()
{
    int x[10]={1,3,5,7,9,2,4,6,8,10};
    Less<int> f1;
    sort<int>(x,10,f1);

    for (auto e : x)
    {
        std::cout << e << ",";
    }
    std::cout <<std::endl;
    sort<int>(x,10);
    for (auto e : x)
    {
        std::cout << e << ",";
    }
    std::cout <<std::endl;
}