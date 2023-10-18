#include <iostream>
#include <bitset>
#include <random>
class URandom
{
    //size_t rand_check;
    std::bitset<10> bs;
    bool recycle;
    std::mt19937 randgen{std::random_device{}()};
    std::uniform_int_distribution <int> dist{0,9};
    public:
    URandom (bool recycle = false) : recycle(recycle)
    {
        // bs.set(5); // 5번째 비트만 1로
        bs.set(); // 모두 1로

    }
    int operator() ()
    {
        if (bs.none())
        {
            if (recycle)
            {
                bs.set();
            }
            else 
            {
                return -1;
            }
        }
        int k = -1;
        while(! bs.test(k=dist(randgen)));
        bs.reset(k); // k번째 bit를 0으로
        return k;
    }
};
URandom urand;
void ex01()
{
    for (int i = 0; i < 15; i++)
    {
        std::cout <<urand() << "," ;
    }
    std::cout << std::endl;
}


int main()
{
    ex01();
}

