#include <iostream>
#include <string>

// make interface and use it 

template <typename OutputPolicy, typename LanguagePolicy>
class HelloWorld : private OutputPolicy, private LanguagePolicy
{
    using OutputPolicy::print;
    using LanguagePolicy::message;

public:
    // Behaviour method
    void run() const
    {
        // Two policy methods
        print(message());
    }
};

class OutputPolicyWriteToCout
{
protected:
    template<typename MessageType>
    void print(MessageType const &message) const
    {
        std::cout << message << std::endl;
    }
};

class LanguagePolicyEnglish
{
protected:
    std::string message() const
    {
        return "Hello, World!";
    }
};

class LanguagePolicyGerman
{
protected:
    std::string message() const
    {
        return "Hallo Welt!";
    }
};

class LanguagePolicyKorea
{
protected:
    std::string message() const
    {
        return "Hello Korea";
    }
};

int main()
{
    /* 예 1 */
    typedef HelloWorld<OutputPolicyWriteToCout, LanguagePolicyEnglish> HelloWorldEnglish;

    HelloWorldEnglish hello_world;
    hello_world.run(); // prints "Hello, World!"

    /* 예 2
     *위와 같지만, 다른 언어를 출력하도록 하였다  */
    typedef HelloWorld<OutputPolicyWriteToCout, LanguagePolicyGerman> HelloWorldGerman;

    HelloWorldGerman hello_world2;
    hello_world2.run(); // prints "Hallo Welt!"

    typedef HelloWorld<OutputPolicyWriteToCout, LanguagePolicyKorea> HelloWorldKorea;
    HelloWorldKorea hello_world3;
    hello_world3.run();

}