//==============================================================================
// GraphicsInt.h
// Paul Marden (2/12/2012)
//==============================================================================

namespace Gphx {

//==============================================================================
// COM Helpers
//==============================================================================

//==============================================================================
template<typename T>
inline void TReleaseSafe (T ** obj) {
    if (*obj) {
        (*obj)->Release();
        *obj = NULL;
    }
}

//==============================================================================
template<typename T>
inline T * TAddRef (T * obj) {
    obj->AddRef();
    return obj;
}

//==============================================================================
template<typename T>
class TComRef {
public:
    inline TComRef () : m_ptr(NULL) { }
    inline TComRef (T * ptr) : m_ptr(TAddRef(ptr)) { }
    inline ~TComRef () { TReleaseSafe(&m_ptr); }
    
    // Used for initial non-AddRef assignments
    inline T *& Ref () { return m_ptr; }
    
    inline operator T * () { return m_ptr; }
    
    inline T * operator -> () { return m_ptr; }
    
    inline T * operator = (T * ptr) {
        TReleaseSafe(&m_ptr);
        m_ptr = TAddRef(ptr);
        return ptr;
    }

private:
    T * m_ptr;
};


//==============================================================================
// CWindow
//==============================================================================

class CWindow {
public:
    ~CWindow ();
    
    static CWindow * Create (const wchar title[], const Rect4i & rect);
    
    HWND           GetHwnd () const { return m_hwnd; }
    const Rect4i & GetRect () const { return m_rect; }
    
    bool Pump ();

private:
    CWindow (HWND hwnd, const Rect4i & clientRect);
    
    static CWindow * GetWindowForHwnd (HWND hwnd);
    
    static LRESULT CALLBACK WindowProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
    
    HWND   m_hwnd;
    Rect4i m_rect;
};


//==============================================================================
// CGeometryBuffer
//==============================================================================

template<typename V>
class CGeometryBuffer {
public:
    CGeometryBuffer (
        ID3D11Buffer *          vertexBuffer,
        uint                    vertexCount,
        ID3D11Buffer *          indexBuffer,
        uint                    indexCount,
        ID3D11DeviceContext *   context
    );
    ~CGeometryBuffer ();
    
    void Use ();
    void Render ();

private:
    void SetVertices (uint count, const V vertices[]);

    TComRef<ID3D11Buffer>        m_indexBuffer;
    uint                         m_indexCount;
    TComRef<ID3D11Buffer>        m_vertexBuffer;
    uint                         m_vertexCount;
    TComRef<ID3D11DeviceContext> m_context;
};


//==============================================================================
// CModel
//==============================================================================

class CModel : public IModel {
public:
    CModel (CGeometryBuffer<VertexSimple> * buffer) : m_buffer(buffer) { }

public: // IModel
    void Render ();

private:
    CGeometryBuffer<VertexSimple> * m_buffer;
};


//==============================================================================
// CGraphics
//==============================================================================

class CGraphics : public IGraphics {
public:
    static CGraphics * Create (const wchar title[], const Rect4i & rect);
    
    void Initialize (const wchar title[], const Rect4i & rect);
    void Destroy ();

public: // IGraphics
    bool Advance ();

    void RenderBegin ();
    void RenderEnd ();

    IModel * CreateModel (
        const VertexSimple  vertices[],
        uint                vertexCount,
        const ushort        indices[],
        uint                indexCount
    );

private:
    void InitializeRenderTargets ();
    void InitializePipeline ();

    void SetViewport (const Rect4i & rect);

    CWindow *                m_window;
    IDXGISwapChain *         m_swapChain;
    ID3D11Device *           m_device;
    ID3D11DeviceContext *    m_context;
    ID3D11RenderTargetView * m_renderTarget;
    
    ID3D11VertexShader *     m_vertexShader;
    ID3D11PixelShader *      m_pixelShader;
    ID3D11InputLayout *      m_inputLayout;
};

} // namespace Gphx
