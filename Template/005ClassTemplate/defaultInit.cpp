template <typename T>
class Complex
{
    T re, im;
    public :
    Complex(T a={},T b={}): re(a),im(b){}

    // generic copy constructor 
    // Complex(const Complex<T>& c){}
    // Complex(const Complex<int>& c){}
    template <typename U>
    Complex(const Complex< U>& c);
    // private -> access 
    template <typename> friend class Complex;  
    T getReal() const;

    static int cnt;
    // member function tmeplate of class template
    template <typename U> T func(const U& c);

};

// Very Important Expression.
template<typename T> template<typename U>
T Complex<T>::func(const U& c)
{

}

template<typename T>
int Complex<T>::cnt = 0;

template<typename T>template<typename U>
Complex<T>::Complex(const Complex<U>& c) : re(c.re),im(c.im)
{

}
template<typename T>
T Complex<T>::getReal() const
{
    return re;
}

int main ()
{
    Complex<int> c1(1,1);
    Complex<int> c2=c1;
    Complex<double> c3;


}