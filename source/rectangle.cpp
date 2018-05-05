#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#include "rectangle.hpp"

#include "vec2.hpp"
#include "color.hpp"

Rectangle::Rectangle():
    min_{Vec2{0.0f,0.0f}},
    max_{Vec2{1.0f,1.0f}},
    color_{Color{0.0f}}
{};

Rectangle::Rectangle(Rectangle const& rectangle):
    min_{rectangle.get_min()},
    max_{rectangle.get_max()},
    color_{rectangle.get_color()}
{};

Rectangle::Rectangle(Color const& color):
    min_{Vec2{0.0f,0.0f}},
    max_{Vec2{1.0f,1.0f}},
    color_(color)
{};

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
    min_{min},
    max_{max},
    color_{Color{0.0f}}
{};

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color):
    min_{min},
    max_{max},
    color_{color}
{};

Vec2 Rectangle::get_length() const
{
    return Vec2{0,max_.y-min_.y};
}

Vec2 Rectangle::get_width() const
{
    return Vec2{max_.x-min_.x,0};
}

Vec2 Rectangle::get_min() const
{
    return min_;
}

Vec2 Rectangle::get_max() const
{
    return max_;
}

Color Rectangle::get_color() const
{
    return color_;
}

float Rectangle::circumference()const
{
    return 2 * get_length().y + 2 * get_width().x;
}

#endif