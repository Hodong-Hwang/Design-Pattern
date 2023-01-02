template <typename T, bool isPolymorphic> 
struct NiftyContainerValueTraits 
{ 
 typedef T* ValueType; 
};

template <typename T> 
struct NiftyContainerValueTraits<T, false> 
{ 
 typedef T ValueType; 
}; 


template <typename T, bool isPolymorphic> 
class NiftyContainer 
{ 
 typedef NiftyContainerValueTraits<T, isPolymorphic> Traits; 
 typedef typename Traits::ValueType ValueType; 
}; 

template <bool flag, typename T, typename U> 
struct Select 
{ 
    typedef T Result; 
};

template <typename T, typename U> 
struct Select<false, T, U> 
{ 
    typedef U Result; 
};

template <typename T, bool isPolymorphic> 
class NiftyContainer 
{ 
 typedef typename Select<isPolymorphic, T*, T>::Result ValueType; 
 ValueType a;
}; 
