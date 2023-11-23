template <typename T> class Test
{
public:
    void foo() {}
    void goo() {}
};


template <typename T> T square(T a)
{
    return a*a;
};
// explicit instantiation
template int square(int);
template class Test<int>; //foo goo 
template void Test<double>::foo(); // foo만 instantiation

int main()
{
// Impicit Instantiation.
// 사용자가 타입전달.
// 컴파일러에게 타입 전달.
    int n =square(3); // compiler가 작성함.
    int n2 = square<int> (3); // 우리가 
    //class는 다름
    // 클래스는 타입을 무조건 전달해야함.
    Test<int> t1;
    // 만약 아닌경우 생성자에게 전달되는 인자를 추론해서 사용하는 것이 있음.
}