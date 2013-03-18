//==============================================================================
// Graphics.cpp
// Paul Marden (2/12/2012)
//==============================================================================

#include "Pch.h"

namespace Gphx {

//==============================================================================
// VertexDesc
//==============================================================================

template<typename T>
struct VertexDesc {
    static const D3D11_INPUT_ELEMENT_DESC Layout[];
};

template<>
const D3D11_INPUT_ELEMENT_DESC VertexDesc<VertexSimple>::Layout[] = {
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
};


//==============================================================================
// CWindow methods
//==============================================================================

//==============================================================================
CWindow::CWindow (HWND hwnd, const Rect4i & clientRect) : m_hwnd(hwnd), m_rect(clientRect) {
    SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}

//==============================================================================
CWindow::~CWindow () {
    if (m_hwnd)
        DestroyWindow(m_hwnd);
}

//==============================================================================
bool CWindow::Pump () {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT)
            return false;
            
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}

//==============================================================================
/*static*/ CWindow * CWindow::GetWindowForHwnd (HWND hwnd) {
    LONG_PTR data = GetWindowLongPtr(hwnd, GWLP_USERDATA);
    return reinterpret_cast<CWindow *>(data);
}

//==============================================================================
/*static*/ CWindow * CWindow::Create (const wchar title[], const Rect4i & rect) {
    const wchar * const windowClassName = L"GraphicsWindow";
    HINSTANCE instance = GetModuleHandle(NULL);
    {
        WNDCLASSEX wc;
        
        ZeroPtr(&wc);
        
        wc.cbSize           = sizeof(wc);
        wc.style            = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc      = CWindow::WindowProc;
        wc.hInstance        = instance;
        wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
        //wc.hbrBackground    = (HBRUSH)COLOR_WINDOW;
        wc.lpszClassName    = windowClassName;
        
        RegisterClassEx(&wc);
    }
    
    const DWORD windowStyle = WS_OVERLAPPEDWINDOW;
    RECT windowRect = { rect.x0, rect.y0, rect.x1, rect.y1 };
    AdjustWindowRect(&windowRect, windowStyle, FALSE);
    
    int xOff = rect.x0 - windowRect.left;
    int yOff = rect.y0 - windowRect.top;
    windowRect.left   += xOff;
    windowRect.right  += xOff;
    windowRect.top    += yOff;
    windowRect.bottom += yOff;
    
    HWND hwnd = CreateWindowEx(
        0,
        windowClassName,
        title,
        windowStyle,
        windowRect.left,
        windowRect.top,
        windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top,
        NULL,
        NULL,
        instance,
        NULL
    );
    if (!hwnd)
        return NULL;
    ShowWindow(hwnd, SW_SHOW);
    
    CWindow * window = new CWindow(hwnd, rect);
    return window;
}

//==============================================================================
LRESULT CALLBACK CWindow::WindowProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    
    return 0;
}


//==============================================================================
// CGeometryBuffer methods
//==============================================================================

//==============================================================================
template<typename V>
CGeometryBuffer<V>::CGeometryBuffer (
    ID3D11Buffer *          vertexBuffer,
    uint                    vertexCount,
    ID3D11Buffer *          indexBuffer,
    uint                    indexCount,
    ID3D11DeviceContext *   context
) : m_vertexBuffer(vertexBuffer),
    m_vertexCount(vertexCount),
    m_indexBuffer(indexBuffer),
    m_indexCount(indexCount),
    m_context(context)
{
    
}

//==============================================================================
template<typename V>
void CGeometryBuffer<V>::SetVertices (uint count, const V vertices[]) {
    assert(count == m_vertexCount);

    D3D11_MAPPED_SUBRESOURCE resource;
    const int subresourceId = 0;
    m_context->Map(m_vertexBuffer, subresourceId, D3D11_MAP_WRITE_DISCARD, 0, &resource);
    MemCopy(resource.pData, vertices, count);
    m_context->Unmap(m_vertexBuffer, subresourceId);
}

//==============================================================================
template<typename V>
void CGeometryBuffer<V>::Use () {
    const uint stride = sizeof(V);
    const uint indexOffset = 0;
    const uint vertexOffset = 0;
    m_context->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R16_UINT, indexOffset);
    m_context->IASetVertexBuffers(0, 1, &m_vertexBuffer.Ref(), &stride, &vertexOffset);
    m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

//==============================================================================
template<typename V>
void CGeometryBuffer<V>::Render () {
    m_context->DrawIndexed(m_indexCount, 0, 0);
}


//==============================================================================
// CModel methods
//==============================================================================

//==============================================================================
void CModel::Render () {
    m_buffer->Use();
    m_buffer->Render();
}


//==============================================================================
// CGraphics methods
//==============================================================================

//==============================================================================
/*static*/ CGraphics * CGraphics::Create (const wchar title[], const Rect4i & rect) {
    CGraphics * graphics = new CGraphics();
    graphics->Initialize(title, rect);
    return graphics;
}

//==============================================================================
void CGraphics::Initialize (const wchar title[], const Rect4i & rect) {
    m_window = CWindow::Create(title, rect);
    assert(m_window);

    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    
    ZeroPtr(&swapChainDesc);
    
    swapChainDesc.BufferCount = 1;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferDesc.Width  = rect.Width();
    swapChainDesc.BufferDesc.Height = rect.Height();
    swapChainDesc.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.OutputWindow      = m_window->GetHwnd();
    swapChainDesc.SampleDesc.Count  = 4;
    swapChainDesc.Windowed          = TRUE;
    swapChainDesc.Flags             = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    
    uint devFlags = 0;
    
    bool debug = false;
    if (debug)
        devFlags |= D3D11_CREATE_DEVICE_DEBUG;
    
    D3D11CreateDeviceAndSwapChain(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        devFlags,
        NULL,
        0,
        D3D11_SDK_VERSION,
        &swapChainDesc,
        &m_swapChain,
        &m_device,
        NULL,
        &m_context
    );
    
    InitializeRenderTargets();
    SetViewport(rect);
    InitializePipeline();
}

//==============================================================================
void CGraphics::InitializeRenderTargets () {
    // Create and set render-target
    ID3D11Texture2D * backBuffer;
    m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *)&backBuffer);
    
    m_device->CreateRenderTargetView(backBuffer, NULL, &m_renderTarget);
    backBuffer->Release();
    
    m_context->OMSetRenderTargets(1, &m_renderTarget, NULL);
}

//==============================================================================
void CGraphics::InitializePipeline () {
    ID3D10Blob * vertexShader;
    ID3D10Blob * pixelShader;
    HRESULT result;
    result = D3DX11CompileFromFile(L"shaders.hlsl", NULL, NULL, "VShader", "vs_4_1", 0, 0, NULL, &vertexShader, NULL, NULL);
    assert(SUCCEEDED(result));
    result = D3DX11CompileFromFile(L"shaders.hlsl", NULL, NULL, "PShader", "ps_4_1", 0, 0, NULL, &pixelShader,  NULL, NULL);
    assert(SUCCEEDED(result));
    
    m_device->CreateVertexShader(vertexShader->GetBufferPointer(), vertexShader->GetBufferSize(), NULL, &m_vertexShader);
    m_device->CreatePixelShader(  pixelShader->GetBufferPointer(),  pixelShader->GetBufferSize(), NULL, &m_pixelShader);
    
    m_context->VSSetShader(m_vertexShader, NULL, 0);
    m_context->PSSetShader(m_pixelShader,  NULL, 0);
    
    m_device->CreateInputLayout(
        VertexDesc<VertexSimple>::Layout,
        arrsize(VertexDesc<VertexSimple>::Layout),
        vertexShader->GetBufferPointer(),
        vertexShader->GetBufferSize(),
        &m_inputLayout
    );
    m_context->IASetInputLayout(m_inputLayout);
    
    TReleaseSafe(&vertexShader);
    TReleaseSafe(&pixelShader);
}

//==============================================================================
IModel * CGraphics::CreateModel (
    const VertexSimple  vertices[],
    uint                vertexCount,
    const ushort        indices[],
    uint                indexCount
) {
    ID3D11Buffer * vertexBuffer;
    ID3D11Buffer * indexBuffer;
    
    {
        D3D11_BUFFER_DESC      vertexDesc;
	    D3D11_SUBRESOURCE_DATA vertexData;
        ZeroPtr(&vertexDesc);
        ZeroPtr(&vertexData);
        
        vertexDesc.Usage          = D3D11_USAGE_DEFAULT;
        vertexDesc.ByteWidth      = sizeof(VertexSimple) * vertexCount;
        vertexDesc.BindFlags      = D3D11_BIND_VERTEX_BUFFER;
        
        vertexData.pSysMem = vertices;
        
        HRESULT result = m_device->CreateBuffer(&vertexDesc, &vertexData, &vertexBuffer);
        assert(!FAILED(result));
    }
    
    {
        D3D11_BUFFER_DESC      indexDesc;
	    D3D11_SUBRESOURCE_DATA indexData;
        ZeroPtr(&indexDesc);
        ZeroPtr(&indexData);
        
        indexDesc.Usage          = D3D11_USAGE_DEFAULT;
        indexDesc.ByteWidth      = sizeof(indices[0]) * indexCount;
        indexDesc.BindFlags      = D3D11_BIND_INDEX_BUFFER;
        
        indexData.pSysMem = indices;
        
        HRESULT result = m_device->CreateBuffer(&indexDesc, &indexData, &indexBuffer);
        assert(!FAILED(result));
    }
    
    CGeometryBuffer<VertexSimple> * buffer = new CGeometryBuffer<VertexSimple>(
        vertexBuffer,
        vertexCount,
        indexBuffer,
        indexCount,
        m_context
    );
    
    CModel * model = new CModel(buffer);
    return model;
}

//==============================================================================
void CGraphics::SetViewport (const Rect4i & rect) {
    D3D11_VIEWPORT viewport;
    ZeroPtr(&viewport);
    
    viewport.TopLeftX = (float)rect.x0;
    viewport.TopLeftY = (float)rect.y0;
    viewport.Width    = (float)rect.Width();
    viewport.Height   = (float)rect.Height();
    
    m_context->RSSetViewports(1, &viewport);
}

//==============================================================================
void CGraphics::Destroy () {
    m_swapChain->SetFullscreenState(FALSE, NULL);

    TReleaseSafe(&m_inputLayout);
    TReleaseSafe(&m_pixelShader);
    TReleaseSafe(&m_vertexShader);
    TReleaseSafe(&m_swapChain);
    TReleaseSafe(&m_renderTarget);
    TReleaseSafe(&m_device);
    TReleaseSafe(&m_context);
    
    delete m_window;
}
//==============================================================================
bool CGraphics::Advance () {
    return m_window->Pump();
}

//==============================================================================
void CGraphics::RenderBegin () {
    const D3DXCOLOR ClearColor(0.0f, 0.2f, 0.4f, 1.0f);
    m_context->ClearRenderTargetView(m_renderTarget, ClearColor);
}
    
//==============================================================================
void CGraphics::RenderEnd () {
    m_swapChain->Present(0, 0);
}

//==============================================================================
IGraphics * GraphicsCreate (const wchar title[], const Rect4i & rect) {
    return CGraphics::Create(title, rect);
}

//==============================================================================
inline void SetIndex (ushort ** buffer, ushort a, ushort b, ushort c) {
    ushort * ptr = *buffer;
    ptr[0] = a;
    ptr[1] = b;
    ptr[2] = c;
    *buffer += 3;
}

//==============================================================================
void GenerateBox (
    VertexSimple *  vertices,
    unsigned        vertexCount,
    ushort *        indices,
    unsigned        indexCount
) {
    assert(vertexCount >= BOX_VERTEX_COUNT);
    assert(indexCount  >= BOX_INDEX_COUNT);
    
    enum {
        LEFT__FRONT_BOTTOM,
        RIGHT_FRONT_BOTTOM,
        LEFT__BACK__BOTTOM,
        RIGHT_BACK__BOTTOM,
        LEFT__FRONT_TOP,
        RIGHT_FRONT_TOP,
        LEFT__BACK__TOP,
        RIGHT_BACK__TOP,
    };
    
    vertices[LEFT__FRONT_BOTTOM] = VertexSimple(0, 0, 0, Color4f(1, 0, 0, 1));
    vertices[RIGHT_FRONT_BOTTOM] = VertexSimple(1, 0, 0, Color4f(0, 1, 0, 1));
    vertices[LEFT__BACK__BOTTOM] = VertexSimple(0, 1, 0, Color4f(0, 0, 1, 1));
    vertices[RIGHT_BACK__BOTTOM] = VertexSimple(1, 1, 0, Color4f(1, 0, 1, 1));
    vertices[LEFT__FRONT_TOP]    = VertexSimple(0, 0, 1, Color4f(1, 1, 0, 1));
    vertices[RIGHT_FRONT_TOP]    = VertexSimple(1, 0, 1, Color4f(0, 1, 1, 1));
    vertices[LEFT__BACK__TOP]    = VertexSimple(0, 1, 1, Color4f(1, 1, 1, 1));
    vertices[RIGHT_BACK__TOP]    = VertexSimple(1, 1, 1, Color4f(0, 0, 0, 1));
    
    // bottom
    SetIndex(&indices, LEFT__FRONT_BOTTOM, LEFT__BACK__BOTTOM, RIGHT_BACK__BOTTOM);
    SetIndex(&indices, LEFT__FRONT_BOTTOM, RIGHT_BACK__BOTTOM, RIGHT_FRONT_BOTTOM);
    
    // top
    SetIndex(&indices, LEFT__FRONT_TOP,    RIGHT_FRONT_TOP,    RIGHT_BACK__TOP);
    SetIndex(&indices, LEFT__FRONT_TOP,    RIGHT_BACK__TOP,    LEFT__BACK__TOP);
    
    // left
    SetIndex(&indices, LEFT__FRONT_BOTTOM, LEFT__FRONT_TOP,    LEFT__BACK__TOP);
    SetIndex(&indices, LEFT__FRONT_BOTTOM, LEFT__BACK__TOP,    LEFT__BACK__BOTTOM);
    
    // right
    SetIndex(&indices, RIGHT_FRONT_BOTTOM, RIGHT_BACK__BOTTOM, RIGHT_BACK__TOP);
    SetIndex(&indices, RIGHT_FRONT_BOTTOM, RIGHT_BACK__TOP,    RIGHT_FRONT_TOP);
    
    // front
    SetIndex(&indices, LEFT__FRONT_BOTTOM, RIGHT_FRONT_BOTTOM, RIGHT_FRONT_TOP);
    SetIndex(&indices, LEFT__FRONT_BOTTOM, RIGHT_FRONT_TOP,    LEFT__FRONT_TOP);
    
    // back
    SetIndex(&indices, LEFT__BACK__BOTTOM, LEFT__BACK__TOP,    RIGHT_BACK__TOP);
    SetIndex(&indices, LEFT__BACK__BOTTOM, RIGHT_BACK__TOP,    RIGHT_BACK__BOTTOM);
}

} // namespace Gphx