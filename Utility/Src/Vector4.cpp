#include "Vector4.h"
#include <cmath>

namespace Utility
{
    Vector4 Vector4::one(1.0f, 1.0f, 1.0f, 1.0f);
    Vector4 Vector4::zero(0.0f, 0.0f, 0.0f, 0.0f);

    const float Vector4::magnitude() const
    {
        return std::sqrtf(x * x + y * y + z * z + w * w);
    }
    const Vector4 Vector4::normalized() const
    {
        float _mag = magnitude();
        return Vector4(
            x / _mag,
            y / _mag,
            z / _mag,
            w / _mag
        );
    }
    const float Vector4::sqrMagnitude() const
    {
        return x * x + y * y + z * z + w * w;
    }
    const Vector4 Vector4::inverse() const
    {
        return Vector4(-x, -y, -z, -w);
    }
    void Vector4::Set(float _x, float _y, float _z, float _w)
    {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }
    const float Vector4::Distance(const Vector4& vec4_0, const Vector4& vec4_1)
    {
        return std::sqrtf(
            std::powf(vec4_0.x - vec4_1.x, 2.0f) + 
            std::powf(vec4_0.y - vec4_1.y, 2.0f) + 
            std::powf(vec4_0.z - vec4_1.z, 2.0f) + 
            std::powf(vec4_0.w - vec4_1.w, 2.0f)
        );
    }
    const float Vector4::Dot(const Vector4& vec4_0, const Vector4& vec4_1)
    {
        return (vec4_0.x * vec4_1.x) + (vec4_0.y * vec4_1.y) + (vec4_0.z * vec4_1.z) + (vec4_0.w * vec4_1.w);
    }
    const Vector4 Vector4::Max(const Vector4& vec4_0, const Vector4& vec4_1)
    {
        return Vector4(
            (vec4_0.x < vec4_1.x) ? vec4_1.x : vec4_0.x,
            (vec4_0.y < vec4_1.y) ? vec4_1.y : vec4_0.y,
            (vec4_0.z < vec4_1.z) ? vec4_1.z : vec4_0.z,
            (vec4_0.w < vec4_1.w) ? vec4_1.w : vec4_0.w);
    }
    const Vector4 Vector4::Min(const Vector4& vec4_0, const Vector4& vec4_1)
    {
        return Vector4(
            (vec4_0.x > vec4_1.x) ? vec4_1.x : vec4_0.x,
            (vec4_0.y > vec4_1.y) ? vec4_1.y : vec4_0.y,
            (vec4_0.z > vec4_1.z) ? vec4_1.z : vec4_0.z,
            (vec4_0.w > vec4_1.w) ? vec4_1.w : vec4_0.w);
    }
    const Vector4 Vector4::Scale(const Vector4& vec4_0, const Vector4& vec4_1)
    {
        return Vector4(
            vec4_0.x * vec4_1.x,
            vec4_0.y * vec4_1.y,
            vec4_0.z * vec4_1.z,
            vec4_0.w * vec4_1.w 
        );
    }

  

}