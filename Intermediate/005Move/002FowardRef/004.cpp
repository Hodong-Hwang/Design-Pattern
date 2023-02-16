

int main ()
{
    int n= 0;
    auto a1 = n; // ok
    auto a2 = 0 ; //ok
    auto&& a3 =n; // ok
    auto&& a4 =0 ; // ok rvalue refernce가 아니라 forwaring reference에 해당함.
}