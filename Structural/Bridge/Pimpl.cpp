#include "Pimpl.h"
#include  <iostream>
struct Person::PersonImpl
{
    void greet(Person* p);
};

Person::Person() : impl(new PersonImpl){}
Person::~Person() {delete impl;}

// pass to greet into impl
void Person::greet()
{
    impl->greet(this);
}
void Person::PersonImpl::greet(Person* p)
{
    std::cout <<"hello" << p->name.c_str() <<std::endl;
}
// 여기까지가 Pimpl 관례의 기본적인 개괄이라고 할 수 있다. 

//  이제 남은 것은 왜 이렇게 하느냐? 이다. 왜 클래스를 이중으로 정의해서 포인터를 왔다 갔다 하는 것일까? 이 방식은 3가지 장점이 있다.

//  클래스 구현부의 상당 부분이 실제로 감춰질 수 있다. 만약 Person 클래스가 많은 수의 private/protected 멤버를 가진다면 헤더를 통해 모두 클라이언트에 노출된다. 
//  private/protected 한정자로 인해 실제 사용은 할 수 없지만 불필요하게 많은 정보가 노출되는 것은 피할 수가 없다. 
//  하지만 Pimpl 관례를 이용하면 꼭 필요한 public 인터페이스만 노출할 수 있다.

// 바이너리 호환성을 보증하기 쉬워진다. 숨겨진 구현 클래스에 대한 수정은 바이너리 호환성에 영향을 미치지 않는다.

// 헤더 파일이 멤버 선언에 필요한 헤더들만 인클루드하게 할 수 있다. 즉
// , 구현부 때문에 클라이언트에서는 필요 없는 헤더까지 인클루드해야 하는 상황을 피할 수 있다. 
// 예를 들어 Person이 private 멤버로 vector<string>를 가진다고 하자. 어쩔 수 없이 Person.h 파일 안에서 #include <vector>와 #include <string>을 해야 한다. 
// 그리고 Person.h를 사용하는 모든 사용자는 강제로 <vector>와 <string>을 인클루드하게 된다. 하지만 Pimpl 관례를 이용하면 Person.cpp에서만 해당 헤더들을 인클루드하면 된다.
// 이러한 장점들은 깨끗하고 안정적인(자주 바뀌지 않는) 헤더를 유지할 수 있게 해준다. 컴파일 소요 시간이 줄어드는 것은 덤이다. 
// 디자인 패턴 관점에서는 Pimpl을 브릿지 패턴의 좋은 예로 볼 수 있다. 위 예에서는 멤버 변수 pimpl이 불투명 포인터이다. 
// 즉, 포인터의 상세 사항이 숨겨져 있다. 이 포인터는 공개용 인터페이스와 숨겨야 할 .cpp 파일의 세부 구현을 연결하는 다리(브릿지) 역할을 한다.