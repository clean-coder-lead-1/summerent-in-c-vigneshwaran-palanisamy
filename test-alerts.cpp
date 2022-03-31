#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(45, 30, 40) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(35, 27, 42) == NORMAL);
}
