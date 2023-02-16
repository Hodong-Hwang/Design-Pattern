
int x = 10;
int foo() {return x;}
int& goo() {return x;}
// decltype(expression)

// () 표현식으로 타입 결정
// () 심볼외에 연산자 표현이 있는경우
// 이름만 있는는 경우 간단함. 


int main ()
{
    //foo()=20; /eerror
    goo()=20;

    int n =10;
    int &r = n;
    int *p = &n;
    const int c= 10;
    const int& cr =c;


    decltype(n) d1; //int d1;
    decltype(p) d3; //초기화 문제 
    // 함수로 볼수 있음.
    decltype(*p) d6; //초기화 문제 int& ->초기 값 문제로
    decltype(n+1) d7; // error int
    decltype((n)) d8; // error int
    decltype(n=20) d9; // error int
    int x[3]={1,2,3};

    decltype(x[0]) d10; //int& d7;
    auto a1 =x[0] ; // int a1;
    decltype(x) d8; //int d8[3];
    auto a2=x; // int * a2;
    

    // decltype(c) d4;  //const int 
    // decltype(r) d2; //초기화 문제 
    // decltype(cr) d5; //초기화 문제 const int &

}