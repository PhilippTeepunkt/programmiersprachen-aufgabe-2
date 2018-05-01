#ifndef VEC_CPP
#define VEC_CPP

#include "vec2.hpp"

Vec2::Vec2():
    x{0.0f},
    y{0.0f}
{};

Vec2::Vec2(float mx, float my):
    x{mx},
    y{my}
{};

Vec2& Vec2::operator +=(Vec2 const& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::operator -=(Vec2 const& v){
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator *=(float s){
    x *= s;
    y *= s;
    return *this;
}

Vec2& Vec2::operator /=(float s){
    x /= s;
    y /= s;
    return *this;
}

#endif


