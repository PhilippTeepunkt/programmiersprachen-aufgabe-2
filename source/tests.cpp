#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

//aufgabe 2.2 und 2.3

TEST_CASE ("default_vec2","[vec2]")
{
  Vec2 vec{3.0f,2.0f};

  REQUIRE(vec.x == 3.0f);
  REQUIRE(vec.y == 2.0f);
}

TEST_CASE ("test_vec2","[vec2]")
{
  Vec2 vecCustom;
  REQUIRE(vecCustom.x == 0.0f);
  REQUIRE(vecCustom.y == 0.0f);
}

TEST_CASE ("test_vec2_+=operator","[vec2_operator]")
{
  Vec2 vec{3.0f,2.0f};
  Vec2 vecT{5.0f,3.0f};
  vec+=vecT;
  REQUIRE(vec.x==8.0f);
  REQUIRE(vec.y==5.0f);
}

TEST_CASE ("test_vec2_-=operator","[vec2_operator]")
{
  Vec2 vecT{3.0f,2.0f};
  Vec2 vec{5.0f,3.0f};
  vec-=vecT;
  REQUIRE(vec.x==2.0f);
  REQUIRE(vec.y==1.0f);
}

TEST_CASE ("test_vec2_*=operator","[vec2_operator]")
{
  Vec2 vec{3.0f,2.0f};
  float s = 2.0f;
  vec*=s;
  REQUIRE(vec.x==6.0f);
  REQUIRE(vec.y==4.0f);
}

TEST_CASE ("test_vec2_/=operator","[vec2_operator]")
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

TEST_CASE ("test_vec2_+operator","[vec2_operator]")
{
  Vec2 vec{3.0f,2.0f};
  Vec2 vecT{2.0f,5.0f};
  Vec2 sum = vec+vecT;
  REQUIRE(sum.x==5.0f);
  REQUIRE(sum.y==7.0f);
}

TEST_CASE ("test_vec2_-operator","[vec2_operator]")
{
  Vec2 vec{3.0f,2.0f};
  Vec2 vecT{2.0f,5.0f};
  Vec2 sub = vec-vecT;
  REQUIRE(sub.x==1.0f);
  REQUIRE(sub.y==-3.0f);
}

TEST_CASE ("test_vec2_*operator","[vec2_operator]")
{
  Vec2 vec{3.0f,2.0f};
  float s = 2.0f;
  Vec2 prod =vec*s;
  REQUIRE(prod.x==6.0f);
}

TEST_CASE ("test_vec2_/operator","[vec2_operator]")
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

//aufgabe 2.5
TEST_CASE ("test_mat2_*=operator","[mat2_operator]")
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

TEST_CASE ("test_mat2_*operator","[mat2_operator]")
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

