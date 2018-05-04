#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

struct Mat2{

    public:

        Mat2();
        Mat2(Mat2 const& m);
        Mat2(Vec2 const& s1,Vec2 const& s2);

        Mat2& operator *=(Mat2 const& m);
        Mat2& operator *=(float s);

        float det() const;

        Vec2 s1;
        Vec2 s2;
};

Mat2 operator * (Mat2 const& m1,Mat2 const& m2);
Vec2 operator * (Vec2 const& v, Mat2 const& m1);
Vec2 operator * (Mat2 const& m1,Vec2 const& v);
Mat2 operator * (Mat2 const& m1,float s);
Mat2 operator * (float s,Mat2 const& m1);
Mat2 inverse (Mat2 const& m);
Mat2 transpose (Mat2 const& m);
Mat2 make_rotate_mat2(float phi);

#endif