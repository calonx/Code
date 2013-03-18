//==============================================================================
// Graphics.h
// Paul Marden (2/12/2012)
//==============================================================================

struct D3DXCOLOR;

namespace Gphx {

//==============================================================================
// VertexSimple
//==============================================================================

struct VertexSimple {
    VertexSimple () { }
    VertexSimple (float x_, float y_, float z_) : x(x_), y(y_), z(z_) { }
    VertexSimple (float x_, float y_, float z_, const Color4f & c) : x(x_), y(y_), z(z_), color(c) { }

    float x, y, z;
    Color4f color;
};


//==============================================================================
// IModel
//==============================================================================

interface IModel {
    virtual ~IModel () { }
    
    virtual void Render () = 0;
};


//==============================================================================
// IGraphics
//==============================================================================

interface IGraphics {
    virtual ~IGraphics () { }

    virtual bool Advance () = 0;

    virtual void RenderBegin () = 0;
    virtual void RenderEnd () = 0;

    virtual IModel * CreateModel (
        const VertexSimple  vertices[],
        uint                vertexCount,
        const ushort        indices[],
        uint                indexCount
    ) = 0;
};

IGraphics * GraphicsCreate (const wchar title[], const Rect4i & rect);


//==============================================================================
// Helpers
//==============================================================================

const unsigned BOX_VERTEX_COUNT = 8;
const unsigned BOX_INDEX_COUNT  = 6 * 2 * 3;

void GenerateBox (
    VertexSimple *  vertices,
    unsigned        vertexCount,
    ushort *        indices,
    unsigned        indexCount
);

} // namespace Gphx
