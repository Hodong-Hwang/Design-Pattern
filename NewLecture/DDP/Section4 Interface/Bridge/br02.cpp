// Update 사됐을 때 문제가 발생함.
// MP3->IMP3 를 이용하여
// MP3는 추상층이라 이용하며.
// pimpl이라고도 불림. pointer to implementation.
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

class MP3{
    IMP3* impl;
public:
    MP3(IMP3* p=nullptr) : impl(p)
    {
        if(impl==nullptr)
        {
            impl=new IPod;
        }
    }
    void play() {impl->play();}
    void stop() {impl->stop();}
    void play_one_minute(){
        play();
        std::cout <<"wait for 1 min." <<std::endl;
        stop();
    }
};

class People
{
    void use(MP3* p)
    {
        p->play();
        p->stop();
        p->play_one_minute();
    }
};
