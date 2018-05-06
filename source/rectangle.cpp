#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#include "rectangle.hpp"

#include "vec2.hpp"
#include "color.hpp"

#include <vector>

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

void Rectangle::draw(Window const& w) const
{
    Color c = get_color();
    w.draw_line(get_min().x,get_min().y,get_min().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_min().x,get_max().y,get_max().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_max().y,get_max().x,get_min().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_min().y,get_min().x,get_min().y,c.r_,c.g_,c.b_);
}

void Rectangle::draw(Window const& w, Color const& c ) const
{
    w.draw_line(get_min().x,get_min().y,get_min().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_min().x,get_max().y,get_max().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_max().y,get_max().x,get_min().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_min().y,get_min().x,get_min().y,c.r_,c.g_,c.b_);
}

void Rectangle::draw(Window const& w, float r, float g, float b) const
{
    Color c{r,g,b};
    w.draw_line(get_min().x,get_min().y,get_min().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_min().x,get_max().y,get_max().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_max().y,get_max().x,get_min().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_min().y,get_min().x,get_min().y,c.r_,c.g_,c.b_);
}

bool Rectangle::is_inside(Vec2 const& vec)const
{
    if((vec-get_min()).x<=get_width().x&&(vec-get_min()).y <=get_length().y)
    {
        return true;
    }
    return false;
}

#endif