#include "engine.hpp"

void Engine::init() {

}

void Engine::index(const std::string& directory) {

    for (const auto& file : std::filesystem::directory_iterator(directory)) {
        std::ifstream ifs(file.path());
        std::stringstream buffer;
        buffer << ifs.rdbuf();

        auto tokens = lexer.tokenize(buffer.str());
        auto term_frequencies = model.getTermFrequency(tokens);
        // std::ofstream ofs(std::string(argv[2]) + file.path().filename().generic_string() + "_tf_idf.txt");
        // for(const auto& entry: term_frequencies) {
        //     ofs << entry.first << " :: " << entry.second << "\n";
        // }

        model.documentToMap[file.path()] = term_frequencies;
    }

}

void Engine::search(const std::string& query) {
    auto results = model.compute_tf_idf(query);
    for(auto it = results.rbegin(); it != results.rend(); it++) {
        std::cout << it->second << " : " << it->first << "\n";
    }
}
