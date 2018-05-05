#ifndef CIRCLE_CPP
#define CIRCLE_CPP
#include "circle.hpp"

#include "vec2.hpp"
#include "color.hpp"
#include <math.h>

Circle::Circle():

    radius_(1.0f),
    center_(Vec2{0.0f,0.0f}),
    color_(Color{0.0f})
{};

Circle::Circle(Circle const& c):
    radius_{c.get_radius()},
    center_{c.get_center()},
    color_{c.get_color()}
{};

Circle::Circle(float radius):
    radius_{radius},
    center_{Vec2{0.0f,0.0f}},
    color_{Color{0.0f}}
{};

Circle::Circle(float radius, Color const& color):
    radius_{radius},
    center_{Vec2{0.0f,0.0f}},
    color_{color}
{};

Circle::Circle(float radius, Vec2 const& center):
    radius_{radius},
    center_{center},
    color_{Color{0.0f}}
{};

Circle::Circle(float radius,Vec2 const& center, Color const& color):
    radius_{radius},
    center_{center},
    color_{color}
{};

float Circle::get_radius()const
{
    return radius_;
}

Vec2 Circle::get_center()const
{
    return center_;
}

Color Circle::get_color()const
{
    return color_;
}

float Circle::circumference()const
{
    return 2 * (float)M_PI * radius_;
}

#endif