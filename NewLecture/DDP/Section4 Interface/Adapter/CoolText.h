// Intent Clinent가 기대하는 구조체로 변환
#pragma once

#include <iostream>
#include <string>

class CoolText
{
private:
    std::string text;
    std::string font_name;
    std::size_t size;
    /* data */
public:
    CoolText(const std::string& text):text(text){}
    ~CoolText();
    void show() {std::cout << text <<std::endl;}
};
