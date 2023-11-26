#include <string>
#include <vector>
#include <sstream>

#include "lexer.hpp"

std::vector<std::string> Lexer::tokenize(const std::string& text) {
    std::istringstream iss(text);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
