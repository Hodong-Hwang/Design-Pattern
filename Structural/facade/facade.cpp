// 소프트웨어 라이브러리를 쉽게 사용
// 라이브러리를 쉽게 이해
// 공통적인 작업에 대해 간편한 메소드
// 라이브러리를 사용하는 코드들을 좀 더 읽기 쉽게
// 바깥쪽의 코드가 라이브러리의 안쪽 코드에 의존하는 일을 감소
// 대부분의 바깥쪽의 코드가 퍼사드를 이용하기 때문에 시스템을 개발하는 데 있어 유연성이 향상
// 퍼사드는 좋게 작성되지 않은 API의 집합을 하나의 좋게 작성된 API로 감싸준다.
// 래퍼(wrapper)가 특정 인터페이스를 준수해야 하며, 폴리모픽 기능을 지원해야 할 경우에는 어댑터 패턴을 쓴다.
//  단지 쉽고 단순한 인터페이스를 이용하고 싶을 경우에는 퍼사드를 쓴다.

// struct TableBuffer : IBuffer
// {
//     TableBuffer(vector<TableColumnSpec> spec, int totalHeight) { ... }

//     struct TableColumnSpec
//     {
//         string header;
//         int width;
//         enum class TableColumnAlignment
//         {
//             Left,
//             Center,
//             Right
//         } alignment;
//     }
// };

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Window.h"
#include "TextBuffer.h"
using namespace std;

class Console
{
public:
    static Console &instance()
    {
        static Console console;
        return console;
    }

    vector<shared_ptr<Window>> windows;

    // cannot make this static
    shared_ptr<Window> single(const string &title, uint8_t charsWide, uint8_t charsHigh)
    {
        auto w = make_shared<Window>(title, charsWide * charWidth, charsHigh * charHeight);
        auto buffer = make_shared<TextBuffer>(charsWide, charsHigh);
        w->buffers.push_back(buffer);
        auto viewport = make_shared<Viewport>(buffer);
        w->viewports.push_back(viewport);
        windows.push_back(w);
        return w;
    }

    shared_ptr<Window> multicolumn(const string &title, uint8_t columnCount, uint8_t columnWidth, uint8_t charsHigh)
    {
        auto w = make_shared<Window>(title, columnCount * columnWidth * charWidth, charsHigh * charHeight);
        for (uint8_t c = 0; c < columnCount; ++c)
        {
            auto buffer = make_shared<TextBuffer>(columnWidth, charsHigh);
            w->buffers.push_back(buffer);
            auto viewport = make_shared<Viewport>(buffer, buffer->get_size(), Point{}, Point{columnWidth * c, 0});
            w->viewports.push_back(viewport);
            windows.push_back(w);
        }
        return w;
    }

private:
    const int charWidth = 10, charHeight = 14;
    Console() {}
    Console(Console const &) = delete;
    void operator=(Console const &) = delete;
};


Console::Console(bool fullscreen, int char_width, int ­ char_height,
                 int width, int height, optional<Size> client_size)
{
    // 구현부 예:
    // 버퍼와 뷰포트를 함께 묶어 생성하여 적절한 컬렉션 객체에 담기
    // 이미지 텍스처 생성
    // 전체 화면 모드 여부에 맞추어 그리드 크기 계산
}