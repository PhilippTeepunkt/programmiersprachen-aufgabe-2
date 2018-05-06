#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

//aufgabe 2.2 und 2.3
TEST_CASE ("tests_vec2","[vec2]")
{
  SECTION ("vec2_constructors")
  {
    Vec2 vec{3.0f,2.0f};

    REQUIRE(vec.x == 3.0f);
    REQUIRE(vec.y == 2.0f);


    Vec2 vecCustom;
    REQUIRE(vecCustom.x == 0.0f);
    REQUIRE(vecCustom.y == 0.0f);
  }
}

TEST_CASE ("test_vec2_operator","[vec2]")
{
  SECTION("test_+=operator")
  {
    Vec2 vec{3.0f,2.0f};
    Vec2 vecT{5.0f,3.0f};
    vec+=vecT;
    REQUIRE(vec.x==8.0f);
    REQUIRE(vec.y==5.0f);
  }

  SECTION("test_-=operator")
  {
    Vec2 vecT{3.0f,2.0f};
    Vec2 vec{5.0f,3.0f};
    vec-=vecT;
    REQUIRE(vec.x==2.0f);
    REQUIRE(vec.y==1.0f);
  }

  SECTION("test_*=operator")
  { 
    Vec2 vec{3.0f,2.0f};
    float s = 2.0f;
    vec*=s;
    REQUIRE(vec.x==6.0f);
    REQUIRE(vec.y==4.0f);
  }

  SECTION("test_/=operator")
  {
    Vec2 vec{3.0f,2.0f};
    float s = 2.0f;
    vec/=s;
    REQUIRE(vec.x==1.5f);
    REQUIRE(vec.y==1.0f);
  
    float z = 0.0f;
    Vec2 vec_2{3.0f,2.0f};
    vec_2/=z;
    REQUIRE(vec_2.x==3.0f);
    REQUIRE(vec_2.y==2.0f);
  }

  //aufgabe 2.4
  SECTION("test_+operator")
  {
    Vec2 vec{3.0f,2.0f};
    Vec2 vecT{2.0f,5.0f};
    Vec2 sum = vec+vecT;
    REQUIRE(sum.x==5.0f);
    REQUIRE(sum.y==7.0f);
  }

  SECTION("test_-operator")
  {
    Vec2 vec{3.0f,2.0f};
    Vec2 vecT{2.0f,5.0f};
    Vec2 sub = vec-vecT;
    REQUIRE(sub.x==1.0f);
    REQUIRE(sub.y==-3.0f);
  }

  SECTION("test_*operator")
  {
    Vec2 vec{3.0f,2.0f};
    float s = 2.0f;
    Vec2 prod =vec*s;
    REQUIRE(prod.x==6.0f);
  }

  SECTION("test_/operator")
  {
    Vec2 vec{3.0f,2.0f};
    float s = 2.0f;
    Vec2 div = vec/s;
    REQUIRE(div.x == 1.5f);
    REQUIRE(div.y == 1.0f);

    Vec2 vecT{3.0f,2.0f};
    float n = 0.0f;
    Vec2 divi = vecT/n;
    REQUIRE(divi.x == 3.0f);
    REQUIRE(divi.y == 2.0f);
  }
}

TEST_CASE ("test_mat2_operators","[mat2]")
{
  //aufgabe 2.5
  SECTION("test_*=operator")
  {
    Vec2 v1{3.0f,2.0f};
    Vec2 v2{2.0f,5.0f};
    Vec2 v3{2.0f,4.0f};
    Vec2 v4{3.0f,-2.0f};

    Mat2 m1{v1,v2};
    Mat2 m2{v3,v4};
    m1 *= m2;
    REQUIRE(m1.s1.x == 14.0f);
    REQUIRE(m1.s1.y == 24.0f);
    REQUIRE(m1.s2.x == 5.0f);
    REQUIRE(m1.s2.y == -4.0f);
  }

  SECTION ("test_*operator")
  {
    Vec2 v_1{3.0f,2.0f};
    Vec2 v_2{2.0f,5.0f};
    Vec2 v_3{2.0f,4.0f};
    Vec2 v_4{3.0f,-2.0f};

    Mat2 m1{v_1,v_2};
    Mat2 m2{v_3,v_4};

    Mat2 erg;
    erg = m1 * m2;
    REQUIRE(erg.s1.x == 14.0f);
    REQUIRE(erg.s1.y == 24.0f);
    REQUIRE(erg.s2.x == 5.0f);
    REQUIRE(erg.s2.y == -4.0f);
  }

  //aufgabe 2.6
  SECTION ("t2_*vecOperator")
  {
    Vec2 v_1{3.0f,2.0f};
    Vec2 v_2{2.0f,5.0f};
    Vec2 v_3{3.0f,-2.0f};

    Mat2 m1{v_1,v_2};

    Vec2 erg;
    erg = m1 * v_3;
    REQUIRE(erg.x == 5.0f);
    REQUIRE(erg.y == -4.0f);

    erg = v_3 * m1;
    REQUIRE(erg.x == 5.0f);
    REQUIRE(erg.y == -4.0f);
  }

  SECTION("test_*float_operator")
  {
    Vec2 v_1{3.0f,2.0f};
    Vec2 v_2{2.0f,5.0f};

    Mat2 m1{v_1,v_2};

    Mat2 erg = m1*2;
    REQUIRE(erg.s1.x == 6.0f);
    REQUIRE(erg.s1.y == 4.0f);
    REQUIRE(erg.s2.x == 4.0f);
    REQUIRE(erg.s2.y == 10.0f);

    erg = 2 * m1;
    REQUIRE(erg.s1.x == 6.0f);
    REQUIRE(erg.s1.y == 4.0f);
    REQUIRE(erg.s2.x == 4.0f);
    REQUIRE(erg.s2.y == 10.0f);
  }
}
TEST_CASE ("test_mat2_functions","[mat2]")
{
  SECTION("test_determinante") 
  {
    Vec2 v_1{3.0f,-2.0f};
    Vec2 v_2{2.0f,-5.0f};

    Mat2 m1{v_1,v_2};

    REQUIRE(m1.det() == -11.0f);
  }

  SECTION("test_inverse")
  {
    Vec2 v_1{3.0f,-2.0f};
    Vec2 v_2{2.0f,-5.0f};
    Vec2 v_3{0.45454547f,-0.181818187f};
    Vec2 v_4{0.181818187f,-0.272727281f};

    Mat2 m1{v_1,v_2};

    Mat2 erg{v_3,v_4};
    Mat2 calc = inverse(m1);
    REQUIRE(erg.s1.x==Approx(calc.s1.x));
    REQUIRE(erg.s1.y==Approx(calc.s1.y));
    REQUIRE(erg.s2.x==Approx(calc.s2.x));
    REQUIRE(erg.s2.y==Approx(calc.s2.y));

    Vec2 v_5{2.0f,2.0f};
    Vec2 v_6{2.0f,2.0f};

    Mat2 m2{v_5,v_6};
    calc = inverse(m2);
    REQUIRE(calc.s1.x == m2.s1.x);
    REQUIRE(calc.s1.y == m2.s1.y);
    REQUIRE(calc.s2.x == m2.s2.x);
    REQUIRE(calc.s2.y == m2.s2.y);
  }

  SECTION("test_transpose")
  {
    Vec2 v_1{3.0f,-2.0f};
    Vec2 v_2{2.0f,-5.0f};
    Mat2 m1{v_1,v_2};

    Mat2 erg{Vec2{3.0f,2.0f},Vec2{-2.0f,-5.0f}};
    Mat2 calc = transpose(m1);
    REQUIRE(calc.s1.x == erg.s1.x);
    REQUIRE(calc.s2.x == erg.s2.x);
    REQUIRE(calc.s1.y == erg.s1.y);
    REQUIRE(calc.s2.y == erg.s2.y);
  }

  SECTION("test_mat2_makeRotate")
  {
    Mat2 calc = make_rotate_mat2(30.0f);
    REQUIRE(calc.s1.x == Approx(cos(30.0f)));
    REQUIRE(calc.s1.y == Approx(sin(30.0f)));
    REQUIRE(calc.s2.x == Approx(-sin(30.0f)));
    REQUIRE(calc.s2.y == Approx(cos(30.0f)));
  }
}

TEST_CASE("test_color_general","[color]")
{
	SECTION("test_constructors"){

		Color bl{0.0f};;
		REQUIRE(bl.r_ == Approx(0.0f));
		REQUIRE(bl.g_ == Approx(0.0f));
		REQUIRE(bl.b_ == Approx(0.0f));

		Color re{1.0f,0.0f,0.0f};
		REQUIRE(re.r_ == Approx(1.0f));
		REQUIRE(re.g_ == Approx(0.0f));
		REQUIRE(re.b_ == Approx(0.0f));

		Color none{3.0f};
		REQUIRE(none.r_ == Approx(0.0f));
		REQUIRE(none.g_ == Approx(0.0f));
		REQUIRE(none.b_ == Approx(0.0f));
	}
}

TEST_CASE("test_circle_general","[circle]") {
	Circle a;
	Circle b{2.0f};
  Circle c{2.0f,Vec2{1.0f,1.0f}};
  Circle d{2.0f,Vec2{2.0f,2.0f},Color{0.0f,1.0f,0.0f}};

	SECTION("test_constructors") {
		REQUIRE(a.get_center().x == Approx(0.0f));
		REQUIRE(a.get_center().y == Approx(0.0f));
		REQUIRE(a.get_radius() == Approx(1.0f));
    REQUIRE(a.get_color().r_ == Approx(0.0f));

		REQUIRE(b.get_center().x == Approx(0.0f));
		REQUIRE(b.get_center().y == Approx(0.0f));
		REQUIRE(b.get_radius() == Approx(2.0f));
    REQUIRE(b.get_color().r_ == Approx(0.0f));

    REQUIRE(c.get_center().x == Approx(1.0f));
		REQUIRE(c.get_center().y == Approx(1.0f));
		REQUIRE(c.get_radius() == Approx(2.0f));
    REQUIRE(c.get_color().g_ == Approx(0.0f));

    REQUIRE(d.get_center().x == Approx(2.0f));
		REQUIRE(d.get_center().y == Approx(2.0f));
		REQUIRE(d.get_radius() == Approx(2.0f));
    REQUIRE(d.get_color().g_ == Approx(1.0f));

	}

	SECTION("test_methods") {

		REQUIRE(a.circumference() == Approx(6.2831853072));
		REQUIRE(b.circumference() == Approx(12.5663706144));
	}
}

TEST_CASE("test_rectangle_general","[rectangle]")
{
	Rectangle a;
	Rectangle b{Color{0.0f,1.0f,0.0f}};
  Rectangle c{Vec2{1.0f,1.0f},Vec2{2.0f,2.0f}};
  Rectangle d{Vec2{2.0f,2.0f},Vec2{3.0f,3.0f},Color{0.0f,1.0f,0.0f}};

	SECTION("test_constructors") {
	
		REQUIRE(a.get_min().x == Approx(0.0f));
		REQUIRE(a.get_min().y == Approx(0.0f));
		REQUIRE(a.get_max().x == Approx(1.0f));
		REQUIRE(a.get_max().y == Approx(1.0f));
    REQUIRE(a.get_color().g_ == Approx(0.0f));

		REQUIRE(b.get_min().x == Approx(0.0f));
		REQUIRE(b.get_min().y == Approx(0.0f));
		REQUIRE(b.get_max().x == Approx(1.0f));
		REQUIRE(b.get_max().y == Approx(1.0f));
    REQUIRE(b.get_color().g_ == Approx(1.0f));


    REQUIRE(c.get_min().x == Approx(1.0f));
		REQUIRE(c.get_min().y == Approx(1.0f));
		REQUIRE(c.get_max().x == Approx(2.0));
		REQUIRE(c.get_max().y == Approx(2.0));
    REQUIRE(c.get_color().g_ == Approx(0.0f));

    REQUIRE(d.get_min().x == Approx(2.0f));
		REQUIRE(d.get_min().y == Approx(2.0f));
		REQUIRE(d.get_max().x == Approx(3.0f));
		REQUIRE(d.get_max().y == Approx(3.0f));
    REQUIRE(d.get_color().g_ == Approx(1.0f));
	}

	SECTION("test_methods") {
		REQUIRE(a.circumference() == Approx(4.0f));
		REQUIRE(c.circumference() == Approx(4.0f));
	} 
}

TEST_CASE("test_custom","[custom]")
{
  SECTION("test_vec_length")
  {
    REQUIRE(length(Vec2{3.0f,4.0f})==5.0f);
    REQUIRE(length(Vec2{-3.0,-4.0f})==5.0f);
  }

  SECTION("circle_isInside")
  {
    Circle c{5.0f,Vec2{2.0f,2.0f}};
    REQUIRE(c.is_inside(Vec2{3.0f,4.0f}));
    REQUIRE(c.is_inside(Vec2{2.0f,7.0f}));
    REQUIRE(!c.is_inside(Vec2{2.0f,9.0f}));
  }
}
