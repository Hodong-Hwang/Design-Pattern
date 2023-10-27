

template <typename T>
concept bool LessThanComparable = requires (T a , T b)
{
    {a<b}->bool;
};


