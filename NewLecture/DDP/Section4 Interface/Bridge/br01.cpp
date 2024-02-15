
// 구현이 update 되면 사용자 코드도 모두 변경되어야 한다.
// 이를 독립적으로 Update하려면 어찌해야할까
// 사용자들이 계층을 직접사용하면, 결합도가 높아짐.
// 사용자가 사용하는 계층 -> 기능을 구현한 계층
// Update가 된다고 하더라도, abstarction을 이용하여 사용하여 건너감.
// user->abstraction ->implementation.
// 추상과 구현을 분리하여 각각을 독립적으로 변형할 수 있게 한다.

#include <iostream>

struct IMP3
{
    virtual void play()=0;
    virtual void stop()=0;
    virtual ~IMP3(){}
};

class IPod :public IMP3
{
    public:
    void play(){std::cout<<"Play Mpe With IPOD" <<std::endl;}
    void stop() {std::cout<<"stop"<<std::endl;}
};

class People
{
    void use(IMP3* p)
    {
        p->play();
        p->stop();
        p->play_one_minute();
    }
};
