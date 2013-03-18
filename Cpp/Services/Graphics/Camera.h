//==============================================================================
// Camera.h
// Paul Marden (2/20/2012)
//==============================================================================

struct Vec3f;


template<typename T>
class Editable {
public:
    inline Editable ()                 { }
    inline Editable (const T & rhs)    { m_data = rhs; }
    
    inline operator T ()               { return m_data; }
    inline operator T () const         { return m_data; }
    
    inline const T & operator = (const T & rhs)    { m_data = rhs;  return m_data; }
    inline const T & operator += (const T & rhs)   { m_data += rhs; return m_data; }
    inline const T & operator -= (const T & rhs)   { m_data -= rhs; return m_data; }
    inline const T & operator *= (const T & rhs)   { m_data *= rhs; return m_data; }
    inline const T & operator /= (const T & rhs)   { m_data /= rhs; return m_data; }

private:
    T m_data;
};

class COrbitalCamera {
public:
    COrbitalCamera ();

    void ComputePosition (Vec3f * eye, Vec3f * target) const;

    void LookAt (const Vec3f & target);

    float GetDistance () const              { return m_distance;        }
    float GetAzimuth () const               { return m_azimuth;         }
    float GetElevation () const             { return m_elevation;       }

    void AdjustDistance (float amount)      { m_distance  += amount;    }
    void AdjustAzimuth (float amount)       { m_azimuth   += amount;    }
    void AdjustElevation (float amount)     { m_elevation += amount;    }

    void SetDistance (float distance)       { m_distance  = distance;   }
    void SetAzimuth (float azimuth)         { m_azimuth   = azimuth;    }
    void SetElevation (float elevation)     { m_elevation = elevation;  }

private:
    Editable<float> m_elevation;
    Editable<float> m_azimuth;
    Editable<float> m_distance;
};
