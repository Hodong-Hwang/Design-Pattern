// decltype과 auto로 인하여 first_argument_type, second_argument_type, result_type이 type def로 정의되어 있음.

template <typename T = void>
struct less
{
    bool operator() (const T& a, const T& b)
    {
        return a<b;
    }
};

template<>
struct less<void>
{
    template <typename T1,typename T2 >
    constexpr auto operator() (const T1& a, const T2& b) const
    {
        return std::forward<T1>(a)<std::forward<T2>(b);
    }
};


int main()
{

    less<void> f3;
    less<> f4;
    less f5;

}