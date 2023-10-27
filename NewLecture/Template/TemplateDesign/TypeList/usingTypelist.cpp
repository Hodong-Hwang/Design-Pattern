#include <iostream>

template <typename T, typename U> struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

struct NullType
{
};

// 선형화를 위한 Macro 도입
#define TYPELIST_1(T1) Typelist<T1,NullType>
#define TYPELIST_2(T1,T2) Typelist<T1,TYPELIST_1(T2)>
#define TYPELIST_3(T1,T2,T3) Typelist<T1,TYPELIST_2(T2,T3)>
#define TYPELIST_4(T1,T2,T3,T4) Typelist<T1,TYPELIST_3(T2,T3,T4)>

template <typename T> struct Holder
{
    T value;
};



// GenScatterHierachy => MakeCode
template <typename T, template <typename> class Unit> 
class MakeCode :public Unit<T>
{

};
template < template <typename> class Unit> 
class MakeCode <NullType,Unit>
{
};
// MakeCode 1번쨰 인자가 TypeList인 경우
template <typename Head,typename Tail,template <typename> class Unit> 
class MakeCode<Typelist<Head,Tail>,Unit> :public MakeCode<Head,Tail>, MakeCode<Tail,Unit>
{

};

int main()
{

    Holder<int> h1;
    MakeCode<int,Holder> mc1; //mc1과 h1은 ㅇ메모리 모양이 동일함
    MakeCode<double,Holder> mc2; // holder<double>
    MakeCode<NullType, Holder> mc3; // Empty

    // Typelist<int, Typelist<double,NullType>>
    // int value 
    // MakeCode <int,Unit>, MakeCode<TypeList<double,Nulltype>,Unit>
    //                    MakeCode<Double,Nulltype> , Unit
    // therefore int value, double value.
    MakeCode<TYPELIST_2(int,double),Holder> m;


}