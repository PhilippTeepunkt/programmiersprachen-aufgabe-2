#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle{
    
    public:

        Rectangle();
        Rectangle(Rectangle const& rect);
        Rectangle(Color const& color);
        Rectangle(Vec2 const& min,Vec2 const& max);
        Rectangle(Vec2 const& min,Vec2 const& max,Color const& color);

        Vec2 get_min() const;
        Vec2 get_max() const;
        Color get_color() const;
        Vec2 get_length() const;
        Vec2 get_width() const;

        float circumference() const;
        void draw(Window const& w);
        
    private:
    
        Vec2 min_;
        Vec2 max_;
        Color color_;
};

#endif