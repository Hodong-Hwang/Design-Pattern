class Vector
{
    public:
    // 생성자가 암시적 변환이 안됨.
    explicit Vector(int size){};
    //잘 판단해서 써주어야함.
};

class Machine
{
    int data=10;
    bool state = true;
    public:
    /// if 문에서 사용할 수 는 있음. -> safe bool
    /// bool b1 = m // error
    /// bool b2 = static_cast<bool>(m)
    explicit operator bool () {return state;} 
};

void foo(Vector v){}

int main ()
{
    Vector v1(3);
    Vector v2=3; //error
    Vector v3{3};
    Vector v4={3};//error

    v1=3;//error
    foo(3);//error
    Machine m;
    if (m)
    {

    }
}