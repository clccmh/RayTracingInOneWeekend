#ifndef vec3_h
#define vec3_h
#include <math.h>

class vec3 {
  public:
    float x;
    float y;
    float z;
    vec3();

    vec3(float x1, float y1, float z1) {
      x = x1;
      y = y1;
      z = z1;
    }

    inline vec3 operator-() const {
      return vec3(-x, -y, -z);
    }

    inline float length() const {
      return sqrt(x*x + y*y + z*z);
    }

    inline float squared_length() const {
      return x*x + y*y + z*z;
    }

    inline vec3& operator+= (const vec3& v) {
      x += v.x;
      y += v.y;
      z += v.z;
      return *this;
    }

    inline vec3& operator-= (const vec3& v) {
      x -= v.x;
      y -= v.y;
      z -= v.z;
      return *this;
    }

    inline vec3& operator*= (const vec3& v) {
      x *= v.x;
      y *= v.y;
      z *= v.z;
      return *this;
    }

    inline vec3& operator/= (const vec3& v) {
      x /= v.x;
      y /= v.y;
      z /= v.z;
      return *this;
    }

    inline vec3& operator*= (const float t) {
      x *= t;
      y *= t;
      z *= t;
      return *this;
    }

    inline vec3& operator/= (const float t) {
      x /= t;
      y /= t;
      z /= t;
      return *this;
    }

    inline vec3 operator+(const vec3& v) {
      return vec3(x + v.x, y + v.y, z + v.z);
    }

    inline vec3 operator-(const vec3& v) {
      return vec3(x - v.x, y - v.y, z - v.z);
    }

    inline vec3 operator*(const vec3& v) {
      return vec3(x * v.x, y * v.y, z * v.z);
    }

    inline vec3 operator/(const vec3& v) {
      return vec3(x/v.x, y/v.y, z/v.z);
    }

    inline vec3 operator*(const float t) {
      return vec3(x * t, y * t, z * t);
    }

    inline vec3 operator/(const float t) {
      return vec3(x / t, y / t, z / t);
    }

    inline float dot(const vec3& v) {
      return (x * v.x) + (y * v.y) + (z * v.z);
    }

    inline vec3 cross(const vec3& v) {
      return vec3((y * v.z - z * v.y),
                  (-(x * v.z - z * v.x)),
                  (x * v.y - y * v.x));
    }

    inline vec3 unit_vector() {
      return *this / *this.length();
    }

};

inline std::istream& operator>>(std::istream& is, vec3& t) {
  is >> t.x >> t.y >> t.z;
  return is;
}

inline std::ostream& operator<<(std::ostream& os, const vec3& t) {
  os << "<" << t.x << ", " << t.y << ", " << t.z << ">";
  return os;
}

#endif
