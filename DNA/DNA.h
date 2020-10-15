#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace DNA {
    std::string findMatch(const std::string & input, const std::unordered_map<std::string, std::vector<int>> & dict, const std::vector<std::string> & strs);
    std::string findMatch(const std::string & input, const std::vector<std::vector<int>> & names_occurrences, const std::vector<std::string> names, const std::vector<std::string> & strs);
}