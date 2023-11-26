#include <string>
#include <vector>
#include <sstream>

#include "lexer.hpp"

std::string Lexer::cleanToken(const std::string& token) {
    std::string cleanedToken;
    for (char c : token) {
        if (!std::ispunct(c)) {
            cleanedToken += c;
        }
    }
    return cleanedToken;
}

std::vector<std::string> Lexer::tokenize(const std::string& text) {
    std::istringstream iss(text);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        // Clean the token by removing punctuation
        std::string cleanedToken = cleanToken(token);

        // Add the cleaned token to the tokens vector
        if (!cleanedToken.empty()) {
            tokens.push_back(cleanedToken);
        }
    }
    return tokens;
}
