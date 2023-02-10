#include <iostream>
using namespace std;
// extent<T,0>::Value 1차 배열 크기 구할 수 있음.
// extent<T,1>::value 2차 배열 크기 구할 수 있음.
template <typename T>
struct xis_array
{
    static constexpr bool value = false;
    static constexpr int size = 0;
};

template <typename T, int N>
struct xis_array<T[N]>
{
    static constexpr bool value = true;
    static constexpr int size = N;
};

template <typename T, int N>
struct xis_array<T[]> // unkonwn size
{
    static constexpr bool value = true;
    static constexpr int size = 0;
};
template <typename T>
void foo(T &a)
{
    if (xis_array<T>::value)
    {
        cout << "array" << endl;
    }
    else
    {
        cout << "not array" << endl;
    }
}

template <typename T>
void print_array(T &a)
{
    if (xis_array<T>::value)
    {
        if (!xis_array<T>::size) return;
        for (int i=0; i<xis_array<T>::size; i++)
        {
            cout << a[i] <<",";
        }
        cout <<endl;
    }
    else
    {
        cout << "input value is not array" << endl;
    }
}

int main()
{
    int x[3] = {1, 2, 3};
    foo(x);
    print_array(x);
}