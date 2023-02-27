int main ()
{
    
    
    auto f1 =[](int a, int b) {return a+b;};
    //auto& f2 =[](int a, int b) {return a+b;};
    auto&& f3 =[](int a, int b) {return a+b;};
    const auto& f4 =[](int a, int b) {return a+b;};

}