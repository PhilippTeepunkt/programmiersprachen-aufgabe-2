#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

#include <vector>

class Circle{
    
    public:

        Circle();
        Circle(Circle const& c);
        Circle(float radius);
        Circle(float radius,Color const& color);
        Circle(float radius,Vec2 const& center);
        Circle(float radius,Vec2 const& center,Color const& color);

        float get_radius() const;
        Vec2 get_center() const;
        Color get_color() const;

        void set_color();

        float circumference() const;
        void draw(Window const& w) const;
        void draw(Window const& w, Color const& c) const;
        void draw(Window const& w,float r, float g, float b) const;

        bool is_inside(Vec2 const& v)const;
        
    private:

        float radius_;
        Vec2 center_;
        Color color_;
};

#endif