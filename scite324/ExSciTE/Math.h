namespace Math
{

//==============================================================================
// Common functions
//==============================================================================


inline f32 Sqrt (f32 v) {
    return f32(sqrt(v));
}

inline f64 Sqrt (f64 v) {
    return f64(sqrt(v));
}

inline f32 Cos (f32 v) {
    return f32(cos(v));
}

inline f64 Cos (f64 v) {
    return f64(cos(v));
}

inline f32 Sin (f32 v) {
    return f32(sin(v));
}

inline f64 Sin (f64 v) {
    return f64(sin(v));
}

inline f32 Tan (f32 v) {
    return f32(tan(v));
}

inline f64 Tan (f64 v) {
    return f64(tan(v));
}

inline f32 Acos (f32 v) {
    return f32(acos(v));
}

inline f64 Acos (f64 v) {
    return f64(acos(v));
}

inline f32 Asin (f32 v) {
    return f32(asin(v));
}

inline f64 Asin (f64 v) {
    return f64(asin(v));
}

//==============================================================================
// MagSq
//==============================================================================


f32 MagSq (const Vec2f & v) {
    return v.x * v.x + v.y * v.y;
}

f32 MagSq (const Vec3f & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

f32 MagSq (const Vec4f & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

f64 MagSq (const Vec2d & v) {
    return v.x * v.x + v.y * v.y;
}

f64 MagSq (const Vec3d & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

f64 MagSq (const Vec4d & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

s32 MagSq (const Vec2i & v) {
    return v.x * v.x + v.y * v.y;
}

s32 MagSq (const Vec3i & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

s32 MagSq (const Vec4i & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

u32 MagSq (const Vec2u & v) {
    return v.x * v.x + v.y * v.y;
}

u32 MagSq (const Vec3u & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

u32 MagSq (const Vec4u & v) {
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

f32 MagSq (const Color4f & v) {
    return v.r * v.r + v.g * v.g + v.b * v.b + v.a * v.a;
}

u8 MagSq (const Color4b & v) {
    return v.r * v.r + v.g * v.g + v.b * v.b + v.a * v.a;
}

//==============================================================================
// Mag
//==============================================================================


f32 Mag (const Vec2f & v) {
    return Sqrt(v.x * v.x + v.y * v.y);
}

f32 Mag (const Vec3f & v) {
    return Sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

f32 Mag (const Vec4f & v) {
    return Sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

f32 Mag (const Color4f & v) {
    return Sqrt(v.r * v.r + v.g * v.g + v.b * v.b + v.a * v.a);
}

//==============================================================================
// Dot
//==============================================================================


f32 Dot (const Vec2f & lhs, const Vec2f & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

f32 Dot (const Vec3f & lhs, const Vec3f & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

f32 Dot (const Vec4f & lhs, const Vec4f & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

f64 Dot (const Vec2d & lhs, const Vec2d & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

f64 Dot (const Vec3d & lhs, const Vec3d & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

f64 Dot (const Vec4d & lhs, const Vec4d & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

s32 Dot (const Vec2i & lhs, const Vec2i & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

s32 Dot (const Vec3i & lhs, const Vec3i & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

s32 Dot (const Vec4i & lhs, const Vec4i & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

u32 Dot (const Vec2u & lhs, const Vec2u & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

u32 Dot (const Vec3u & lhs, const Vec3u & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

u32 Dot (const Vec4u & lhs, const Vec4u & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

f32 Dot (const Color4f & lhs, const Color4f & rhs) {
    return lhs.r * rhs.r + lhs.g * rhs.g + lhs.b * rhs.b + lhs.a * rhs.a;
}

u8 Dot (const Color4b & lhs, const Color4b & rhs) {
    return lhs.r * rhs.r + lhs.g * rhs.g + lhs.b * rhs.b + lhs.a * rhs.a;
}

//==============================================================================
// Normalization
//==============================================================================


template<class T>
void Normalize (T * t) {
    *t = *t / Mag(*t);
}

template<class T>
void Normalize (const T & src, T * dst) {
    *dst = src / Mag(src);
}

template<class T>
const T & Normalized (T * src) {
    *src /= Mag(src);
    return *src;
}

} // namespace Math
