#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// using seconds = duration <int,ratio<1,1>>; // =using seconds = duration <int>;
// using minutes = duration <int,ratio<60,1>>;// =using seconds = duration <int,ratio<60>>;
// using hours = duration <int,ratio<3600,1>>; 
//using days <int,ratio<3600*24,1>>;

void ex1()
{
    hours h(1);
    minutes m(h);
    seconds s(h);

    cout << m.count() <<endl;
    cout << s.count() <<endl;

    //h2=s error
    hours h2= duration_cast<hours> (s);
    cout << h2.count() <<endl;
}

void ex2()
{
    seconds s1(3);
    seconds s3 =3s;
    seconds s4 =3min;
    cout <<s4.count() <<endl;
    seconds s5 =3min+40s;
    cout <<s5.count() <<endl;

   // this_thread::sleep_for(3s);
}

void ex3()
{
    system_clock::time_point tp = system_clock::now();
    nanoseconds ns = tp.time_since_epoch(); // 1970 1월 1일 0시로 기준
    cout << ns.count() <<endl;

    hours h = duration_cast<hours>(ns);
    cout << h.count() <<endl;

    time_t t = system_clock::to_time_t(tp);
    string s = ctime(&t);
    cout <<s << endl;
}

int main()
{
    ex1();
    ex2();
    ex3();
}