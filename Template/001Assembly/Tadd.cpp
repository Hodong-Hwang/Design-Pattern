
int add(int a, int b)
{
    return a+b;
}

template <typename T>
T square (T a)
{
    return a*a;
}

int main ()
{
    square(3);
    square (3.3);

}

// Assembly code
// g++ .\Tadd.cpp -S
// g++ -fdump-tree-original *.cpp