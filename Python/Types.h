struct Vec2f {
    float x;
    float y;

    inline Vec2f () { }

    inline Vec2f (const Vec2f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2f (float x, float y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2f (float v) {
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

    inline const Vec2f & operator += (float s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2f & operator -= (float s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2f & operator *= (float s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2f & operator /= (float s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }

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

    inline static Vec2f operator + (const Vec2f & lhs, float s) {
        return Vec2f(lhs.x + s, lhs.y + s);
    }

    inline static Vec2f operator - (const Vec2f & lhs, float s) {
        return Vec2f(lhs.x - s, lhs.y - s);
    }

    inline static Vec2f operator * (const Vec2f & lhs, float s) {
        return Vec2f(lhs.x * s, lhs.y * s);
    }

    inline static Vec2f operator / (const Vec2f & lhs, float s) {
        return Vec2f(lhs.x / s, lhs.y / s);
    }
};


struct Vec3f {
    float x;
    float y;
    float z;

    inline Vec3f () { }

    inline Vec3f (const Vec3f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3f (float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3f (float v) {
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

    inline const Vec3f & operator += (float s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3f & operator -= (float s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3f & operator *= (float s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3f & operator /= (float s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }

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

    inline static Vec3f operator + (const Vec3f & lhs, float s) {
        return Vec3f(lhs.x + s, lhs.y + s, lhs.z + s);
    }

    inline static Vec3f operator - (const Vec3f & lhs, float s) {
        return Vec3f(lhs.x - s, lhs.y - s, lhs.z - s);
    }

    inline static Vec3f operator * (const Vec3f & lhs, float s) {
        return Vec3f(lhs.x * s, lhs.y * s, lhs.z * s);
    }

    inline static Vec3f operator / (const Vec3f & lhs, float s) {
        return Vec3f(lhs.x / s, lhs.y / s, lhs.z / s);
    }
};


struct Vec4f {
    float x;
    float y;
    float z;
    float w;

    inline Vec4f () { }

    inline Vec4f (const Vec4f & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4f (float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4f (float v) {
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

    inline const Vec4f & operator += (float s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4f & operator -= (float s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4f & operator *= (float s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4f & operator /= (float s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }

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

    inline static Vec4f operator + (const Vec4f & lhs, float s) {
        return Vec4f(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
    }

    inline static Vec4f operator - (const Vec4f & lhs, float s) {
        return Vec4f(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
    }

    inline static Vec4f operator * (const Vec4f & lhs, float s) {
        return Vec4f(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
    }

    inline static Vec4f operator / (const Vec4f & lhs, float s) {
        return Vec4f(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
    }
};


struct Vec2d {
    double x;
    double y;

    inline Vec2d () { }

    inline Vec2d (const Vec2d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2d (double x, double y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2d (double v) {
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

    inline const Vec2d & operator += (double s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2d & operator -= (double s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2d & operator *= (double s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2d & operator /= (double s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }

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

    inline static Vec2d operator + (const Vec2d & lhs, double s) {
        return Vec2d(lhs.x + s, lhs.y + s);
    }

    inline static Vec2d operator - (const Vec2d & lhs, double s) {
        return Vec2d(lhs.x - s, lhs.y - s);
    }

    inline static Vec2d operator * (const Vec2d & lhs, double s) {
        return Vec2d(lhs.x * s, lhs.y * s);
    }

    inline static Vec2d operator / (const Vec2d & lhs, double s) {
        return Vec2d(lhs.x / s, lhs.y / s);
    }
};


struct Vec3d {
    double x;
    double y;
    double z;

    inline Vec3d () { }

    inline Vec3d (const Vec3d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3d (double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3d (double v) {
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

    inline const Vec3d & operator += (double s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3d & operator -= (double s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3d & operator *= (double s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3d & operator /= (double s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }

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

    inline static Vec3d operator + (const Vec3d & lhs, double s) {
        return Vec3d(lhs.x + s, lhs.y + s, lhs.z + s);
    }

    inline static Vec3d operator - (const Vec3d & lhs, double s) {
        return Vec3d(lhs.x - s, lhs.y - s, lhs.z - s);
    }

    inline static Vec3d operator * (const Vec3d & lhs, double s) {
        return Vec3d(lhs.x * s, lhs.y * s, lhs.z * s);
    }

    inline static Vec3d operator / (const Vec3d & lhs, double s) {
        return Vec3d(lhs.x / s, lhs.y / s, lhs.z / s);
    }
};


struct Vec4d {
    double x;
    double y;
    double z;
    double w;

    inline Vec4d () { }

    inline Vec4d (const Vec4d & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4d (double x, double y, double z, double w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4d (double v) {
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

    inline const Vec4d & operator += (double s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4d & operator -= (double s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4d & operator *= (double s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4d & operator /= (double s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }

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

    inline static Vec4d operator + (const Vec4d & lhs, double s) {
        return Vec4d(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
    }

    inline static Vec4d operator - (const Vec4d & lhs, double s) {
        return Vec4d(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
    }

    inline static Vec4d operator * (const Vec4d & lhs, double s) {
        return Vec4d(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
    }

    inline static Vec4d operator / (const Vec4d & lhs, double s) {
        return Vec4d(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
    }
};


struct Vec2i {
    int x;
    int y;

    inline Vec2i () { }

    inline Vec2i (const Vec2i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2i (int x, int y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2i (int v) {
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

    inline const Vec2i & operator += (int s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2i & operator -= (int s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2i & operator *= (int s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2i & operator /= (int s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }

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

    inline static Vec2i operator + (const Vec2i & lhs, int s) {
        return Vec2i(lhs.x + s, lhs.y + s);
    }

    inline static Vec2i operator - (const Vec2i & lhs, int s) {
        return Vec2i(lhs.x - s, lhs.y - s);
    }

    inline static Vec2i operator * (const Vec2i & lhs, int s) {
        return Vec2i(lhs.x * s, lhs.y * s);
    }

    inline static Vec2i operator / (const Vec2i & lhs, int s) {
        return Vec2i(lhs.x / s, lhs.y / s);
    }
};


struct Vec3i {
    int x;
    int y;
    int z;

    inline Vec3i () { }

    inline Vec3i (const Vec3i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3i (int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3i (int v) {
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

    inline const Vec3i & operator += (int s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3i & operator -= (int s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3i & operator *= (int s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3i & operator /= (int s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }

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

    inline static Vec3i operator + (const Vec3i & lhs, int s) {
        return Vec3i(lhs.x + s, lhs.y + s, lhs.z + s);
    }

    inline static Vec3i operator - (const Vec3i & lhs, int s) {
        return Vec3i(lhs.x - s, lhs.y - s, lhs.z - s);
    }

    inline static Vec3i operator * (const Vec3i & lhs, int s) {
        return Vec3i(lhs.x * s, lhs.y * s, lhs.z * s);
    }

    inline static Vec3i operator / (const Vec3i & lhs, int s) {
        return Vec3i(lhs.x / s, lhs.y / s, lhs.z / s);
    }
};


struct Vec4i {
    int x;
    int y;
    int z;
    int w;

    inline Vec4i () { }

    inline Vec4i (const Vec4i & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4i (int x, int y, int z, int w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4i (int v) {
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

    inline const Vec4i & operator += (int s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4i & operator -= (int s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4i & operator *= (int s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4i & operator /= (int s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }

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

    inline static Vec4i operator + (const Vec4i & lhs, int s) {
        return Vec4i(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
    }

    inline static Vec4i operator - (const Vec4i & lhs, int s) {
        return Vec4i(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
    }

    inline static Vec4i operator * (const Vec4i & lhs, int s) {
        return Vec4i(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
    }

    inline static Vec4i operator / (const Vec4i & lhs, int s) {
        return Vec4i(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
    }
};


struct Vec2u {
    unsigned x;
    unsigned y;

    inline Vec2u () { }

    inline Vec2u (const Vec2u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }

    inline Vec2u (unsigned x, unsigned y) {
        this->x = x;
        this->y = y;
    };

    inline Vec2u (unsigned v) {
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

    inline const Vec2u & operator += (unsigned s) {
        this->x += s;
        this->y += s;
        return *this;
    }

    inline const Vec2u & operator -= (unsigned s) {
        this->x -= s;
        this->y -= s;
        return *this;
    }

    inline const Vec2u & operator *= (unsigned s) {
        this->x *= s;
        this->y *= s;
        return *this;
    }

    inline const Vec2u & operator /= (unsigned s) {
        this->x /= s;
        this->y /= s;
        return *this;
    }

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

    inline static Vec2u operator + (const Vec2u & lhs, unsigned s) {
        return Vec2u(lhs.x + s, lhs.y + s);
    }

    inline static Vec2u operator - (const Vec2u & lhs, unsigned s) {
        return Vec2u(lhs.x - s, lhs.y - s);
    }

    inline static Vec2u operator * (const Vec2u & lhs, unsigned s) {
        return Vec2u(lhs.x * s, lhs.y * s);
    }

    inline static Vec2u operator / (const Vec2u & lhs, unsigned s) {
        return Vec2u(lhs.x / s, lhs.y / s);
    }
};


struct Vec3u {
    unsigned x;
    unsigned y;
    unsigned z;

    inline Vec3u () { }

    inline Vec3u (const Vec3u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline Vec3u (unsigned x, unsigned y, unsigned z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    inline Vec3u (unsigned v) {
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

    inline const Vec3u & operator += (unsigned s) {
        this->x += s;
        this->y += s;
        this->z += s;
        return *this;
    }

    inline const Vec3u & operator -= (unsigned s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        return *this;
    }

    inline const Vec3u & operator *= (unsigned s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        return *this;
    }

    inline const Vec3u & operator /= (unsigned s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        return *this;
    }

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

    inline static Vec3u operator + (const Vec3u & lhs, unsigned s) {
        return Vec3u(lhs.x + s, lhs.y + s, lhs.z + s);
    }

    inline static Vec3u operator - (const Vec3u & lhs, unsigned s) {
        return Vec3u(lhs.x - s, lhs.y - s, lhs.z - s);
    }

    inline static Vec3u operator * (const Vec3u & lhs, unsigned s) {
        return Vec3u(lhs.x * s, lhs.y * s, lhs.z * s);
    }

    inline static Vec3u operator / (const Vec3u & lhs, unsigned s) {
        return Vec3u(lhs.x / s, lhs.y / s, lhs.z / s);
    }
};


struct Vec4u {
    unsigned x;
    unsigned y;
    unsigned z;
    unsigned w;

    inline Vec4u () { }

    inline Vec4u (const Vec4u & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
    }

    inline Vec4u (unsigned x, unsigned y, unsigned z, unsigned w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };

    inline Vec4u (unsigned v) {
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

    inline const Vec4u & operator += (unsigned s) {
        this->x += s;
        this->y += s;
        this->z += s;
        this->w += s;
        return *this;
    }

    inline const Vec4u & operator -= (unsigned s) {
        this->x -= s;
        this->y -= s;
        this->z -= s;
        this->w -= s;
        return *this;
    }

    inline const Vec4u & operator *= (unsigned s) {
        this->x *= s;
        this->y *= s;
        this->z *= s;
        this->w *= s;
        return *this;
    }

    inline const Vec4u & operator /= (unsigned s) {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
        return *this;
    }

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

    inline static Vec4u operator + (const Vec4u & lhs, unsigned s) {
        return Vec4u(lhs.x + s, lhs.y + s, lhs.z + s, lhs.w + s);
    }

    inline static Vec4u operator - (const Vec4u & lhs, unsigned s) {
        return Vec4u(lhs.x - s, lhs.y - s, lhs.z - s, lhs.w - s);
    }

    inline static Vec4u operator * (const Vec4u & lhs, unsigned s) {
        return Vec4u(lhs.x * s, lhs.y * s, lhs.z * s, lhs.w * s);
    }

    inline static Vec4u operator / (const Vec4u & lhs, unsigned s) {
        return Vec4u(lhs.x / s, lhs.y / s, lhs.z / s, lhs.w / s);
    }
};


struct Color4f {
    float r;
    float g;
    float b;
    float a;

    inline Color4f () { }

    inline Color4f (const Color4f & rhs) {
        this->r = rhs.r;
        this->g = rhs.g;
        this->b = rhs.b;
        this->a = rhs.a;
    }

    inline Color4f (float r, float g, float b, float a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };

    inline Color4f (float v) {
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

    inline const Color4f & operator += (float s) {
        this->r += s;
        this->g += s;
        this->b += s;
        this->a += s;
        return *this;
    }

    inline const Color4f & operator -= (float s) {
        this->r -= s;
        this->g -= s;
        this->b -= s;
        this->a -= s;
        return *this;
    }

    inline const Color4f & operator *= (float s) {
        this->r *= s;
        this->g *= s;
        this->b *= s;
        this->a *= s;
        return *this;
    }

    inline const Color4f & operator /= (float s) {
        this->r /= s;
        this->g /= s;
        this->b /= s;
        this->a /= s;
        return *this;
    }

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

    inline static Color4f operator + (const Color4f & lhs, float s) {
        return Color4f(lhs.r + s, lhs.g + s, lhs.b + s, lhs.a + s);
    }

    inline static Color4f operator - (const Color4f & lhs, float s) {
        return Color4f(lhs.r - s, lhs.g - s, lhs.b - s, lhs.a - s);
    }

    inline static Color4f operator * (const Color4f & lhs, float s) {
        return Color4f(lhs.r * s, lhs.g * s, lhs.b * s, lhs.a * s);
    }

    inline static Color4f operator / (const Color4f & lhs, float s) {
        return Color4f(lhs.r / s, lhs.g / s, lhs.b / s, lhs.a / s);
    }
};


struct Color4b {
    byte r;
    byte g;
    byte b;
    byte a;

    inline Color4b () { }

    inline Color4b (const Color4b & rhs) {
        this->r = rhs.r;
        this->g = rhs.g;
        this->b = rhs.b;
        this->a = rhs.a;
    }

    inline Color4b (byte r, byte g, byte b, byte a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };

    inline Color4b (byte v) {
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

    inline const Color4b & operator += (byte s) {
        this->r += s;
        this->g += s;
        this->b += s;
        this->a += s;
        return *this;
    }

    inline const Color4b & operator -= (byte s) {
        this->r -= s;
        this->g -= s;
        this->b -= s;
        this->a -= s;
        return *this;
    }

    inline const Color4b & operator *= (byte s) {
        this->r *= s;
        this->g *= s;
        this->b *= s;
        this->a *= s;
        return *this;
    }

    inline const Color4b & operator /= (byte s) {
        this->r /= s;
        this->g /= s;
        this->b /= s;
        this->a /= s;
        return *this;
    }

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

    inline static Color4b operator + (const Color4b & lhs, byte s) {
        return Color4b(lhs.r + s, lhs.g + s, lhs.b + s, lhs.a + s);
    }

    inline static Color4b operator - (const Color4b & lhs, byte s) {
        return Color4b(lhs.r - s, lhs.g - s, lhs.b - s, lhs.a - s);
    }

    inline static Color4b operator * (const Color4b & lhs, byte s) {
        return Color4b(lhs.r * s, lhs.g * s, lhs.b * s, lhs.a * s);
    }

    inline static Color4b operator / (const Color4b & lhs, byte s) {
        return Color4b(lhs.r / s, lhs.g / s, lhs.b / s, lhs.a / s);
    }
};


