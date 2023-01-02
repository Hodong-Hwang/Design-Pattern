
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string recommend_list(vector<string> vhistory, string keyword)
{
    for (const auto& history : vhistory)
    {
        if (history.find(keyword)!=string::npos) return history;
    }
    return "";
}

string recommendfromkeyword(vector<string> vhistory, string keyword)
{
    size_t pos = 0;
    size_t pos_empty = 0 ;
    for (const auto& history : vhistory)
    {
        pos = history.find(keyword);
        pos_empty = history.find(" ",pos);
        if (pos!=string::npos) return history.substr(pos,pos_empty);
    }
    return "";
}
void parsing_text()
{
    string str="java c c++ python";
    istringstream ss(str);
    string stringBuffer;
    vector<string> x;
    x.clear();
    //구분자가 , 이라면 getline(ss, stringBuffer, ',')쓰면됨
    while (getline(ss, stringBuffer, ' '))
    {
        x.push_back(stringBuffer);
        cout<<stringBuffer<<"\t";
    }
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<endl;
    }
    str="java,c,c++,python";
    size_t previous =0;
    size_t current=0;
    x.clear();
    current= str.find(',');
    while(current!=string::npos)
    {
        string substring=str.substr(previous,current-previous);
        x.push_back(substring);
        previous = current+1;
        current=str.find(',',previous);
    }
    x.push_back(str.substr(previous,current-previous));

    for(int i=0;i<x.size();i++){
        cout<<x[i]<<endl;
    }
}
void otheroption()
{
    string str1="a",str2="b";
    str1.append("b");
    cout << str1.compare(str2) <<endl;
    cout << str1 <<endl;
    str1.at(1)='c';
    cout << str1 <<endl;
    cout << (str1>str2) <<endl;
    str1.insert(str1.begin()+str1.size(),'d');
    cout << str1 <<endl;
    str1.pop_back();
    cout << str1 <<endl;
    str1.push_back('d'); // 'string'
    cout << str1 <<endl;
    str1.append("a"); // const char*
    cout << str1 <<endl;
}
int main()
{
    
    size_t pos = 0;
    
    vector<string> histroy;
    histroy.push_back("Hello, i am chemcial engineer");
    histroy.push_back("hello, i am Chemputer");
    string keyword = "Hello";

    string ans = recommend_list(histroy,keyword);
    cout << ans <<endl;
    ans = recommendfromkeyword(histroy,"He");
    cout << ans <<endl;
    
    // cout<<hex<<string::npos <<endl;
    parsing_text();
    // https://chbuljumeok1997.tistory.com/42
    otheroption();
    return 0;

}