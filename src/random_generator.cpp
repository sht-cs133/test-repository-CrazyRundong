//
// Created by lirundong on 2019-03-06.
//

#include <random>
#include <vector>
#include <algorithm>

#include "random_generator.hpp"


std::vector<float> get_normal_dist(
    const float mu,
    const float std,
    const int n,
    const unsigned int seed) {
  static std::default_random_engine engine(seed);
  static std::normal_distribution<float> normal(mu, std);
  std::vector<float> ret(n, 0.0f);
  for (auto &e : ret) {
    e = normal(engine);
  }

  return ret;
}

std::vector<float> get_uniform_dist(
    const float lb, const float ub,
    const int n, const unsigned int seed) {
  static std::default_random_engine engine(seed);
  static std::uniform_real_distribution<float> uni(lb, ub);
  std::vector<float> ret(n, 0.0f);
  for (auto &e : ret) {
    e = uni(engine);
  }

  return ret;
}

std::vector<float> get_t_dist(
    const int freedom,
    const int n, const unsigned int seed) {
  static std::default_random_engine engine(seed);
  static std::student_t_distribution<float> t(freedom);
  std::vector<float> ret(n, 0.0f);
  for (auto &e : ret) {
    e = t(engine);
  }

  return ret;
}

std::vector<float> get_mixed_data(const int n, const unsigned int seed) {
  const float normal_mu = 2.333f, std = 6.666f, u_lb = -15.f, u_ub = 12.f;
  const int t_freedom = 5;
  auto v_normal = get_normal_dist(normal_mu, std, n, seed + 1);
  auto v_uniform = get_uniform_dist(u_lb, u_ub, n, seed + 2);
  auto v_t = get_t_dist(t_freedom, n, seed + 3);

  static std::default_random_engine engine(seed);
  std::vector<float> ret;
  for (auto &v : {v_normal, v_uniform, v_t}) {
    ret.insert(ret.end(), v.begin(), v.end());
  }
  std::shuffle(ret.begin(), ret.end(), engine);
  ret.resize(n);

  return ret;
}
