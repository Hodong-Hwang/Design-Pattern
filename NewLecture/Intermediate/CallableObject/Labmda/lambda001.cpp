

// lambda > function object


#include <iostream>
#include <vector>
#include <algorithm>


int main ()
{
    std::vector v{2,4,6,8, 10};

    std::sort (v.begin(),v.end(),[](int a, int b){return a>b;});
    
}