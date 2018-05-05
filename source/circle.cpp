#ifndef CIRCLE_CPP
#define CIRCLE_CPP
#include "circle.hpp"

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
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

void Circle::draw(Window const& w)const
{
    Vec2 start{};
    Vec2 end{};
    Color c{0.0f};
    c = get_color();
    
    for(int i =0; i<=360; i++)
    {
        start = {(float)sin((2*M_PI*i)/360)*get_radius()+center_.x,(float)cos((2*M_PI*i)/360)*get_radius()+center_.y};
        end = {(float)sin(((i+1)*2*M_PI)/360)*get_radius()+center_.x,(float)cos(((i+1)*2*M_PI)/360)*get_radius()+center_.y};
        w.draw_line(start.x,start.y,end.x,end.y,c.r_,c.g_,c.b_);
    }
}

#endif