#pragma once

#include <vector>
#include <cstddef>

float square_distance(const std::vector<float> &a, const std::vector<float> &b);
//std::vector<float> point_picker(const std::vector<std::vector<float>> &points);
std::vector<std::vector<float>> centroid_initializer(std::size_t k, 
            const std::vector<std::vector<float>> &points);