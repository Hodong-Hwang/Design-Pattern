#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


int main ()
{
    list<int > s = {1,2,3,4,5};

    vector<int > s2 = {1,2,3,4,5};

    reverse(s.begin(),s.end());
    reverse(s2.begin(),s2.end());

    for (int i= 0; i<s.size(); i++)
    {
        cout << s2[i] <<endl; //only vector not list
    }
    for (auto it=s.begin();it!=s.end();it ++)
    {
        cout << *it<<endl; //only vector not list
    }
    for (auto& n : s) cout << n <<endl;
}