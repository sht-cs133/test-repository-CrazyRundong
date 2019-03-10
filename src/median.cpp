//
// Created by lirundong on 2019-03-10.
//

#include <iostream>
#include <algorithm>
#include <cmath>

#include "median.hpp"

float get_median(const std::vector<float> &data, const MedianMethod method) {
  float ret = 0.0f;

  switch (method) {
    case SORT: {
      auto n = data.size();
      auto i1 = n / 2, i2 = (n + 1) / 2;
      auto sorted_data(data);
      std::sort(sorted_data.begin(), sorted_data.end());
      auto v1 = sorted_data[i1], v2 = sorted_data[i2];
      ret = (v1 + v2) / 2.f;
    }
      break;
    case HIST: {
      // TODO

    }
      break;
    case PROB: {
      // TODO:
    }
      break;
    case YOURS: {
      // TODO:
    }
      break;
    default:
      std::cerr << "Invalid median algorithm option" << std::endl;
  }

  return ret;
}
