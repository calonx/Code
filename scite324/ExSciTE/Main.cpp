
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>
#include <string>
#include <cassert>
#include <regex>

#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")

#include "Common.h"

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

using namespace PCommon;

const float s_dpiScaleX = 1;
const float s_dpiScaleY = 1;

enum EFontStyleFlags
{
    FONTSTYLE_ForeColor     = (1 << 0),
    FONTSTYLE_BackColor     = (1 << 1),
    FONTSTYLE_Italic        = (1 << 2),
    FONTSTYLE_Weighted      = (1 << 3),
    FONTSTYLE_Underline     = (1 << 4),
    FONTSTYLE_Strikethrough = (1 << 5),
};

struct SScopedStyle
{
    SScopedStyle() : styleFlags(), colorFore(), colorBack(), uWeight(0.5f) { }

    s32     styleFlags;
    Color4b colorFore;
    Color4b colorBack;
    f32     uWeight;
};

class CWindow
{
public:
    CWindow ();
    ~CWindow ();

    bool Initialize ();

    void Run ();

private:
    void CreateTextResources ();
    void EnsureDeviceResources ();

    void DiscardDeviceResources ();

    void Render ();
    void RenderText (const wchar * text, size_t count);

    LRESULT OnMessage (UINT msg, WPARAM wParam, LPARAM lParam);
    void OnResize (s32 width, s32 height);

    HWND                    m_hwnd;
    std::wstring            m_strText;

    IDWriteFactory *        m_pWriteFactory;
    IDWriteTextFormat *     m_pTextFormat;
    IDWriteTextLayout *     m_pTextLayout;

    ID2D1Factory *          m_pD2dFactory;
    ID2D1HwndRenderTarget * m_pRenderTarget;
    ID2D1SolidColorBrush *  m_pBlackBrush;
    ID2D1SolidColorBrush *  m_pGrayBrush;
};

CWindow::CWindow ()
  : m_hwnd(nullptr),
    m_strText(L"Hello,\nworld!"),
    m_pWriteFactory(nullptr),
    m_pTextFormat(nullptr),
    m_pTextLayout(nullptr),
    m_pD2dFactory(nullptr),
    m_pRenderTarget(nullptr),
    m_pBlackBrush(nullptr),
    m_pGrayBrush(nullptr)
{

}

CWindow::~CWindow ()
{
    CloseWindow(m_hwnd);
}

bool CWindow::Initialize ()
{
    CreateTextResources();

    WNDCLASSEX wcex;
    MemZero(&wcex);
    
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = sizeof(LONG_PTR);
    wcex.hInstance = HINST_THISCOMPONENT;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszClassName = L"ExSciTE";
    wcex.lpfnWndProc = [] (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) -> LRESULT
    {
        auto pWindow = reinterpret_cast<CWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        if (!pWindow)
            return DefWindowProc(hwnd, msg, wp, lp);
        return pWindow->OnMessage(msg, wp, lp);
    };
    
    if (!RegisterClassEx(&wcex))
        return false;

    m_hwnd = CreateWindow(
        L"ExSciTE",
        L"ExSciTE",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        512,
        512,
        NULL,
        NULL,
        HINST_THISCOMPONENT,
        this
    );

    SetWindowLongPtr(m_hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    ShowWindow(m_hwnd, SW_SHOWNORMAL);

    return true;
}

void CWindow::Run ()
{
    MSG msg;

    while (BOOL result = GetMessage(&msg, NULL, 0, 0))
    {
        if (result != -1)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}

void CWindow::CreateTextResources ()
{
    HRESULT result = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2dFactory);
    assert(SUCCEEDED(result));

    result = DWriteCreateFactory(
        DWRITE_FACTORY_TYPE_SHARED,
        __uuidof(IDWriteFactory),
        reinterpret_cast<IUnknown **>(&m_pWriteFactory)
    );
    assert(SUCCEEDED(result));

    result = m_pWriteFactory->CreateTextFormat(
        L"Consolas",
        NULL,
        DWRITE_FONT_WEIGHT_REGULAR,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        72.0f,
        L"en-us",
        &m_pTextFormat
    );
    assert(SUCCEEDED(result));

    //result = m_pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
    //assert(SUCCEEDED(result));

    //result = m_pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
    //assert(SUCCEEDED(result));
}

void CWindow::EnsureDeviceResources ()
{
    if (m_pRenderTarget)
        return;

    RECT rectClient;
    GetClientRect(m_hwnd, &rectClient);

    D2D1_SIZE_U size = D2D1::SizeU(
        rectClient.right  - rectClient.left,
        rectClient.bottom - rectClient.top
    );

    HRESULT result = m_pD2dFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(m_hwnd, size),
        &m_pRenderTarget
    );
    assert(SUCCEEDED(result));

    result = m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_pBlackBrush);
    assert(SUCCEEDED(result));

    result = m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Gray), &m_pGrayBrush);
    assert(SUCCEEDED(result));
}

void CWindow::DiscardDeviceResources ()
{
    Release(&m_pRenderTarget);
    Release(&m_pBlackBrush);
}

void CWindow::Render ()
{
    EnsureDeviceResources();

    m_pRenderTarget->BeginDraw();
    m_pRenderTarget->SetTransform(D2D1::IdentityMatrix());
    m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

    RenderText(m_strText.c_str(), m_strText.length());

    m_pRenderTarget->EndDraw();
}

void CWindow::RenderText (const wchar * text, size_t count)
{
    RECT rectClient;
    GetClientRect(m_hwnd, &rectClient);

    D2D1_RECT_F rectLayout = D2D1::RectF(
        static_cast<float>(rectClient.left)                     / s_dpiScaleX,
        static_cast<float>(rectClient.top)                      / s_dpiScaleY,
        static_cast<float>(rectClient.right - rectClient.left)  / s_dpiScaleX,
        static_cast<float>(rectClient.bottom - rectClient.top)  / s_dpiScaleY
    );

    IDWriteTextLayout * pTextLayout;
    m_pWriteFactory->CreateTextLayout(
        text,
        u32(count),
        m_pTextFormat,
        rectLayout.right,
        rectLayout.bottom,
        &pTextLayout
    );

    SScopedStyle style;
    style.styleFlags = FONTSTYLE_Italic | FONTSTYLE_ForeColor;
    style.colorFore = Color4b(128, 128, 128, 255);

    std::wregex reComment(L"(//.*)$", std::regex_constants::ECMAScript | std::regex_constants::icase);
    auto commentsBegin = std::wsregex_iterator(m_strText.begin(), m_strText.end(), reComment);
    auto commentsEnd = std::wsregex_iterator();

    for (auto i = commentsBegin; i != commentsEnd; ++i)
    {
        auto match = *i;
        DWRITE_TEXT_RANGE textRangeComment = { u32(match.position()), u32(match.length()) };
        pTextLayout->SetFontStyle(DWRITE_FONT_STYLE_ITALIC, textRangeComment);
        pTextLayout->SetDrawingEffect(m_pGrayBrush, textRangeComment);
    }

    m_pRenderTarget->DrawTextLayout(
        D2D1_POINT_2F(),
        pTextLayout,
        m_pBlackBrush
    );

    Release(&pTextLayout);

    //m_pRenderTarget->DrawRectangle();
}

LRESULT CWindow::OnMessage (UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CHAR:
        {
            wchar ch = wchar(wParam);
            if (isprint(ch))
                m_strText += ch;
            else if (ch == VK_RETURN)
                m_strText += L'\n';
            else if ((ch == VK_BACK) && (m_strText.length() > 0))
                m_strText.pop_back();
            else
                break;

            InvalidateRect(m_hwnd, NULL, true);
            return 0;
        }

        case WM_SIZE:
        {
            OnResize(LOWORD(lParam), HIWORD(lParam));
            return 0;
        }

        case WM_PAINT:
        case WM_DISPLAYCHANGE:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(m_hwnd, &ps);
            assert(hdc);

            Render();

            EndPaint(m_hwnd, &ps);
            return 0;
        }

        case WM_DESTROY:
        case WM_CLOSE:
        {
            PostQuitMessage(0);
            return 0;
        }
    }

    return DefWindowProc(m_hwnd, msg, wParam, lParam);
}

void CWindow::OnResize (s32 width, s32 height)
{
    if (!m_pRenderTarget)
        return;

    D2D1_SIZE_U size;
    size.width = width;
    size.height = height;
    m_pRenderTarget->Resize(size);
}

int WINAPI wWinMain (
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nCmdShow)
{
    HRESULT result = CoInitialize(NULL);

    if (FAILED(result))
        return EXIT_FAILURE;

    {
        CWindow window;

        if (!window.Initialize())
            return EXIT_FAILURE;

        window.Run();
    }

    CoUninitialize();

    return EXIT_SUCCESS;
}
