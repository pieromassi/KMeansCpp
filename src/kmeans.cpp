#include <stdexcept>
#include <random>

#include "kmeans.hpp"

/* Compute the square distance between two given points, 
* after checking sizes are equal */
float square_distance(const std::vector<float> &a, const std::vector<float> &b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Points have different dimension");
    }

    float distance = 0.0f;
    for(std::size_t i = 0; i < a.size(); i++) {
        const float diff = a[i] - b[i];
        distance += diff * diff;
    }
    return distance;
}

/* Pick a random point between the given ones */
// std::vector<float> point_picker(const std::vector<std::vector<float>> &points) {
//     int n = points.size(); // how many points there are
//     std::mt19937 rng{std::random_device{}()};
//     std::uniform_int_distribution<int> pick(0, n-1);
//     int k = pick(rng);
//     return points[k]; 
// }

/* Checks if a given integer is inside a vector of integers */
static bool is_in(std::size_t idx,const std::vector<std::size_t> &indices) {
    for (const auto &index : indices) {
        if (idx == index) {
            return true;
        }
    }    
    return false;
}

/* Initializes centroids by picking k random distinct points from the given ones */
std::vector<std::vector<float>> centroid_initializer(std::size_t k, 
            const std::vector<std::vector<float>> &points) {
    std::size_t n = points.size(); // how many points there are
    if (k > n) {
        throw std::invalid_argument("Groups to make are more than points given");
    }
    if (k <= 0) {
        throw std::invalid_argument("Nonpositive number of groups");
    }

    std::vector<std::vector<float>> centroids;
    std::vector<std::size_t> indices;
    
    std::mt19937 rng{std::random_device{}()}; // Generate random numbers
    std::uniform_int_distribution<std::size_t> pick(0, n-1); // Resize random number uniformly into a range

    while(centroids.size() < k) {
        const auto idx = pick(rng);
        if (is_in(idx, indices)) {
            continue;
        }
        centroids.push_back(points[idx]);
        indices.push_back(idx);
    }

    return centroids;
}