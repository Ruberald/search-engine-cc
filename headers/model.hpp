#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <sstream>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <filesystem>
#include <string>

class Model {
public:
    Model();
private:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> documentToMap;

    std::unordered_map<std::string, int> getTermFrequency(std::vector<std::string> tokens);

    double compute_tf(const std::string& query, std::unordered_map<std::string, int> doc);

    double compute_idf(const std::string& query, int number_of_docs_with_term);

    std::map<double, std::string> compute_tf_idf(const std::string& query);

    friend class Engine;
};
