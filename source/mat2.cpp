#ifndef MAT2_CPP
#define MAT2_CPP
#include "vec2.hpp"
#include "mat2.hpp"
#include <iostream>

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

Mat2& Mat2::operator*= (Mat2 const& m)
{   
    Mat2 calc;
    calc.s1.x = ((s1.x)*(m.s1.x))+((s2.x)*(m.s1.y));
    calc.s1.y = ((s1.y)*(m.s1.x))+((s2.y)*(m.s1.y));
    calc.s2.x = ((s1.x)*(m.s2.x))+((s2.x)*(m.s2.y));
    calc.s2.y = ((s1.y)*(m.s2.x))+((s2.y)*(m.s2.y));
    s1 = calc.s1;
    s2 = calc.s2;
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
#endif