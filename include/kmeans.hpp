#pragma once

#include <vector>

double square_distance(const std::vector<double> &a, const std::vector<double> &b);
//std::vector<double> point_picker(const std::vector<std::vector<double>> &points);
std::vector<std::vector<double>> centroid_initializer(int k, 
            const std::vector<std::vector<double>> &points);