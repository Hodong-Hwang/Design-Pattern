#include <string>
#include <vector>
#include <algorithm>
#include <bitset>	
using namespace std;


void Check(vector<int>& cards,bitset<100>& cardCheck, vector<int>& temp,int n)
{
    if (cardCheck[n-1] == 1)
    {
        return;
    }
    int input{ cards[n-1] };
    temp.push_back(input);
    cardCheck[n-1] = 1;
    Check(cards, cardCheck, temp, input);
}

int solution(vector<int> cards) {
    bitset<100> cardCheck;
    vector<int> nums;
    vector<int> temp;
    int answer = 0 ;
    for (int i = 1; i <= cards.size(); i++)
    {
        if (!cardCheck[i])
        {
            Check(cards, cardCheck, temp, i);
            nums.push_back(static_cast<int>(temp.size()));
        }
        temp.clear();
    }
    sort(nums.begin(), nums.end(), greater<int>());
    answer = nums[0] * nums[1];
    return answer;
}


vector<bool> visited;
void Check(int start,vector<int> cards,vector<int>& tmp)
{
    if(visited[start])
        return;
    visited[start] = true;
    tmp.push_back(start+1);
    int next = cards[start];
    Check(next-1,cards,tmp);
}

int solution(vector<int> cards) {
    int answer = 0;

    int maxVal = 0;

    for(int i=0;i<cards.size();i++)
    {
        vector<int> group1;
        visited = vector<bool>(cards.size(), false);

        Check(i,cards,group1);
        for(int j=0;j<cards.size();j++)
        {
            vector<int> group2;
            if(i==j || visited[j])
                continue;
            Check(j,cards,group2);
        int _size = group1.size() * group2.size();
        maxVal = max(maxVal,_size);
        }
    }

    answer = maxVal;
    return answer;
}