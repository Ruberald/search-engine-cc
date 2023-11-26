// Include libraries
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>

// Include project headers
#include "engine.hpp"

int main (int argc, char ** argv) {

    if (argc != 2) {
        std::cerr << "Usage: search-engine-cc [directory]\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Search Engine v0.1\n";

    std::string search_term;
    std::cout << "Enter your search term: " << std::endl;

    Engine engine{};
    
    engine.init();

    engine.index(argv[1]);

    std::cin >> search_term;
    engine.search(search_term);

}
