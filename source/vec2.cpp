#ifndef VEC2_CPP
#define VEC2_CPP

#include "vec2.hpp"
#include "mat2.hpp"
#include <iostream>

//Aufgabe 2.2

Vec2::Vec2():
    x{0.0f},
    y{0.0f}
{}

Vec2::Vec2(Vec2 const& v):
    x{v.x},
    y{v.y}
{}

Vec2::Vec2(float mx, float my):
    x{mx},
    y{my}
{}

//Aufgabe 2.3

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
    if(s==0.0f){
        std::cout<<"Division through zero!! Nothing calculated!\n";
        return *this;
    }
    else{
        x /= s;
        y /= s;
    }
    return *this;
}

//Aufgabe 2.4

Vec2 operator+(Vec2 const& u,Vec2 const& v){
    Vec2 calc;
    calc.x = u.x + v.x;
    calc.y = u.y + v.y;
    return calc;
}

Vec2 operator-(Vec2 const& u,Vec2 const& v){
    Vec2 calc;
    calc.x = u.x - v.x;
    calc.y = u.y - v.y;
    return calc;
}

Vec2 operator*(Vec2 const& u,float s){
    Vec2 calc;
    calc.x = u.x *s;
    calc.y = u.y *s;
    return calc;
}


Vec2 operator/(Vec2 const& u, float s){
    Vec2 calc = u;
    if(s==0.0f){
        std::cout<<"Division through zero!! Nothing calculated!\n";
        return calc;
    }
    else{
        calc.x = u.x / s;
    calc.y = u.y / s;
    return calc;
    }
}


Vec2 operator*(float s,Vec2 const& v){
    Vec2 calc;
    calc.x = s * v.x;
    calc.y = s * v.y;
    return calc;
}

#endif


