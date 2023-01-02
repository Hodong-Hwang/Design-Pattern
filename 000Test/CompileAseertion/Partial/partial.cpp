class ModalDialog;
class MyController;
template <class Window, class controller>
class Widget{
    //generic implementation

};

template <> 
class Widget<ModalDialog, MyController> 
{ 
    //explicitly specialize 
}; 

// Partial specialization of Widget 
template <class Window> 
class Widget<Window, MyController> 
{ 
};

template<class ButtonArg>
class Button;

template <class ButtonArg> 
class Widget<Button<ButtonArg>, MyController> 
{ 
}; 

// Unfortunately, partial template specialization does not apply to functions—be they member or 
// nonmember—which somewhat reduces the flexibility and the granularity of what you can do. 

template <class T, class U> T Fun(U obj);
// template <class U> void Fun<void, U>(U obj);
template <class T> T Fun (ModalDialog obj);
int main()
{
    return 0;
}