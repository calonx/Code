

//==============================================================================
// MathMagnitudeSq
//==============================================================================

float MathMagnitudeSq (const Vec2f & v) {
    return v.x * v.x + v.y * v.y;
}

float MathMagnitudeSq (const Vec3f & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float MathMagnitudeSq (const Vec4f & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

double MathMagnitudeSq (const Vec2d & v) {
    return v.x * v.x + v.y * v.y;
}

double MathMagnitudeSq (const Vec3d & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

double MathMagnitudeSq (const Vec4d & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

int MathMagnitudeSq (const Vec2i & v) {
    return v.x * v.x + v.y * v.y;
}

int MathMagnitudeSq (const Vec3i & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

int MathMagnitudeSq (const Vec4i & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

unsigned MathMagnitudeSq (const Vec2u & v) {
    return v.x * v.x + v.y * v.y;
}

unsigned MathMagnitudeSq (const Vec3u & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

unsigned MathMagnitudeSq (const Vec4u & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

float MathMagnitudeSq (const Color4f & v) {
    return v.r * v.r + v.g * v.g + v.b * v.b + v.a * v.a;
}

byte MathMagnitudeSq (const Color4b & v) {
    return v.r * v.r + v.g * v.g + v.b * v.b + v.a * v.a;
}


//==============================================================================
// MathMagnitude
//==============================================================================

float MathMagnitude (const Vec2f & v) {
    return MathSqrt(v.x * v.x + v.y * v.y);
}

float MathMagnitude (const Vec3f & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float MathMagnitude (const Vec4f & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

double MathMagnitude (const Vec2d & v) {
    return MathSqrt(v.x * v.x + v.y * v.y);
}

double MathMagnitude (const Vec3d & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double MathMagnitude (const Vec4d & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

int MathMagnitude (const Vec2i & v) {
    return MathSqrt(v.x * v.x + v.y * v.y);
}

int MathMagnitude (const Vec3i & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

int MathMagnitude (const Vec4i & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

unsigned MathMagnitude (const Vec2u & v) {
    return MathSqrt(v.x * v.x + v.y * v.y);
}

unsigned MathMagnitude (const Vec3u & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

unsigned MathMagnitude (const Vec4u & v) {
    return MathSqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

float MathMagnitude (const Color4f & v) {
    return MathSqrt(v.r * v.r + v.g * v.g + v.b * v.b + v.a * v.a);
}

byte MathMagnitude (const Color4b & v) {
    return MathSqrt(v.r * v.r + v.g * v.g + v.b * v.b + v.a * v.a);
}


//==============================================================================
// MathDotProduct
//==============================================================================

float MathDotProduct (const Vec2f & lhs, const Vec2f & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float MathDotProduct (const Vec3f & lhs, const Vec3f & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float MathDotProduct (const Vec4f & lhs, const Vec4f & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

double MathDotProduct (const Vec2d & lhs, const Vec2d & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

double MathDotProduct (const Vec3d & lhs, const Vec3d & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

double MathDotProduct (const Vec4d & lhs, const Vec4d & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

int MathDotProduct (const Vec2i & lhs, const Vec2i & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

int MathDotProduct (const Vec3i & lhs, const Vec3i & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

int MathDotProduct (const Vec4i & lhs, const Vec4i & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

unsigned MathDotProduct (const Vec2u & lhs, const Vec2u & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

unsigned MathDotProduct (const Vec3u & lhs, const Vec3u & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

unsigned MathDotProduct (const Vec4u & lhs, const Vec4u & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

float MathDotProduct (const Color4f & lhs, const Color4f & rhs) {
    return lhs.r * rhs.r + lhs.g * rhs.g + lhs.b * rhs.b + lhs.a * rhs.a;
}

byte MathDotProduct (const Color4b & lhs, const Color4b & rhs) {
    return lhs.r * rhs.r + lhs.g * rhs.g + lhs.b * rhs.b + lhs.a * rhs.a;
}


//==============================================================================
// Normalization
//==============================================================================

template<class T>
void MathNormalize (T * t) {
    *t = *t / MathMagnitude(*t);
}

template<class T>
void MathNormalize (const T & src, T * dst) {
    *dst = src / MathMagnitude(src);
}
