#include <string>
#include <iostream>
class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

class Person
{
  // address
  std::string street_address, post_code, city;

  // employment
  std::string company_name, position;
  int annual_income = 0;

  Person()
  {
    std::cout << "Person created\n";
  }
  
public:
  ~Person()
  {
    std::cout << "Person destroyed\n";
  }

  static PersonBuilder create();

  Person(Person&& other)
    : street_address{move(other.street_address)},
      post_code{move(other.post_code)},
      city{move(other.city)},
      company_name{move(other.company_name)},
      position{move(other.position)},
      annual_income{other.annual_income}
  {
  }

  Person& operator=(Person&& other)
  {
    if (this == &other)
      return *this;
    street_address = move(other.street_address);
    post_code = move(other.post_code);
    city = move(other.city);
    company_name = move(other.company_name);
    position = move(other.position);
    annual_income = other.annual_income;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Person& obj)
  {
    return os
      << " street_address:" << obj.street_address <<"\n"
      << " post_code:" << obj.post_code <<"\n"
      << " city:" << obj.city <<"\n"
      << " company_name:" << obj.company_name <<"\n"
      << " position:" << obj.position <<"\n"
      << " annual_income:" << obj.annual_income <<"\n";
  }

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};

class PersonBuilderBase
{
protected:
  Person& person;
  explicit PersonBuilderBase(Person& person)
    : person{ person }
  {
  }
public:
  operator Person() const
  {
    std::cout <<"Person moved" <<std::endl;
    return std::move(person);
  }

  // builder facets

  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};

class PersonAddressBuilder : public PersonBuilderBase
{
  typedef PersonAddressBuilder Self;
public:
  explicit PersonAddressBuilder(Person& person)
  : PersonBuilderBase{person}
  {
    std::cout << "Person Addres Builder Created "<< std::endl;
  }
  ~PersonAddressBuilder()
  {
    std::cout << "Person Addres Builder Destroyed "<< std::endl;

  }

  Self& at(std::string street_address)
  {
    person.street_address = street_address;
    return *this;
  }

  Self& with_postcode(std::string post_code)
  {
    person.post_code = post_code;
    return *this;
  }

  Self& in(std::string city)
  {
    person.city = city;
    return *this;
  }
};
class PersonJobBuilder : public PersonBuilderBase
{
  typedef PersonJobBuilder Self;
public:
  explicit PersonJobBuilder(Person& person)
  : PersonBuilderBase { person }
  {
    std::cout << "Person Job Builder Created "<< std::endl;
  }
  ~PersonJobBuilder()
  {
    std::cout << "Person Job Builder Destroyed "<< std::endl;

  }

  Self& at(std::string company_name)
  {
    person.company_name = company_name;
    return *this;
  }

  Self& as_a(std::string position)
  {
    person.position = position;
    return *this;
  }

  Self& earning(int annual_income)
  {
    person.annual_income = annual_income;
    return *this;
  }
};



class PersonBuilder : public PersonBuilderBase
{
  Person p;
public:
  PersonBuilder(): PersonBuilderBase{p}
  {
    std::cout << "Person Builder Created" <<std::endl;
  }

};

PersonBuilder Person::create()
{
  return PersonBuilder{};
}
PersonAddressBuilder PersonBuilderBase::lives() const
{
  return PersonAddressBuilder{ person };
}

PersonJobBuilder PersonBuilderBase::works() const
{
  return PersonJobBuilder{ person };
}


int main()
{
    // Person -> Person Builder -> Addres Builder ->JobBuilder -> Person std::move  -> destoyed builders.. 
    Person p = Person::create()
    .lives().at("123 London Road")
    .with_postcode("15001")
    .in("London")
    .works().at("Seuol")
    .as_a("Researcher and Developer")
    .earning(10e6);
    std::cout <<p <<std::endl;

    
    return 0;
}