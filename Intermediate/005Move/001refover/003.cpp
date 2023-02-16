

// reference collapsing
    //참조의 참조를 가리킬 수 없다.

int main()
{
    int n = 3;
    int& lr = n;
    int&& rr =3;

    //int& & ref2ref =lr ; //eerror
    //reference collapsing
    decltype(lr)& r1 =n; //int& & => 타입추론에서는 erro는 아님.
    decltype(lr)&& r2 = n ; // int&
    decltype(rr)& r3 = n ; // int&
    decltype(rr)&& r4 = 3 ; // int&&

    //  && 2개만 있을 때 2개

    // 적용 되는 경우 typedef, using decltype,template에서 사용될 수 있음 .!!
    typedef int& LREF ;


}