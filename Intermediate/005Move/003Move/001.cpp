
// std::move의 장점
// std::move() 지원 바업
// move 예외, 생성
// move 생성자 자동생성ㄱ ㅠ칙
// move를 지원하는 규칙
// move 구현


/// 단계적절차..

#include <iostream>
#include <string>

int main ()
{
    std::string s1 = "Partice make Perferct";
    std::string s2 = s1; // copy construct
    std::string s3 = "Partice make Perferct";
    std::string s4 = std::move(s3); // 동일한 주소에 있는 자원을 이용함. 그리고  s3의는 파괴함.(자원을)

    std::cout << s1 <<std::endl;
    std::cout << s2 <<std::endl;
    std::cout << s3 <<std::endl; // ""
    std::cout << s4 <<std::endl;

}