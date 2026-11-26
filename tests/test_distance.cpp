#include "kmeans.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    assert(square_distance({1.0, 2.0}, {4.0, 6.0}) == 25.0);
    assert(square_distance({1.0, 2.0}, {1.0, 2.0}) == 0.0);

    bool threw = false;
    try {
        square_distance({1.0}, {1.0, 2.0});
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw);

    std::cout << "All distance tests passed.\n";
}