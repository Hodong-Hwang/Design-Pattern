#include <iostream>
#include <bitset>
#include <random>
class URandom
{
    std::bitset<10> bs;
    bool recycle;
    std::mt19937 randge {std::random_device{}()};
    std::uniform_int_distribution<int> dist{0,9};

public:
    URandom(bool recycle = false) : recycle(recycle)
    {
        bs.set(); // 모두 1로 세팅
       // bs.set(5); // 5번째 비트만 1로
    }
    int operator()()
    {
        if (bs.none())
        {
            if(recycle)
            {
                bs.set();
            }
            else 
            {
                return -1;
            }
        }
        int k= -1;
        while(! bs.test(k=dist(randge)));
        bs.reset(k);
        return k;

    }
};

URandom urand;

int main()
{
    for (int i = 0; i < 15; i++)
    {
        std::cout << urand() << ",";
    }
    std::cout << std::endl;
}