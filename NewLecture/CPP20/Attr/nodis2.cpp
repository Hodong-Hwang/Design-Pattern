

struct MyType
{
    // 임시객체 생성 방지.
    [[nodiscard]] MyType(int a, int b){}
};

enum class [[nodiscard]] ErrorCode{OK,Warning, CRITICAL,FATA};


ErrorCode foo() {return ErrorCode::CRITICAL;}


int main()
{
    auto ret =foo();
    // 생성자 앞엣
}