//
// Created by lirundong on 2019-03-06.
//

#include <random>
#include <vector>

#include "random_generator.hpp"
#include "gtest/gtest.h"


class TestRandomGenerator : public ::testing::Test {
protected:
  TestRandomGenerator() : _e(_seed) {};

  const unsigned int _seed = 19260817;
  std::default_random_engine _e;
};


TEST_F(TestRandomGenerator, normal_dist) {
  const float mu = 0.f, std = 1.f;
  std::normal_distribution<float> normal(mu, std);

  EXPECT_EQ(get_normal_dist(0, 1, 0, _seed), std::vector<float>({}));
}
