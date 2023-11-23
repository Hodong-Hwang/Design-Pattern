#include <iostream>
// t상속이 아니라 포함을 사용한 기능을 추가하자.
// 이미 생성된 객체를 이용해서 쓰자.
// 생성된 객체를 가지고 쓰는 것.. 
//
class Image
{
    std::string image_path;

public:
    Image(const std::string& path) : image_path(path)
    {

    }
    void draw() const
    {
        std::cout << "draw : " <<image_path <<std::endl;
    }
};

// Load된 그림에 새로운 그림을 추가하고 싶다면?
class Frame 
{
private:
    Image& img;
public:
    Frame(Image& img_) : img(img_) {}
 void draw() const{
    std::cout <<"==============" <<std::endl;
    img.draw();
    std::cout << "=============" << std::endl;
 }
};


class Ballon 
{
private:
    Image& img;
public:
    Ballon(Image& img_) : img(img_) {}
 void draw() const{
    std::cout <<"===Bal==============" <<std::endl;
    img.draw();
    std::cout << "=============" << std::endl;
 }
};
int main()
{
    Image img("D:/");
    img.draw();
    Frame frame(img);
    frame.draw();
    Ballon bln(img);
    bln.draw();
    // 여기에 기능을 중첩할 수 있을까?
    //Ballon bln2(frame)

}