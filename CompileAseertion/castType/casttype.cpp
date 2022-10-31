#include <iostream>
#include <vector>
using namespace std;
template <class T, class U> 
class Conversion 
{ 
 typedef char Small; 
 class Big { char dummy[2]; }; 
 static Small Test(U); 
 static Big Test(...); 
 static T MakeT(); 
public: 
 enum { exists = sizeof(Test(MakeT())) == sizeof(Small) }; 
 enum { sameType = false };
}; 

// Note that although std::vector does implement a constructor taking a size_t, the conversion test returns 0 because that constructor is explicit.
int main() 
{ 
 using namespace std; 
 cout 
 << Conversion<double, int>::exists << ' ' 
 << Conversion<char, char*>::exists << ' ' 
 << Conversion<size_t, vector<int> >::exists << ' ';
} 