// local classes cannot define static member variables
//cannot access nonstatic local variables.
//What makes local classes truly interesting is that you can use them in templatefunctions

// Local classes defined inside template functions can use the template parameters of the enclosing function.
class Interface 
{ 
public: 
 virtual void Fun() = 0;
}; 

//Local classes do have a unique feature, though: They are final. Outside users cannot derive from a class 
// hidden in a function. Without local classes, you'd have to add an unnamed namespace in a separate 
// translation unit. Chapter 11 uses local classes to create trampoline functions.
template <class T, class P> 
Interface* MakeAdapter(const T& obj, const P& arg) 
{ 
    class Local : public Interface 
    { 
    public: 
    Local(const T& obj, const P& arg) : obj_(obj), arg_(arg) {} 
    virtual void Fun() 
    { 
    obj_.Call(arg_); 
    } 
    private: 
    T obj_; 
    P arg_; 
    }; 
 return new Local(obj, arg); 
} 
// akeAdapter implements an interface on the fly with the help of a local class