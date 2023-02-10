template <typename T> 
class Test
{
    void foo(){}
    void bar(){}
};

template <typename T>
T square (T a)
{
    return a*a;
}

// template class Test<int>; // foo and bar
template void Test<int>::foo(); // partially instantiation.
// explicit instantiation
//template int square<int>(int);
//template int square<>(int);
template int square(int);
int main()
{

}
