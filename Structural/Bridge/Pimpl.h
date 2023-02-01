#include <string>
// Pimpl Custom -> pointer to implementation
struct Person
{
    std::string name;
    void greet();
    Person();
    ~Person();

    class PersonImpl;
    PersonImpl *impl;
    // PersonImpl-is defined in cpp file.
    /* data */
};
