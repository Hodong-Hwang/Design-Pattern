#include <iostream>
using namespace std;
#include <type_traits>

template <typename T>
void eadvance_imp (T& p , int n,random_access_iterator_tag)
{
    p=p+n;
    cout << "random Accesoble" <<endl;
}

template <typename T>
void eadvance_imp (T& p , int n,input_iterator_tag)
{
    while (n--)  ++p; // 성능 저하 (vector의 경우)
    cout << "input Accesoble" <<endl;

}

template <typename T>
void eadvance (T& p , int n)
{
    // T::iterator_category 
    eadvance_imp(p,n,typename T::iterator_category());
}



template <typename T>
void eadvance17 (T& p , int n)
{
    if constexpr (is_same <typename T::iteraotr_category, random_access_iterator_tag>::value)
    {
        p=p+n;
    }
    else
    {
        while (n--)  ++p; // 성능 저하 (vector의 경우)
    }
}

// 3. SIFANE
template <typename T>
typename enable_if<is_same <typename T::iteraotr_category, random_access_iterator_tag>::value>::type
eadvance3 (T& p , int n)
{

      while (n--)  ++p; // 성능 저하 (vector의 경우)
}


template <typename T>
typename enable_if<!is_same <typename T::iteraotr_category, random_access_iterator_tag>::value>::type
eadvance3 (T& p , int n)
{

    p=p+n;
}