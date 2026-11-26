#include "kmeans.hpp"

#include <iostream>
#include <cassert>

int main() {
    const std::vector<std::vector<double>> points = {
        {1.0f, 2.0f}, 
        {1.5f, 2.3f}, 
        {4.0f, 6.0f}, 
        {8.0f, 9.1f}
    }; 

    const int k = 2;                                        
    const auto centroids = centroid_initializer(k, points);
    
    assert(centroids.size() == 2);
    assert(centroids[0] != centroids[1]);

    for (const auto &centroid : centroids) {
        std::cout << "(" << centroid[0] << "," << centroid[1] << ")\n";
    }
}