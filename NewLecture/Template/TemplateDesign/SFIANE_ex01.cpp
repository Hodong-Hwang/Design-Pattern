
// Enable if

template <bool b, typename T=void>
 struct enable_if
{

};

template <typename T> //
struct enable_if <true,T>
{
    typedef T type;
};

int main()
{
    enable_if<true,int>::type t0; // T
    enable_if<true>::type* t0; // void *
    
    //enable_if<false>::type* t0; // error 발생/ 특수화가 되지 않았음.

}