# Factory Method
Factory method는 생성을 위한 디자인 패턴 방법이다.


만약, 2개의 좌표계를 골라야하는 상황이 발생한다면, 극좌표계 또는 Polar 좌표계 생성을 위해서 Enum class 생성이 필요로 하다.

이를 효율적으로 생성하기 위해서 Factory Method를 적용하면 좋다. 또한, 어떠한 솔버를 선택할 때에도 Factory Method를 이용하여 직관적인 클래스 생성을 할 수 있다.

## Factory
Build Process
```
g++ .\Factory.cpp
```

## InnerFactory

Inner Factory는 사용자에게, 해당 Factory를 이용하여 생성하라는 의도를 알려줄 수 있음. 이에 따라 생성자들 으 ㅣ관리가 이루어짐.

```
g++ .\Factory.cpp
```
```