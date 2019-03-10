//
// Created by lirundong on 2019-03-06.
//

#ifndef TEST_REPOSITORY_RANDOM_GENERATOR_HPP
#define TEST_REPOSITORY_RANDOM_GENERATOR_HPP

#include <random>
#include <vector>

std::vector<float> get_normal_dist(const float mu, const float std,
                                   const int n, const unsigned int seed);

std::vector<float> get_uniform_dist(const float lb, const float ub,
                                    const int n, const unsigned int seed);

std::vector<float> get_t_dist(const int freedom,
                              const int n, const unsigned int seed);

std::vector<float> get_mixed_data(const int n, const unsigned int seed);

#endif //TEST_REPOSITORY_RANDOM_GENERATOR_HPP
