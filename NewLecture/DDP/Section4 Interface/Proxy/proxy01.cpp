// 다른객체에 접근하기 위한 대리역할을 하는객체
#include <iostream>
class Image{
    std::string name;
    public:
    Image (const std::string& name) : name(name)
    {
        std::cout <<"open" << name << "\n";
    }
    void draw() {std::cout << "draw" << name <<"\n";}
    int width( ) const {return 100;}
    int height( ) const {return 100;}
};
// 바로 만들지 말고, draw할 경우에만 ㄱ객체만 생성하고, 크기정보 할때는 굳이 안만들어 도 된다.
class ImageProxy{
    std::string name;
    Image* img =nullptr;
public:
    ImageProxy(const std::string& name) : name(name){}
    void draw()
    {
        if (img==nullptr)
        {
            img =new Image(name);
        }
        img->draw();
    }
    int width( ) const {return 100;}
    int height( ) const {return 100;}
    };
int main()
{
    // 이미지 생성을 꼭 필요한 생성에서 진행함
    // 지연된 생성
    // 보안의 추가
    // 기능의 추가 (로그 기록)
    // 원격지 서버에 대한 대행자.
    // Decorator와 다른점은 인터페이스가 다르게 가능함.
    // Image에 접근하기 위한 대행자를 만든 것임.
    ImageProxy* img = new ImageProxy("C:/1.png");
    int w=img->width();

    img->draw();

}