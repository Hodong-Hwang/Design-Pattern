template <typename T> class Complex
{
    T re, im;
    public:
    Complex(T a={}, T= b{}): re(a),im(b) {};
    // Copy Constructor -> 자신과 동일한 타입만 인자로 받음
    Complex(const Complex<T>& c){} // complex 자기자신
    //generic Copy constructor Smart Poninter에서 많이사용함.
    template <typename U>
    Complex(const Complex<U>& c);

    template <typename> friend class Complex; // 모든 typename에 대해서 friend선언해줌.


};

// private에 있는경우 오류가 발생함.

template <typename T> template <typename U>
Complex<T>::Complex(const Complex<U>& c) : re(c.re),im(c.im)
{

}
int main()
{
    Complex<int> c1(1,1);
    Complex<int> c2=c1; //ok
    Complex<double> c3=c1; //error
}