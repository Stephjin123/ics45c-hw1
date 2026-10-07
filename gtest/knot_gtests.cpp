// ------------------------- Tests File - knot_test.cpp -------------------- //
// This file is for writing your own user tests. Be sure to include your *.hpp
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// ------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include <iostream>
using namespace std;
// Include all of your *.hpp files you want to unit test:
#include "convert_knots.hpp"

namespace {

TEST(ConvertKnots, Two) {
  EXPECT_NEAR(0.0383593, knots_to_miles_per_minute(2), 0.01);
}

// ADD YOUR TESTS HERE:

TEST(ConvertKnots, Zero) {
  EXPECT_NEAR(0.0, knots_to_miles_per_minute(0), 0.01);
}

TEST(ConvertKnots, Sixty) {
  EXPECT_NEAR(1.15076, knots_to_miles_per_minute(60), 0.01);
}

TEST(ConvertKnots, OneMillion) {
  EXPECT_NEAR(19179.29, knots_to_miles_per_minute(1000000), 0.01);
}

TEST(ConvertKnots, NegativeMillion) {
  EXPECT_NEAR(-19179.29, knots_to_miles_per_minute(-1000000), 0.01);
}

} // anonymous namespace
