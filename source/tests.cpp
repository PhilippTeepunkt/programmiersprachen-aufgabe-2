#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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

}

TEST_CASE ("test_vec2_-operator","[vec2_operator]")
{
  
}

TEST_CASE ("test_vec2_*operator","[vec2_operator]")
{
  
}

TEST_CASE ("test_vec2_/operator","[vec2_operator]")
{
  
}
