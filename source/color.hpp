#ifndef COLOR_HPP
#define COLOR_HPP

#include<iostream>

struct Color{

    Color(float value){
        if(value<0.0f||value>1.0f){
            std::cout<<"The value is not a valid inut! black was constructed instead!\n";
            r_ = 0.0f;
            g_ = 0.0f;
            b_ = 0.0f;
        }

        else
        {
            r_ = value;
            g_ = value;
            b_ = value;
        }
    };

    Color(float r,float g,float b){

        if(r>1.0f||r<0.0f||g>1.0f||g<0.0f||b<0.0f||b>1.0f){

            std::cout<<"The values are not a valid inut! black was constructed instead!\n";
            r_ = 0.0f;
            g_ = 0.0f;
            b_ = 0.0f;
        }
        else
        {
            r_ = r;
            g_ = g;
            b_ = b;
        }

    }

      float r_;
    float g_;
    float b_;
};
#endif