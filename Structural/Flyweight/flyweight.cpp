// 플라이웨이트 패턴은 많은 수의 가벼운 임시 객체들을 “스마트 참조”로 사용하는 것을 말하며 그러한 객체들을 플라이웨이트라고 부른다. 
// 어떤 사람들은 토큰(token), 쿠키(cookie)라고 부르기도 한다. 
// 플라이웨이트는 대단히 많은 수의 매우 비슷한 객체들이 사용되어야 할 때 메모리 사용량을 절감하는 방법으로서 자주 사용된다.

// https://lee1535.tistory.com/106

#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>
using namespace boost;
using namespace flyweights;

// coloring in the console by-letter vs using ranges

// boost.flyweight  

// naive
typedef uint32_t key;

// mmorpg
struct User
{
  User(const string& first_name, const string& last_name)
    : first_name{add(first_name)}, last_name{add(last_name)}
  {
  }

  const string& get_first_name() const
  {
    return names.left.find(last_name)->second;
  }

  const string& get_last_name() const
  {
    return names.left.find(last_name)->second;
  }

  static void info()
  {
    for (auto entry : names.left)
    {
      cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
    }
  }

  friend ostream& operator<<(ostream& os, const User& obj)
  {
    return os
      << "first_name: " << obj.first_name << " " << obj.get_first_name()
      << " last_name: " << obj.last_name << " " << obj.get_last_name();
  }

protected:
// Main Point to realize bimap 
  static bimap<key, string> names;
  static int seed;

  static key add(const string& s)
  {
    auto it = names.right.find(s);
    if (it == names.right.end())
    {
      // add it
      key id = ++seed;
      names.insert({seed, s});
      return id;
    }
    return it->second;
  }
  key first_name, last_name;
};

int User::seed = 0;
bimap<key, string> User::names{};

void naive_flyweight()
{
  User john_doe{ "John", "Doe" };
  User jane_doe{ "Jane", "Doe" };

  cout << "John " << john_doe << endl;
  cout << "Jane " << jane_doe << endl;

  User::info();
}

struct User2
{
  flyweight<string> first_name, last_name;

  User2(const string &first_name, const string &last_name)
    : first_name(first_name),
      last_name(last_name) {}
};

void boost_flyweight()
{
  User2 user1{"John", "Smith"};
  User2 user2{"Jane", "Smith"};

  cout << user1.first_name << endl;

  cout << boolalpha
       << (&user1.first_name.get() == &user2.first_name.get()) << endl;
  cout << boolalpha
       << (&user1.last_name.get() == &user2.last_name.get()) << endl;
}

int main_()
{
  naive_flyweight();
  boost_flyweight();

  getchar();
  return 0;
}
