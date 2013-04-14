
//==============================================================================
// Typedefs
//==============================================================================


typedef char                s8;
typedef short               s16;
typedef int                 s32;
typedef __int64             s64;

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned __int64    u64;

typedef float               f32;
typedef double              f64;

typedef wchar_t             wchar;


//==============================================================================
// Vec2f
//==============================================================================

struct Vec2f {
    f32 x;
    f32 y;

    inline Vec2f () {
        this->x = 0;
        this->y = 0;
    }

    inline Vec2f (const Vec2f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2f (f32 x, f32 y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2f (f32 v) {
        this->x = v;
        this->y = v;
    };

    inline const Vec2f & operator = (const Vec2f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }

    inline const Vec2f & operator += (const Vec2f & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    inline const Vec2f & operator -= (const Vec2f & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    inline const Vec2f & operator *= (const Vec2f & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        return *this;
    }

    inline const Vec2f & operator /= (const Vec2f & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        return *this;
    }

    inline const Vec2f & operator += (f32 s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2f & operator -= (f32 s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2f & operator *= (f32 s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2f & operator /= (f32 s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }
};

inline static Vec2f operator + (const Vec2f & lhs, const Vec2f & rhs) {
    return Vec2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline static Vec2f operator - (const Vec2f & lhs, const Vec2f & rhs) {
    return Vec2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline static Vec2f operator * (const Vec2f & lhs, const Vec2f & rhs) {
    return Vec2f(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline static Vec2f operator / (const Vec2f & lhs, const Vec2f & rhs) {
    return Vec2f(lhs.x / rhs.x, lhs.y / rhs.y);
}

inline static Vec2f operator + (const Vec2f & lhs, f32 s) {
    return Vec2f(lhs.x + s, lhs.y + s);
}

inline static Vec2f operator - (const Vec2f & lhs, f32 s) {
    return Vec2f(lhs.x - s, lhs.y - s);
}

inline static Vec2f operator * (const Vec2f & lhs, f32 s) {
    return Vec2f(lhs.x * s, lhs.y * s);
}

inline static Vec2f operator / (const Vec2f & lhs, f32 s) {
    return Vec2f(lhs.x / s, lhs.y / s);
}



//==============================================================================
// Vec3f
//==============================================================================

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;

    inline Vec3f () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    inline Vec3f (const Vec3f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3f (f32 x, f32 y, f32 z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3f (f32 v) {
        this->x = v;
        this->y = v;
        this->z = v;
    };

    inline const Vec3f & operator = (const Vec3f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        return *this;
    }

    inline const Vec3f & operator += (const Vec3f & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }

    inline const Vec3f & operator -= (const Vec3f & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        return *this;
    }

    inline const Vec3f & operator *= (const Vec3f & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        return *this;
    }

    inline const Vec3f & operator /= (const Vec3f & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        return *this;
    }

    inline const Vec3f & operator += (f32 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3f & operator -= (f32 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3f & operator *= (f32 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3f & operator /= (f32 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }
};

inline static Vec3f operator + (const Vec3f & lhs, const Vec3f & rhs) {
    return Vec3f(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline static Vec3f operator - (const Vec3f & lhs, const Vec3f & rhs) {
    return Vec3f(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline static Vec3f operator * (const Vec3f & lhs, const Vec3f & rhs) {
    return Vec3f(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

inline static Vec3f operator / (const Vec3f & lhs, const Vec3f & rhs) {
    return Vec3f(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

inline static Vec3f operator + (const Vec3f & lhs, f32 s) {
    return Vec3f(lhs.x + s, lhs.y + s, lhs.z + s);
}

inline static Vec3f operator - (const Vec3f & lhs, f32 s) {
    return Vec3f(lhs.x - s, lhs.y - s, lhs.z - s);
}

inline static Vec3f operator * (const Vec3f & lhs, f32 s) {
    return Vec3f(lhs.x * s, lhs.y * s, lhs.z * s);
}

inline static Vec3f operator / (const Vec3f & lhs, f32 s) {
    return Vec3f(lhs.x / s, lhs.y / s, lhs.z / s);
}



//==============================================================================
// Vec4f
//==============================================================================

struct Vec4f {
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    inline Vec4f () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }

    inline Vec4f (const Vec4f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4f (f32 x, f32 y, f32 z, f32 w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4f (f32 v) {
        this->x = v;
        this->y = v;
        this->z = v;
        this->w = v;
    };

    inline const Vec4f & operator = (const Vec4f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
        return *this;
    }

    inline const Vec4f & operator += (const Vec4f & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        this->w += rhs.w;
        return *this;
    }

    inline const Vec4f & operator -= (const Vec4f & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        this->w -= rhs.w;
        return *this;
    }

    inline const Vec4f & operator *= (const Vec4f & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        this->w *= rhs.w;
        return *this;
    }

    inline const Vec4f & operator /= (const Vec4f & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        this->w /= rhs.w;
        return *this;
    }

    inline const Vec4f & operator += (f32 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4f & operator -= (f32 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4f & operator *= (f32 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4f & operator /= (f32 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }
};

inline static Vec4f operator + (const Vec4f & lhs, const Vec4f & rhs) {
    return Vec4f(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

inline static Vec4f operator - (const Vec4f & lhs, const Vec4f & rhs) {
    return Vec4f(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

inline static Vec4f operator * (const Vec4f & lhs, const Vec4f & rhs) {
    return Vec4f(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

inline static Vec4f operator / (const Vec4f & lhs, const Vec4f & rhs) {
    return Vec4f(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

inline static Vec4f operator + (const Vec4f & lhs, f32 s) {
    return Vec4f(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
}

inline static Vec4f operator - (const Vec4f & lhs, f32 s) {
    return Vec4f(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
}

inline static Vec4f operator * (const Vec4f & lhs, f32 s) {
    return Vec4f(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
}

inline static Vec4f operator / (const Vec4f & lhs, f32 s) {
    return Vec4f(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
}



//==============================================================================
// Vec2d
//==============================================================================

struct Vec2d {
    f64 x;
    f64 y;

    inline Vec2d () {
        this->x = 0;
        this->y = 0;
    }

    inline Vec2d (const Vec2d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2d (f64 x, f64 y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2d (f64 v) {
        this->x = v;
        this->y = v;
    };

    inline const Vec2d & operator = (const Vec2d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }

    inline const Vec2d & operator += (const Vec2d & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    inline const Vec2d & operator -= (const Vec2d & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    inline const Vec2d & operator *= (const Vec2d & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        return *this;
    }

    inline const Vec2d & operator /= (const Vec2d & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        return *this;
    }

    inline const Vec2d & operator += (f64 s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2d & operator -= (f64 s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2d & operator *= (f64 s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2d & operator /= (f64 s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }
};

inline static Vec2d operator + (const Vec2d & lhs, const Vec2d & rhs) {
    return Vec2d(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline static Vec2d operator - (const Vec2d & lhs, const Vec2d & rhs) {
    return Vec2d(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline static Vec2d operator * (const Vec2d & lhs, const Vec2d & rhs) {
    return Vec2d(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline static Vec2d operator / (const Vec2d & lhs, const Vec2d & rhs) {
    return Vec2d(lhs.x / rhs.x, lhs.y / rhs.y);
}

inline static Vec2d operator + (const Vec2d & lhs, f64 s) {
    return Vec2d(lhs.x + s, lhs.y + s);
}

inline static Vec2d operator - (const Vec2d & lhs, f64 s) {
    return Vec2d(lhs.x - s, lhs.y - s);
}

inline static Vec2d operator * (const Vec2d & lhs, f64 s) {
    return Vec2d(lhs.x * s, lhs.y * s);
}

inline static Vec2d operator / (const Vec2d & lhs, f64 s) {
    return Vec2d(lhs.x / s, lhs.y / s);
}



//==============================================================================
// Vec3d
//==============================================================================

struct Vec3d {
    f64 x;
    f64 y;
    f64 z;

    inline Vec3d () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    inline Vec3d (const Vec3d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3d (f64 x, f64 y, f64 z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3d (f64 v) {
        this->x = v;
        this->y = v;
        this->z = v;
    };

    inline const Vec3d & operator = (const Vec3d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        return *this;
    }

    inline const Vec3d & operator += (const Vec3d & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }

    inline const Vec3d & operator -= (const Vec3d & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        return *this;
    }

    inline const Vec3d & operator *= (const Vec3d & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        return *this;
    }

    inline const Vec3d & operator /= (const Vec3d & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        return *this;
    }

    inline const Vec3d & operator += (f64 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3d & operator -= (f64 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3d & operator *= (f64 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3d & operator /= (f64 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }
};

inline static Vec3d operator + (const Vec3d & lhs, const Vec3d & rhs) {
    return Vec3d(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline static Vec3d operator - (const Vec3d & lhs, const Vec3d & rhs) {
    return Vec3d(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline static Vec3d operator * (const Vec3d & lhs, const Vec3d & rhs) {
    return Vec3d(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

inline static Vec3d operator / (const Vec3d & lhs, const Vec3d & rhs) {
    return Vec3d(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

inline static Vec3d operator + (const Vec3d & lhs, f64 s) {
    return Vec3d(lhs.x + s, lhs.y + s, lhs.z + s);
}

inline static Vec3d operator - (const Vec3d & lhs, f64 s) {
    return Vec3d(lhs.x - s, lhs.y - s, lhs.z - s);
}

inline static Vec3d operator * (const Vec3d & lhs, f64 s) {
    return Vec3d(lhs.x * s, lhs.y * s, lhs.z * s);
}

inline static Vec3d operator / (const Vec3d & lhs, f64 s) {
    return Vec3d(lhs.x / s, lhs.y / s, lhs.z / s);
}



//==============================================================================
// Vec4d
//==============================================================================

struct Vec4d {
    f64 x;
    f64 y;
    f64 z;
    f64 w;

    inline Vec4d () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }

    inline Vec4d (const Vec4d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4d (f64 x, f64 y, f64 z, f64 w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4d (f64 v) {
        this->x = v;
        this->y = v;
        this->z = v;
        this->w = v;
    };

    inline const Vec4d & operator = (const Vec4d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
        return *this;
    }

    inline const Vec4d & operator += (const Vec4d & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        this->w += rhs.w;
        return *this;
    }

    inline const Vec4d & operator -= (const Vec4d & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        this->w -= rhs.w;
        return *this;
    }

    inline const Vec4d & operator *= (const Vec4d & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        this->w *= rhs.w;
        return *this;
    }

    inline const Vec4d & operator /= (const Vec4d & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        this->w /= rhs.w;
        return *this;
    }

    inline const Vec4d & operator += (f64 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4d & operator -= (f64 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4d & operator *= (f64 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4d & operator /= (f64 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }
};

inline static Vec4d operator + (const Vec4d & lhs, const Vec4d & rhs) {
    return Vec4d(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

inline static Vec4d operator - (const Vec4d & lhs, const Vec4d & rhs) {
    return Vec4d(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

inline static Vec4d operator * (const Vec4d & lhs, const Vec4d & rhs) {
    return Vec4d(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

inline static Vec4d operator / (const Vec4d & lhs, const Vec4d & rhs) {
    return Vec4d(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

inline static Vec4d operator + (const Vec4d & lhs, f64 s) {
    return Vec4d(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
}

inline static Vec4d operator - (const Vec4d & lhs, f64 s) {
    return Vec4d(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
}

inline static Vec4d operator * (const Vec4d & lhs, f64 s) {
    return Vec4d(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
}

inline static Vec4d operator / (const Vec4d & lhs, f64 s) {
    return Vec4d(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
}



//==============================================================================
// Vec2i
//==============================================================================

struct Vec2i {
    s32 x;
    s32 y;

    inline Vec2i () {
        this->x = 0;
        this->y = 0;
    }

    inline Vec2i (const Vec2i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2i (s32 x, s32 y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2i (s32 v) {
        this->x = v;
        this->y = v;
    };

    inline const Vec2i & operator = (const Vec2i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }

    inline const Vec2i & operator += (const Vec2i & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    inline const Vec2i & operator -= (const Vec2i & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    inline const Vec2i & operator *= (const Vec2i & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        return *this;
    }

    inline const Vec2i & operator /= (const Vec2i & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        return *this;
    }

    inline const Vec2i & operator += (s32 s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2i & operator -= (s32 s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2i & operator *= (s32 s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2i & operator /= (s32 s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }
};

inline static Vec2i operator + (const Vec2i & lhs, const Vec2i & rhs) {
    return Vec2i(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline static Vec2i operator - (const Vec2i & lhs, const Vec2i & rhs) {
    return Vec2i(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline static Vec2i operator * (const Vec2i & lhs, const Vec2i & rhs) {
    return Vec2i(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline static Vec2i operator / (const Vec2i & lhs, const Vec2i & rhs) {
    return Vec2i(lhs.x / rhs.x, lhs.y / rhs.y);
}

inline static Vec2i operator + (const Vec2i & lhs, s32 s) {
    return Vec2i(lhs.x + s, lhs.y + s);
}

inline static Vec2i operator - (const Vec2i & lhs, s32 s) {
    return Vec2i(lhs.x - s, lhs.y - s);
}

inline static Vec2i operator * (const Vec2i & lhs, s32 s) {
    return Vec2i(lhs.x * s, lhs.y * s);
}

inline static Vec2i operator / (const Vec2i & lhs, s32 s) {
    return Vec2i(lhs.x / s, lhs.y / s);
}



//==============================================================================
// Vec3i
//==============================================================================

struct Vec3i {
    s32 x;
    s32 y;
    s32 z;

    inline Vec3i () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    inline Vec3i (const Vec3i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3i (s32 x, s32 y, s32 z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3i (s32 v) {
        this->x = v;
        this->y = v;
        this->z = v;
    };

    inline const Vec3i & operator = (const Vec3i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        return *this;
    }

    inline const Vec3i & operator += (const Vec3i & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }

    inline const Vec3i & operator -= (const Vec3i & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        return *this;
    }

    inline const Vec3i & operator *= (const Vec3i & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        return *this;
    }

    inline const Vec3i & operator /= (const Vec3i & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        return *this;
    }

    inline const Vec3i & operator += (s32 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3i & operator -= (s32 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3i & operator *= (s32 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3i & operator /= (s32 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }
};

inline static Vec3i operator + (const Vec3i & lhs, const Vec3i & rhs) {
    return Vec3i(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline static Vec3i operator - (const Vec3i & lhs, const Vec3i & rhs) {
    return Vec3i(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline static Vec3i operator * (const Vec3i & lhs, const Vec3i & rhs) {
    return Vec3i(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

inline static Vec3i operator / (const Vec3i & lhs, const Vec3i & rhs) {
    return Vec3i(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

inline static Vec3i operator + (const Vec3i & lhs, s32 s) {
    return Vec3i(lhs.x + s, lhs.y + s, lhs.z + s);
}

inline static Vec3i operator - (const Vec3i & lhs, s32 s) {
    return Vec3i(lhs.x - s, lhs.y - s, lhs.z - s);
}

inline static Vec3i operator * (const Vec3i & lhs, s32 s) {
    return Vec3i(lhs.x * s, lhs.y * s, lhs.z * s);
}

inline static Vec3i operator / (const Vec3i & lhs, s32 s) {
    return Vec3i(lhs.x / s, lhs.y / s, lhs.z / s);
}



//==============================================================================
// Vec4i
//==============================================================================

struct Vec4i {
    s32 x;
    s32 y;
    s32 z;
    s32 w;

    inline Vec4i () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }

    inline Vec4i (const Vec4i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4i (s32 x, s32 y, s32 z, s32 w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4i (s32 v) {
        this->x = v;
        this->y = v;
        this->z = v;
        this->w = v;
    };

    inline const Vec4i & operator = (const Vec4i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
        return *this;
    }

    inline const Vec4i & operator += (const Vec4i & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        this->w += rhs.w;
        return *this;
    }

    inline const Vec4i & operator -= (const Vec4i & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        this->w -= rhs.w;
        return *this;
    }

    inline const Vec4i & operator *= (const Vec4i & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        this->w *= rhs.w;
        return *this;
    }

    inline const Vec4i & operator /= (const Vec4i & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        this->w /= rhs.w;
        return *this;
    }

    inline const Vec4i & operator += (s32 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4i & operator -= (s32 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4i & operator *= (s32 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4i & operator /= (s32 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }
};

inline static Vec4i operator + (const Vec4i & lhs, const Vec4i & rhs) {
    return Vec4i(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

inline static Vec4i operator - (const Vec4i & lhs, const Vec4i & rhs) {
    return Vec4i(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

inline static Vec4i operator * (const Vec4i & lhs, const Vec4i & rhs) {
    return Vec4i(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

inline static Vec4i operator / (const Vec4i & lhs, const Vec4i & rhs) {
    return Vec4i(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

inline static Vec4i operator + (const Vec4i & lhs, s32 s) {
    return Vec4i(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
}

inline static Vec4i operator - (const Vec4i & lhs, s32 s) {
    return Vec4i(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
}

inline static Vec4i operator * (const Vec4i & lhs, s32 s) {
    return Vec4i(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
}

inline static Vec4i operator / (const Vec4i & lhs, s32 s) {
    return Vec4i(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
}



//==============================================================================
// Vec2u
//==============================================================================

struct Vec2u {
    u32 x;
    u32 y;

    inline Vec2u () {
        this->x = 0;
        this->y = 0;
    }

    inline Vec2u (const Vec2u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2u (u32 x, u32 y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2u (u32 v) {
        this->x = v;
        this->y = v;
    };

    inline const Vec2u & operator = (const Vec2u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }

    inline const Vec2u & operator += (const Vec2u & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    inline const Vec2u & operator -= (const Vec2u & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    inline const Vec2u & operator *= (const Vec2u & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        return *this;
    }

    inline const Vec2u & operator /= (const Vec2u & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        return *this;
    }

    inline const Vec2u & operator += (u32 s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2u & operator -= (u32 s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2u & operator *= (u32 s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2u & operator /= (u32 s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }
};

inline static Vec2u operator + (const Vec2u & lhs, const Vec2u & rhs) {
    return Vec2u(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline static Vec2u operator - (const Vec2u & lhs, const Vec2u & rhs) {
    return Vec2u(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline static Vec2u operator * (const Vec2u & lhs, const Vec2u & rhs) {
    return Vec2u(lhs.x * rhs.x, lhs.y * rhs.y);
}

inline static Vec2u operator / (const Vec2u & lhs, const Vec2u & rhs) {
    return Vec2u(lhs.x / rhs.x, lhs.y / rhs.y);
}

inline static Vec2u operator + (const Vec2u & lhs, u32 s) {
    return Vec2u(lhs.x + s, lhs.y + s);
}

inline static Vec2u operator - (const Vec2u & lhs, u32 s) {
    return Vec2u(lhs.x - s, lhs.y - s);
}

inline static Vec2u operator * (const Vec2u & lhs, u32 s) {
    return Vec2u(lhs.x * s, lhs.y * s);
}

inline static Vec2u operator / (const Vec2u & lhs, u32 s) {
    return Vec2u(lhs.x / s, lhs.y / s);
}



//==============================================================================
// Vec3u
//==============================================================================

struct Vec3u {
    u32 x;
    u32 y;
    u32 z;

    inline Vec3u () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    inline Vec3u (const Vec3u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3u (u32 x, u32 y, u32 z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3u (u32 v) {
        this->x = v;
        this->y = v;
        this->z = v;
    };

    inline const Vec3u & operator = (const Vec3u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        return *this;
    }

    inline const Vec3u & operator += (const Vec3u & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }

    inline const Vec3u & operator -= (const Vec3u & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        return *this;
    }

    inline const Vec3u & operator *= (const Vec3u & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        return *this;
    }

    inline const Vec3u & operator /= (const Vec3u & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        return *this;
    }

    inline const Vec3u & operator += (u32 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3u & operator -= (u32 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3u & operator *= (u32 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3u & operator /= (u32 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }
};

inline static Vec3u operator + (const Vec3u & lhs, const Vec3u & rhs) {
    return Vec3u(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline static Vec3u operator - (const Vec3u & lhs, const Vec3u & rhs) {
    return Vec3u(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline static Vec3u operator * (const Vec3u & lhs, const Vec3u & rhs) {
    return Vec3u(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

inline static Vec3u operator / (const Vec3u & lhs, const Vec3u & rhs) {
    return Vec3u(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

inline static Vec3u operator + (const Vec3u & lhs, u32 s) {
    return Vec3u(lhs.x + s, lhs.y + s, lhs.z + s);
}

inline static Vec3u operator - (const Vec3u & lhs, u32 s) {
    return Vec3u(lhs.x - s, lhs.y - s, lhs.z - s);
}

inline static Vec3u operator * (const Vec3u & lhs, u32 s) {
    return Vec3u(lhs.x * s, lhs.y * s, lhs.z * s);
}

inline static Vec3u operator / (const Vec3u & lhs, u32 s) {
    return Vec3u(lhs.x / s, lhs.y / s, lhs.z / s);
}



//==============================================================================
// Vec4u
//==============================================================================

struct Vec4u {
    u32 x;
    u32 y;
    u32 z;
    u32 w;

    inline Vec4u () {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }

    inline Vec4u (const Vec4u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4u (u32 x, u32 y, u32 z, u32 w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4u (u32 v) {
        this->x = v;
        this->y = v;
        this->z = v;
        this->w = v;
    };

    inline const Vec4u & operator = (const Vec4u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
        return *this;
    }

    inline const Vec4u & operator += (const Vec4u & rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        this->w += rhs.w;
        return *this;
    }

    inline const Vec4u & operator -= (const Vec4u & rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        this->w -= rhs.w;
        return *this;
    }

    inline const Vec4u & operator *= (const Vec4u & rhs) {
        this->x *= rhs.x;
        this->y *= rhs.y;
        this->z *= rhs.z;
        this->w *= rhs.w;
        return *this;
    }

    inline const Vec4u & operator /= (const Vec4u & rhs) {
        this->x /= rhs.x;
        this->y /= rhs.y;
        this->z /= rhs.z;
        this->w /= rhs.w;
        return *this;
    }

    inline const Vec4u & operator += (u32 s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4u & operator -= (u32 s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4u & operator *= (u32 s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4u & operator /= (u32 s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }
};

inline static Vec4u operator + (const Vec4u & lhs, const Vec4u & rhs) {
    return Vec4u(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

inline static Vec4u operator - (const Vec4u & lhs, const Vec4u & rhs) {
    return Vec4u(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

inline static Vec4u operator * (const Vec4u & lhs, const Vec4u & rhs) {
    return Vec4u(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

inline static Vec4u operator / (const Vec4u & lhs, const Vec4u & rhs) {
    return Vec4u(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

inline static Vec4u operator + (const Vec4u & lhs, u32 s) {
    return Vec4u(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
}

inline static Vec4u operator - (const Vec4u & lhs, u32 s) {
    return Vec4u(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
}

inline static Vec4u operator * (const Vec4u & lhs, u32 s) {
    return Vec4u(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
}

inline static Vec4u operator / (const Vec4u & lhs, u32 s) {
    return Vec4u(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
}



//==============================================================================
// Color4f
//==============================================================================

struct Color4f {
    f32 r;
    f32 g;
    f32 b;
    f32 a;

    inline Color4f () {
        this->r = 0;
        this->g = 0;
        this->b = 0;
        this->a = 0;
    }

    inline Color4f (const Color4f & rhs) {
        this->r = rhs.r;
        this->g = rhs.g;
        this->b = rhs.b;
        this->a = rhs.a;
    }

    inline Color4f (f32 r, f32 g, f32 b, f32 a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };

    inline Color4f (f32 v) {
        this->r = v;
        this->g = v;
        this->b = v;
        this->a = v;
    };

    inline const Color4f & operator = (const Color4f & rhs) {
        this->r = rhs.r;
        this->g = rhs.g;
        this->b = rhs.b;
        this->a = rhs.a;
        return *this;
    }

    inline const Color4f & operator += (const Color4f & rhs) {
        this->r += rhs.r;
        this->g += rhs.g;
        this->b += rhs.b;
        this->a += rhs.a;
        return *this;
    }

    inline const Color4f & operator -= (const Color4f & rhs) {
        this->r -= rhs.r;
        this->g -= rhs.g;
        this->b -= rhs.b;
        this->a -= rhs.a;
        return *this;
    }

    inline const Color4f & operator *= (const Color4f & rhs) {
        this->r *= rhs.r;
        this->g *= rhs.g;
        this->b *= rhs.b;
        this->a *= rhs.a;
        return *this;
    }

    inline const Color4f & operator /= (const Color4f & rhs) {
        this->r /= rhs.r;
        this->g /= rhs.g;
        this->b /= rhs.b;
        this->a /= rhs.a;
        return *this;
    }

    inline const Color4f & operator += (f32 s) {
        this->r += s;
        this->g += s;
        this->b += s;
        this->a += s;
        return *this;
    }

    inline const Color4f & operator -= (f32 s) {
        this->r -= s;
        this->g -= s;
        this->b -= s;
        this->a -= s;
        return *this;
    }

    inline const Color4f & operator *= (f32 s) {
        this->r *= s;
        this->g *= s;
        this->b *= s;
        this->a *= s;
        return *this;
    }

    inline const Color4f & operator /= (f32 s) {
        this->r /= s;
        this->g /= s;
        this->b /= s;
        this->a /= s;
        return *this;
    }
};

inline static Color4f operator + (const Color4f & lhs, const Color4f & rhs) {
    return Color4f(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b, lhs.a + rhs.a);
}

inline static Color4f operator - (const Color4f & lhs, const Color4f & rhs) {
    return Color4f(lhs.r - rhs.r, lhs.g - rhs.g, lhs.b - rhs.b, lhs.a - rhs.a);
}

inline static Color4f operator * (const Color4f & lhs, const Color4f & rhs) {
    return Color4f(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b, lhs.a * rhs.a);
}

inline static Color4f operator / (const Color4f & lhs, const Color4f & rhs) {
    return Color4f(lhs.r / rhs.r, lhs.g / rhs.g, lhs.b / rhs.b, lhs.a / rhs.a);
}

inline static Color4f operator + (const Color4f & lhs, f32 s) {
    return Color4f(lhs.r + s, lhs.g + s, lhs.b + s, lhs.a + s);
}

inline static Color4f operator - (const Color4f & lhs, f32 s) {
    return Color4f(lhs.r - s, lhs.g - s, lhs.b - s, lhs.a - s);
}

inline static Color4f operator * (const Color4f & lhs, f32 s) {
    return Color4f(lhs.r * s, lhs.g * s, lhs.b * s, lhs.a * s);
}

inline static Color4f operator / (const Color4f & lhs, f32 s) {
    return Color4f(lhs.r / s, lhs.g / s, lhs.b / s, lhs.a / s);
}



//==============================================================================
// Color4b
//==============================================================================

struct Color4b {
    u8 r;
    u8 g;
    u8 b;
    u8 a;

    inline Color4b () {
        this->r = 0;
        this->g = 0;
        this->b = 0;
        this->a = 0;
    }

    inline Color4b (const Color4b & rhs) {
        this->r = rhs.r;
        this->g = rhs.g;
        this->b = rhs.b;
        this->a = rhs.a;
    }

    inline Color4b (u8 r, u8 g, u8 b, u8 a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };

    inline Color4b (u8 v) {
        this->r = v;
        this->g = v;
        this->b = v;
        this->a = v;
    };

    inline const Color4b & operator = (const Color4b & rhs) {
        this->r = rhs.r;
        this->g = rhs.g;
        this->b = rhs.b;
        this->a = rhs.a;
        return *this;
    }

    inline const Color4b & operator += (const Color4b & rhs) {
        this->r += rhs.r;
        this->g += rhs.g;
        this->b += rhs.b;
        this->a += rhs.a;
        return *this;
    }

    inline const Color4b & operator -= (const Color4b & rhs) {
        this->r -= rhs.r;
        this->g -= rhs.g;
        this->b -= rhs.b;
        this->a -= rhs.a;
        return *this;
    }

    inline const Color4b & operator *= (const Color4b & rhs) {
        this->r *= rhs.r;
        this->g *= rhs.g;
        this->b *= rhs.b;
        this->a *= rhs.a;
        return *this;
    }

    inline const Color4b & operator /= (const Color4b & rhs) {
        this->r /= rhs.r;
        this->g /= rhs.g;
        this->b /= rhs.b;
        this->a /= rhs.a;
        return *this;
    }

    inline const Color4b & operator += (u8 s) {
        this->r += s;
        this->g += s;
        this->b += s;
        this->a += s;
        return *this;
    }

    inline const Color4b & operator -= (u8 s) {
        this->r -= s;
        this->g -= s;
        this->b -= s;
        this->a -= s;
        return *this;
    }

    inline const Color4b & operator *= (u8 s) {
        this->r *= s;
        this->g *= s;
        this->b *= s;
        this->a *= s;
        return *this;
    }

    inline const Color4b & operator /= (u8 s) {
        this->r /= s;
        this->g /= s;
        this->b /= s;
        this->a /= s;
        return *this;
    }
};

inline static Color4b operator + (const Color4b & lhs, const Color4b & rhs) {
    return Color4b(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b, lhs.a + rhs.a);
}

inline static Color4b operator - (const Color4b & lhs, const Color4b & rhs) {
    return Color4b(lhs.r - rhs.r, lhs.g - rhs.g, lhs.b - rhs.b, lhs.a - rhs.a);
}

inline static Color4b operator * (const Color4b & lhs, const Color4b & rhs) {
    return Color4b(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b, lhs.a * rhs.a);
}

inline static Color4b operator / (const Color4b & lhs, const Color4b & rhs) {
    return Color4b(lhs.r / rhs.r, lhs.g / rhs.g, lhs.b / rhs.b, lhs.a / rhs.a);
}

inline static Color4b operator + (const Color4b & lhs, u8 s) {
    return Color4b(lhs.r + s, lhs.g + s, lhs.b + s, lhs.a + s);
}

inline static Color4b operator - (const Color4b & lhs, u8 s) {
    return Color4b(lhs.r - s, lhs.g - s, lhs.b - s, lhs.a - s);
}

inline static Color4b operator * (const Color4b & lhs, u8 s) {
    return Color4b(lhs.r * s, lhs.g * s, lhs.b * s, lhs.a * s);
}

inline static Color4b operator / (const Color4b & lhs, u8 s) {
    return Color4b(lhs.r / s, lhs.g / s, lhs.b / s, lhs.a / s);
}


