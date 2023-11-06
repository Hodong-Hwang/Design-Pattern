#include <iostream>
// 문자열에서 문자 검색
// 문자에서 -> \0 만날때 까지 검색하는 것임.
// 널문자도 검색에서 포함되고, 검색 실패시 nullpoint를 return함.
// 전체문자열을 모두 검색하기에 부분 문자열만 검색하도록 하자.
// begin, end 개념이 들어옴.

// [first,last)
// Character-> 모든 Type에배열로 확장하자.
char* estrchr (char* first, char* last, char value)
{
    while (first!=last && *first !=value)
    {
        first++;
    }
    return first == last ? 0: first;

}
int main()
{
    char s[]="abcdefg";
    char* p =estrchr(s,s+4,'c');
    if( p==0)
    {
        std::cout << "fail" << std::endl;
    }
    else
    {
        std::cout <<"sucess : " << * p <<std::endl;
    }
}