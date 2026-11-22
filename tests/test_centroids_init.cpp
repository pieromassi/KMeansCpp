#include "kmeans.hpp"

#include <iostream>
#include <cassert>
#include <cstddef>

int main() {
    const std::vector<std::vector<float>> points = {
        {1.0f, 2.0f}, 
        {1.5f, 2.3f}, 
        {4.0f, 6.0f}, 
        {8.0f, 9.1f}
    }; 

    const std::size_t k = 2;                                        
    const auto centroids = centroid_initializer(k, points);
    
    assert(centroids.size() == 2);
    assert(centroids[0] != centroids[1]);

    for (const auto &centroid : centroids) {
        std::cout << "(" << centroid[0] << "," << centroid[1] << ")\n";
    }
}