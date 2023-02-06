#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ChatRoom;

struct Person
{
  string name;
  ChatRoom* room = nullptr;

  Person(const string& name);
  void receive(const string& origin, const string& message);

 /// 채팅 룸의 모든 참여자에게 메시지를 전송한다.
  void say(const string& message) const;
  vector<string> chat_log;

 // pm()은 개인 메시지(Private Massage, PM) 
  void pm(const string& who, const string& message) const;

  // generated in IDE
  friend bool operator==(const Person& lhs, const Person& rhs)
  {
    return lhs.name == rhs.name;
  }

  friend bool operator!=(const Person& lhs, const Person& rhs)
  {
    return !(lhs == rhs);
  }
};


struct ChatRoom
{
  vector<Person*> people; // assume append-only

 // Chating Room join
  void join(Person* p);
  // broadcast()는 채팅 룸의 모든 참여자에게 메시지를 보낸다. 엄밀히 말하자면 보내는 사람 자기 자신에게는 보내지 않으므로 모든 참여자는 아니다.

  void broadcast(const string& origin, const string& message);
  void message(const string& origin, const string& who, const string& message);
};

void ChatRoom::broadcast(const string& origin, const string& message)
{
  for (auto p : people) 
    if (p->name != origin)
      p->receive(origin, message);
}

void ChatRoom::join(Person* p)
{
  string join_msg = p->name + " joins the chat";
  broadcast("room", join_msg);

  p->room = this;
  people.push_back(p);
}

void ChatRoom::message(const string& origin, const string& who, const string& message)
{
  auto target = find_if(begin(people), end(people), [&](const Person* p) { return p->name == who; });
  if (target != end(people))
  {
    (*target)->receive(origin, message);
  }
}

Person::Person(const string& name) : name(name)
{
}

void Person::receive(const string& origin, const string& message)
{
  string s{ origin + ": \"" + message + "\"" };
  cout << "[" << name << "'s chat session] " << s << "\n";
  chat_log.emplace_back(s);
}

void Person::say(const string& message) const
{
  room->broadcast(name, message);
}

void Person::pm(const string& who, const string& message) const
{
  room->message(name, who, message);
}
