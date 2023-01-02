template <typename T> 
class TypeTraits 
{ 
private: 
template <class U> struct PointerTraits 
{ 
    enum { result = false }; 
    typedef NullType PointeeType; 
}; 

template <class U> struct PointerTraits<U*>
{ 
    enum { result = true }; 
    typedef U PointeeType; 
}; 
public: 
    enum { isPointer = PointerTraits<T>::result }; 
    typedef PointerTraits<T>::PointeeType PointeeType; 
};