#include <iostream>
#include <algorithm>
template <typename T>
bool cmp1 (T a, T b)
{
    return a<b;
}

template <typename T>
bool cmp2 (T a, T b)
{
    return a>b;
}

template <typename T>
void sort (T* x, T sz, bool(*cmp)(T,T))
{
    for (int i =0 ;  i<sz-1; i++)
    {
        for (int j=i+1; j<sz; j++)
        {
            if(cmp(x[i],x[j]))
            {
                std::swap(x[i],x[j]);
            }
        }
    }
}


int main()
{
    int x[10]={1,3,5,7,9,2,4,6,8,10};
    sort<int>(x,10,&cmp2);

    for (auto e : x)
    {
        std::cout << e << ",";
    }
    std::cout <<std::endl;
}