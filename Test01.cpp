#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> my_map;
    volatile std::unordered_map<volatile int, std::string,std::hash<volatile int>> volatile_map;
    

    // Access the value associated with key 2
   // std::string& value = const_cast<std::unordered_map<int, std::string>&>(volatile_map)[2];

    // Modify the value
    //value = "new value";

    // Print the new value
   // std::cout << my_map[2] << std::endl; // Prints "new value"
    return 0;
}