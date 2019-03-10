//
// Created by lirundong on 2019-03-10.
//

#include <vector>

#include "median.hpp"
#include "random_generator.hpp"
#include "gtest/gtest.h"

class TestMedian : public ::testing::Test {
protected:
  void SetUp() override {
    seed = 19260817;
    int n = 1e6;
    data = get_mixed_data(n, seed);
  }

  std::vector<float> data;
  unsigned int seed;
};

TEST_F(TestMedian, test_get_median) {
  EXPECT_EQ(0.0f, get_median({0.f, 0.f, 0.f}, SORT));
  auto median_sort = get_median(data, SORT);
  EXPECT_EQ(median_sort, get_median(data, SORT));
}

