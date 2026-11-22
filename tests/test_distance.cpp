#include "kmeans.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    assert(square_distance({1.0f, 2.0f}, {4.0f, 6.0f}) == 25.0f);
    assert(square_distance({1.0f, 2.0f}, {1.0f, 2.0f}) == 0.0f);

    bool threw = false;
    try {
        square_distance({1.0f}, {1.0f, 2.0f});
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw);

    std::cout << "All distance tests passed.\n";
}