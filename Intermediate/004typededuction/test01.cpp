template<typename T1, typename T2> 
//decltype(a+b) Add (T1 a, T2 b)
// auto Add (T1 a, T2 b) ->decltype (a+b) // suffix return
// auto Add (T1 a, T2 b)  // return 문에 따라서 auto를 결정함 -> auto의 참조문을 버리고 return 해줌.
decltype(auto) Add (T1 a, T2 b) // suffix return
{
    return a+b;
}