//
// Created by lirundong on 2019-03-10.
//

#ifndef TEST_REPOSITORY_MEDIAN_HPP
#define TEST_REPOSITORY_MEDIAN_HPP

#include <vector>

enum MedianMethod {
  SORT, HIST, PROB, YOURS
};

float get_median(const std::vector<float> &data, const MedianMethod method);

#endif //TEST_REPOSITORY_MEDIAN_HPP
