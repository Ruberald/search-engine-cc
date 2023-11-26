#include "model.hpp"

Model::Model() {
    
}

std::unordered_map<std::string, int> Model::getTermFrequency(std::vector<std::string> tokens) {
    std::unordered_map<std::string, int> termFrequency;

    for (auto token : tokens) {
        if (termFrequency.contains(token))
            termFrequency[token] = termFrequency[token] + 1;
        else
            termFrequency[token] = 1;
    }

    return termFrequency;
}

double Model::compute_tf(const std::string& query, std::unordered_map<std::string, int> doc) {
    int documentFrequency = 0;

    if(doc.contains(query))
        documentFrequency = doc.at(query);

    return (static_cast<double>(documentFrequency) / doc.size());
}

double Model::compute_idf(const std::string& query, int number_of_docs_with_term) {
    for (const auto& doc: documentToMap) {
        if(doc.second.contains(query))
            number_of_docs_with_term++;
    }

    return std::log10(static_cast<double>(documentToMap.size()) / number_of_docs_with_term);
}

std::map<double, std::string> Model::compute_tf_idf(const std::string& query) {
    std::map<double, std::string> results;

    int number_of_docs_with_term = 0;

    for (const auto& doc: documentToMap) {
        if(doc.second.contains(query)) 
            number_of_docs_with_term++;
    }

    for (const auto& doc: documentToMap) {
        if(doc.second.contains(query)) {
            double tf_idf = compute_tf(query, doc.second) * compute_idf(query, number_of_docs_with_term);
            results[tf_idf] = doc.first;
        }
    }

    return results;
}
