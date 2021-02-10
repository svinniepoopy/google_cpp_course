#ifndef INDEXER_H
#define INDEXER_H

#include "index.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

class Indexer {
  public:

    Indexer():do_scrub{false} {}

    void addIgnoredWordsFromFile(const std::string& file);

    void processLine(const std::string& line, const int pagenum, const int doc_id);

    bool processFile(const std::string& file, const int doc_id);

    std::vector<std::pair<int, int>> find(const std::string& word);

  private:
    bool do_scrub;
    std::unordered_map<std::string> ignored_words; 
    std::unique_ptr<Index> index = std::make_unique<Index>();
};

#endif // INDEXER_H
