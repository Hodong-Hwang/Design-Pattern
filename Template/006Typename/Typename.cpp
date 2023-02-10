
class Test
{
    public:
    enum {value =1 };
    static int value2;
    typedef int INT;
    using SHORT = short;
    class innerClass{};
};

// :: -> enum, static, typdef, using
int main ()
{
    int n1 =Test::value;
    int n2= Test::value2;
    Test::INT a;
    Test::SHORT b;
    Test::innerClass A{};
}