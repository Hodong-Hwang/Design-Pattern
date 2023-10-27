

// Anderi,,, Modern C++ Design.
// loki library
// Modern C++ Design

//Typelist는 값을 보관하지 않음.
// 내부적으로 2개의 Type을 보관함.
// n개의 type을 보관할 수 있도록함.     Typelist<int, Typelist<int,Typelist<int,double>>> t2;

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
#define TYPELIST_3(T1,T2,T3) Typelist<T1,TYPELIST_2(T2,T3)>;
#define TYPELIST_4(T1,T2,T3,T4) Typelist<T1,TYPELIST_3(T2,T3,T4)>;


int main()
{
    // Typelist<int, double> t1;
    // Typelist<int, Typelist<int,double>> t2;
    // Typelist<int, Typelist<int,Typelist<int,double>>> t3;
    // Typelist<int, NullType> t4;
    // Null Type...
    // 선형화를 윟
    //Typelist<int, Typelist<int,NullType>> t5;
    TYPELIST_1(int) t;
    TYPELIST_2(int,double) t2;
    //Typelist<int,NullType> t1;


}
