
#include <functional>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
struct Logger
{
    function<void()> func;
    string name;
    Logger(const function<void()> &func, const string &name)
        : func{func}, name{name}
    {
    }
    void operator()() const
    {
        cout << "Entering " << name << endl;
        func();
        cout << "Exiting " << name << endl;
    }
};

template <typename Func>
struct Logger2
{
    Func func;
    string name;

    Logger2(const Func &func, const string &name)
        : func{func}, name{name} {}

    void operator()() const
    {
        cout << "Entering " << name << endl;
        func();
        cout << "Exiting " << name << endl;
    }
};

template <typename R, typename... Args>
struct Logger3
{
    Logger3(function<R(Args...)> func, const string &name)
        : func{func},
          name{name}
    {
    }

    R operator()(Args... args)
    {
        cout << "Entering " << name << endl;
        R result = func(args...);
        cout << "Exiting " << name << endl;
        return result;
    }

    function<R(Args...)> func;
    string name;
};

// 위 코드에서 템플릿 인자 R은 리턴 값의 타입을 의미한다. 그리고 Args는 이미 여러 번 보았던 파라미터 팩이다.
//  이 데커레이터는 앞서와 마찬가지로 함수를 가지고 있다가 필요할 때 호출할 수 있게 해준다.
//  유일하게 다른 점은 operator()가 R 타입의 리턴 값을 가진다는 점이다. 즉, 리턴 값을 잃지 않고 받아낼 수 있다.

template <typename R, typename... Args>
auto make_logger3(R (*func)(Args...), const string &name)
{
    return Logger3<R(Args...)>(
        std::function<R(Args...)>(func),
        name);
}
double add(double a, double b)
{
    cout << a << "+" << b << "=" << (a + b) << endl;
    return a + b;
}
auto logged_add = make_logger3(add, "Add");
auto result = logged_add(2, 3);