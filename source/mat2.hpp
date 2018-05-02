#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

struct Mat2{

    public:

        Mat2();
        Mat2(Mat2 const& m);
        Mat2(Vec2 const& s1,Vec2 const& s2);

        Mat2& operator *=(Mat2 const& m);
        Mat2& operator *=(Vec2 const& v1);

        Vec2 s1;
        Vec2 s2;
};

Mat2 operator*(Mat2 const& m1,Mat2 const& m2);
/*Vec2 operator*(Mat2 const& m,Vec2 const& v1);
Vec2 operator*(Vec2 const& v1,Mat2 const& m);
*/
#endif