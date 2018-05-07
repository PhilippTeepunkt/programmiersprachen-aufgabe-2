#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>

#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <vector>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

    Circle c1{100.0f,Vec2{400.0f,400.0f},Color{1.0f,0.0f,0.0f}};
    Circle c2{200.0f,Vec2{400.0f,400.0f},Color{0.0f,1.0f,0.0f}};
    Rectangle r1{Vec2{150.0f,50.0f},Vec2{350.0f,150.0f},Color{0.0f,1.0f,0.0f}};
    Rectangle r2{Vec2{50.0f,200.0f},Vec2{100.0f,380.0f},Color{0.0f,1.0f,0.0f}};

    Vec2 hourHand{0.0f,-230.0f};
    Vec2 minHand{0.0f,-320.0f};
    Vec2 secHand{0.0f,-400.0f};  

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    std::vector<Circle> vc;
    std::vector<Rectangle> vr;

    //user defined    
    vc.push_back(c1);
    vc.push_back(c2);
    vr.push_back(r1);
    vr.push_back(r2);
    Color highlightColor{0.0f,0.0f,1.0f};

    float time = win.get_time();

    Mat2 hourHandRot = make_rotate_mat2(360/24*0.0174532925*(time/3600));
    Mat2 minHandRot = make_rotate_mat2(360/60*0.0174532925*(time/60));
    Mat2 secHandRot = make_rotate_mat2(360/60*0.0174532925*time);

    win.draw_line(400.0f,400.0f, (hourHand*hourHandRot).x+400.0f,(hourHand*hourHandRot).y+400.0f,1.0f,1.0f,1.0f);
    win.draw_line(400.0f,400.0f,(minHand*minHandRot).x+400.0f,(minHand*minHandRot).y+400.0f,1.0f,1.0f,0.0f);
    win.draw_line(400.0f,400.0f,(secHand*secHandRot).x+400.0f,(secHand*secHandRot).y+400.0f,0.5f,0.5f,0.0f);

    for(Circle const& i : vc)
    {
      if(i.is_inside(Vec2{(float)std::get<0>(win.mouse_position()),(float)std::get<1>(win.mouse_position())})){
        i.draw(win,highlightColor);
      }
      else {
        i.draw(win);
      }
    }

    for(Rectangle const& i : vr)
    {
      if(i.is_inside(Vec2{(float)std::get<0>(win.mouse_position()),(float)std::get<1>(win.mouse_position())})){
        i.draw(win,highlightColor);
      }
      else{
        i.draw(win);
      }
    }

    win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    std::string timeText = "time: "+std::to_string((int)time/3600)+"h "+std::to_string((int)time/60)+"min  "+std::to_string(((int)time)%60)+"s ";
    win.draw_text(10, 5, 35.0f, text);
    win.draw_text(10, 35, 35.0f, timeText);

    win.update();
  }

  return 0;
}
