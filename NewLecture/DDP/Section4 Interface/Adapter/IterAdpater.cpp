#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> s={1,2,3,4,1,3,2};
    auto first =s.begin();
    auto second = s.end();

    // REverse는 ㅁ반대로 수행되는 iterator임.
    std::reverse_iterator first(s.end());
    std::reverse_iterator last(s.begin());

    auto ret = std::find(first,last,3);
    // ITL부터 다시함 (adapter 3부터)
}