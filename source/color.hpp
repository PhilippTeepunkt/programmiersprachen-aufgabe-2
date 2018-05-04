#ifndef COLOR_HPP
#define COLOR_HPP

#include<iostream>

struct Color{

    float _r;
    float _g;
    float _b;

    Color{float value}{
        if(value<0&&value>1){
            std::cout<<"The value is not a valid inut! black was constructed instead! ";
            _r = 0.0f;
            _g = 0.0f;
            _b = 0.0f;
        }

        else
        {
            _r = value;
            _g = value;
            _b = value;
        }
    };

    Color{float r,float g,float b}{
        
        if(r,g,b>1&&r,g,b<0){

            std::cout<<"The values are not a valid inut! black was constructed instead! ";
            _r = 0.0f;
            _g = 0.0f;
            _b = 0.0f;
        }
        else
        {
            _r = r;
            _g = g;
            _b = b;
        }

    }

    float r,g,b;
}
#endif