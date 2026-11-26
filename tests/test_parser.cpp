#include <exception>
#include <iostream>
#include <vector>

#include "csv_parser.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: test_csv_parser <path-to-csv>\n";
        return 1;
    }

    const std::vector<std::vector<double>> expected = {
        {0, 0},
        {0, 2},
        {2, 1},
        {8, 8},
        {8, 10},
        {10, 9}
    };

    try {
        const auto points = csv_to_points(argv[1]);

        if (points.size() != expected.size()) {
            std::cerr << "Expected " << expected.size()
                      << " rows, got " << points.size() << '\n';
            return 1;
        }

        for (int i = 0; i < expected.size(); ++i) {
            if (points[i] != expected[i]) {
                std::cerr << "Wrong coordinates or dimension on row "
                          << i + 1 << '\n';
                return 1;
            }
        }
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }

    std::cout << "All points were read correctly.\n";
    return 0;
}