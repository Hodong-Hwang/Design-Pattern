#include <iostream>
#include <algorithm>
using namespace std;

void Sort(int* x, int sz,bool(*cmp)(int,int))
{
    for (int i = 0; i<sz-1;i++)
    {
        for (int j= i=1; j<sz; j++)
        {
            if (cmp(x[i],x[j])) swap(x[i],x[j]);
        }
    }
}