#include <iostream>
// 공통적인 특징을 묶어서
// Decorator를 만들고. 
// 여기서 추가할 것을 만듦
struct Idraw
{
    virtual void draw() const =0;
    virtual ~Idraw(){};
};

class Decorator : public Idraw{
    Idraw* img;
public:
    Decorator(Idraw* img): img(img){}
    void draw() const override {img->draw();}
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
class Frame : public Decorator
{
public:
    Frame(Idraw* img_) : Decorator(img_) {}
 void draw() const{
    std::cout <<"=========== Frame ==============" <<std::endl;
    Decorator::draw();
    std::cout << "=========== Frame ==============" << std::endl;
 }
};


class Ballon : public Decorator
{
public:
    Ballon(Idraw* img_) : Decorator(img_) {}
 void draw() const{
    std::cout <<"==========Bal==============" <<std::endl;
    Decorator::draw();
 }
};


int main()
{
    Image img("D:/");
    img.draw();
    Frame frame(&img);
    Ballon bln(&frame);
    bln.draw();
}