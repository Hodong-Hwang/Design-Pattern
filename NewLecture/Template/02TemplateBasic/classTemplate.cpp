template <typename T> class Complex
{
    T re, im;
    public:
    // 명확하게 표시하는게 좋음 Complex<T>
    void foo(Complex c) // compiler가변환 -> void foo(Complex<T> c)
    {
        Complex c2; // Complex<T> c2;
    }
    Complex(T a={}, T= b{}): re(a),im(b) {};
    T getReal() const;
    static int cnt;
    //클래스 템플릿의 멤버함수 템플릿
    template <typename U> T func (const U& c)
};
// static 멤버변수 초기화
template <typename T> 
int Complex<T>::cnt =0;


template<typename T> template <typename U>
T Complex<T>::func(const U& c)
{

}

template <typename T>
T Complex<T>::getReal() const{
    return re;
}

// Error 
/*
void foo(Complex c)
{

}
*/

int main ()
{
    //Complex c1; //error
    Complex<int> c2; //ok
}