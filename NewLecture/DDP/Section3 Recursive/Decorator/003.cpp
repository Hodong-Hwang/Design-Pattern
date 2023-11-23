#include <iostream>
// 여기에 기능을 중첩할 수 있을까?
//Ballon bln2(frame)
// 공통으로 받기 위한 공통의 Interface를 생성해주어야함.
// Idraw를 만들어서 이를 상속 받아서 ㅅ만드는 것을함.
// 객체와 기능추가는 공통의 인터ㅠ페이스가 필요함.
struct Idraw
{
    virtual void draw() const =0;
    virtual ~Idraw(){};
};

class Image : public Idraw
{
    std::string image_path;

public:
    Image(const std::string& path) : image_path(path)
    {

    }
    void draw() const override
    {
        std::cout << "draw : " <<image_path <<std::endl;
    }
};

// Load된 그림에 새로운 그림을 추가하고 싶다면?
class Frame : public Idraw
{
private:
    Idraw& img;
public:
    Frame(Idraw& img_) : img(img_) {}
 void draw() const{
    std::cout <<"=========== Frame ==============" <<std::endl;
    img.draw();
    std::cout << "=========== Frame ==============" << std::endl;
 }
};


class Ballon : public Idraw
{
private:
    Idraw& img;
public:
    Ballon(Idraw& img_) : img(img_) {}
 void draw() const{
    std::cout <<"===Bal==============" <<std::endl;
    img.draw();
 }
};
int main()
{
    Image img("D:/");
    img.draw();
    Frame frame(img);
    Ballon bln(frame);
    bln.draw();


}