#ifndef MAT2_CPP
#define MAT2_CPP
#include "vec2.hpp"
#include "mat2.hpp"
#include <iostream>
#include <math.h>

Mat2::Mat2():
    s1{Vec2{}},
    s2{Vec2{}}
{}

Mat2::Mat2(Vec2 const& v1,Vec2 const& v2):
    s1{v1},
    s2{v2}
{}

Mat2::Mat2(Mat2 const& m):
    s1{m.s1},
    s2{m.s2}
{}

Mat2& Mat2::operator*= (Mat2 const& m){

    Mat2 calc;
    calc.s1.x = ((s1.x)*(m.s1.x))+((s2.x)*(m.s1.y));
    calc.s1.y = ((s1.y)*(m.s1.x))+((s2.y)*(m.s1.y));
    calc.s2.x = ((s1.x)*(m.s2.x))+((s2.x)*(m.s2.y));
    calc.s2.y = ((s1.y)*(m.s2.x))+((s2.y)*(m.s2.y));
    s1 = calc.s1;
    s2 = calc.s2;
    return *this;
}

Mat2& Mat2::operator*= (float s)
{
    s1.x = s1.x * s;
    s1.y = s1.y * s;
    s2.x = s2.x * s;
    s2.y = s2.y * s;
    return *this;
}

Mat2 operator* (Mat2 const& m1, Mat2 const& m2)
{
    Mat2 calc;
    calc.s1.x = ((m1.s1.x)*(m2.s1.x))+((m1.s2.x)*(m2.s1.y));
    calc.s1.y = ((m1.s1.y)*(m2.s1.x))+((m1.s2.y)*(m2.s1.y));
    calc.s2.x = ((m1.s1.x)*(m2.s2.x))+((m1.s2.x)*(m2.s2.y));
    calc.s2.y = ((m1.s1.y)*(m2.s2.x))+((m1.s2.y)*(m2.s2.y));
    return calc;
}

Mat2 operator* (Mat2 const& m,float s)
{
    Mat2 calc;
    calc.s1.x = m.s1.x * s;
    calc.s1.y = m.s1.y * s;
    calc.s2.x = m.s2.x * s;
    calc.s2.y = m.s2.y * s;
    return calc;
}

Mat2 operator* (float s, Mat2 const& m)
{
    Mat2 calc;
    calc.s1.x = m.s1.x * s;
    calc.s1.y = m.s1.y * s;
    calc.s2.x = m.s2.x * s;
    calc.s2.y = m.s2.y * s;
    return calc;
}

Vec2 operator* (Mat2 const& m1, Vec2 const& v)
{
    Vec2 calc;
    calc.x = v.x * m1.s1.x + v.y * m1.s2.x;
    calc.y = v.x * m1.s1.y + v.y * m1.s2.y;
    return calc; 
}

Vec2 operator* (Vec2 const& v, Mat2 const& m1)
{
    Vec2 calc;
    calc.x = v.x * m1.s1.x + v.y * m1.s2.x;
    calc.y = v.x * m1.s1.y + v.y * m1.s2.y;
    return calc; 
}

Mat2 inverse(Mat2 const& m){
    
    Mat2 calc;

    if(m.det() != 0.0f){
        calc.s1 = Vec2{m.s2.y,-m.s1.y};
        calc.s2 = Vec2{-m.s2.x,m.s1.x};
        calc*=1/m.det();
    }
    else 
    {
        std::cout<<" matrix doesn't have inverse , det==0";
        return m;
    }
    
    return calc;
}

float Mat2::det()const{

    return (s1.x*s2.y)-(s2.x*s1.y);
}

Mat2 transpose(Mat2 const& m)
{
    return Mat2{Vec2{m.s1.x,m.s2.x},Vec2{m.s1.y,m.s2.y}};
}

Mat2 make_rotate_mat2(float phi)
{
    return Mat2{Vec2{(float)cos(phi),(float)sin(phi)},Vec2{(float)-sin(phi),(float)cos(phi)}};
}

#endif