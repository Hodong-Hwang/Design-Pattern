
template <typename TYPE> class SingleTon
{
    protected : 
    SingleTon(){}
    SingleTon(const SingleTon&) =delete;
    void operator=(const SingleTon&)=delete;

    public:
    static TYPE& getInstance()
    {
        static TYPE instance;
        return instance;
    }
};


class Mouse : public SingleTon<Mouse>
{

};

int main ()
{
    Mouse& m1=Mouse::getInstance();

}