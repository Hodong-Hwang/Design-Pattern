/*
객체에 동적으로 서비스 추가 가능
상속을 사용해서 서비스를 추가하는 것 보다 유연한 방법으로 새로운 서비스 추가
추가하는 것이 중요한 개념임
*/
#include <iostream>
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
class Frame :public Image
{
private:
    /* data */
public:
 using Image::Image;
 void draw() const{
    std::cout <<"==============" <<std::endl;
    Image::draw();
    std::cout << "=============" << std::endl;
 }
};

// 이거는 객체가 아닌 클래스게 기능을 추가한 것이다.
// 여러개의 서비스를 중복해서 추가하기 어렵다.
// 즉-> 서비스를 여러개를 동시에 추가하기 위한 과정이 필요하다.

int main()
{
    Image img("D:/");
    img.draw();
    Frame frame("DDDD");
    frame.draw();
}