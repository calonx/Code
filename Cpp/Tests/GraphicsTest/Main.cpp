//==============================================================================
// Main.cpp
// Paul Marden (2/4/2012)
//==============================================================================
#include "Pch.h"

using namespace Gphx;

//==============================================================================
int main () {
    VertexSimple vertices[BOX_VERTEX_COUNT];
    ushort indices[BOX_INDEX_COUNT];
    
    GenerateBox(vertices, arrsize(vertices), indices, arrsize(indices));
    
    const float scale = 0.5f;
    for (uint i = 0; i < arrsize(vertices); ++i) {
        vertices[i].x *= scale;
        vertices[i].y *= scale;
        vertices[i].z *= scale;
    }
    
    const Rect4i windowRect(0, 0, 800, 600);
    IGraphics * graphics = Gphx::GraphicsCreate(L"GraphicsTest", windowRect);
    
    IModel * model = graphics->CreateModel(vertices, arrsize(vertices), indices, arrsize(indices));
    
    while (graphics->Advance()) {
        graphics->RenderBegin();
        model->Render();
        graphics->RenderEnd();
    }
    
    delete model;
    delete graphics;
    
    _CrtDumpMemoryLeaks();
    
    return 0;
}
