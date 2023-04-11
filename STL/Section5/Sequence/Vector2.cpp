#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main ()
{
    vector<string> v;
    std::string s;
    fstream f("Vector2.cpp");
    while (getline(f,s))
        v.push_back(s);

    for (auto str: v)
        cout << str <<endl;
    
    reverse(begin(v),end(v));
    for (auto str: v)
        cout << str <<endl;
    reverse(begin(v),end(v));
    for (auto& str: v)

        cout << str <<endl;
    // 조건자 연산
    // replace_if 추가
}