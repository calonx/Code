
#include "Common.h"

//==============================================================================
// Rect
//==============================================================================

template<typename T>
struct Rect {
    inline Rect () : x0(0), y0(0), x1(0), y1(0) {  }
    inline Rect (T x0_, T y0_, T x1_, T y1_) : x0(x0_), y0(y0_), x1(x1_), y1(y1_) {  }
    
    inline T Width () const  { return x1 - x0; }
    inline T Height () const { return y1 - y0; }
    
    inline void SetDims (T w, T h) {
        x1 = x0 + w;
        y1 = y0 + h;
    }
    
    T x0, y0, x1, y1;
};

typedef Rect<uint>   Rect4u;
typedef Rect<int>    Rect4i;
typedef Rect<float>  Rect4f;
typedef Rect<double> Rect4d;


//==============================================================================
// Color4f
//==============================================================================

struct Color4f {
    Color4f () : r(0), g(0), b(0), a(0) { }
    Color4f (float r_, float g_, float b_) : r(r_), g(g_), b(b_), a(1) { }
    Color4f (float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) { }
    
    float r, g, b, a;
};