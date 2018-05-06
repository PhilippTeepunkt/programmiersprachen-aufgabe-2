# ifndef VEC2_HPP
# define VEC2_HPP

//#include "mat2.hpp"

// Vec2 class definition
struct Vec2
{
    public:
        Vec2();
        Vec2(Vec2 const& v);
        Vec2(float s1,float s2);

        Vec2& operator+= (Vec2 const& v);
        Vec2& operator-= (Vec2 const& v);
        Vec2& operator*= (float s);
        Vec2& operator/= (float s);

        // TODO Constructors
        float x;
        float y;
};

Vec2 operator + (Vec2 const& u, Vec2 const& v);
Vec2 operator - (Vec2 const& u, Vec2 const& v);
Vec2 operator * (Vec2 const& u, float s);
Vec2 operator / (Vec2 const& u, float s);
Vec2 operator * (float s, Vec2 const& v);
float length(Vec2 const& v);

# endif // VEC2_HPP