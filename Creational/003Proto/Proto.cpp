#include <string>
#include <iostream>
using namespace std;
struct Address
{
    string street,city;
    int suite;
    Address(const string& street,const string& city, const int suite) : street{street},city{city},suite{suite}
    {}
    friend ostream& operator<<(ostream& os, const Address& obj)
    {
        return os
        << "street: " << obj.street
        << " city: " << obj.city
        << " suite: " << obj.suite;
    }
};

struct Contact{

    string name;
    Address* address;
    Contact() : name(nullptr), address(nullptr)
    {} // required for serialization
    Contact(string name, Address* address)
        : name{name}, address{address}
    {
        //this->address = new Address{ *address };
    }
    Contact(const Contact& other)
    : name{other.name}
    , address{ new Address{*other.address} }
    {
        address = new Address(
        other.address->street, 
        other.address->city, 
        other.address->suite
        );
    }

    Contact(const Contact& other) :name{other.name}
    {
        address = new Address(
            other.address->street,
            other.address->city,
            other.address->suite
        );
    }
    Contact& operator = (const Contact& other)
    {
        if(this==&other) return *this;
        name=other.name;
        address=other.address;
        return *this;
    }
    
};

void ex1()
{
    Contact worker{"",new Address{"123 East Dr","London",0}};
    Contact John {worker};
    John.name ="John Doe";
    John.address->suite=10;
}

//