// Bar 객체와 그 멤버들을 네트워크로 연결된 원격의 다른 컴퓨터에 옮기는 것으로 설계 차원의 결정이 되었다고 하자.
// 그렇게 하기 위해 커뮤니케이션 프록시가 필요하다.

struct Pingable
{
    virtual wstring ping(const wstring &message) = 0;
};

struct Pong : Pingable
{
    wstring ping(const wstring &message) override
    {
        return message + L" pong";
    }
};

// 이 코드에서 ostringstream&를 사용하지 않고 매 응답마다 새로운 문자열을 생성하고 있다는 점을 눈여겨보자. 이러한 API는 웹서비스의 동작 방식을 따라 한 것이다.
// ostringstream, sstringstream...

void tryit(Pingable &pp)
{
    wcout << pp.ping(L"ping") << "\n";
}

Pong pp;
for (int i = 0; i < 3; ++i)
{
    tryit(pp);
}