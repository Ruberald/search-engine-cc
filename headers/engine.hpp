#pragma once

#include "lexer.hpp"
#include "model.hpp"

class Engine {
public:

    void init();

    void index(const std::string& directory);
    void search(const std::string& query);

private:
    Lexer lexer{};
    Model model{};
};
