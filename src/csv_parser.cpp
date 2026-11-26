#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "csv_parser.hpp"

/* Read a line of comma-separated numbers
* and convert it to a vector of floats */
std::vector<double> line_to_point(const std::string &line) {
    std::vector<double> result;
    std::istringstream row(line); // converts to stream
    std::string point;
    while (std::getline(row, point, ',')) {
        result.push_back(std::stod(point)); // converts string to double
    }
    return result;
}

/* Open a CSV file from its path, read and convert the file 
* to a matrix of floats line by line */
std::vector<std::vector<double>> csv_to_points (const std::string &filename) {
    std::ifstream file(filename); // open the file path
    if (!file) {
        throw std::runtime_error("Cannot open CSV file: " + filename);
    }
    std::vector<std::vector<double>> points;
    std::string line;
    while (std::getline(file, line)) {
        points.push_back(line_to_point(line));
    }
    return points;
}

  