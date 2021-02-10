#ifndef INDEXER_H
#define INDEXER_H

#include "index.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>

class Indexer {
  public:

    Indexer(const std::string& ignoreddir, const std::string& corpusdir):
      do_scrub{false},
      ignored_words_dir{ignoreddir},
      corpus_dir{corpusdir} {}


    void processIgnoredWords();

    bool processFile(const std::string& file, const int doc_id);

    void summarize() const;

    void writeToDisk();

  private:
    void processLine(const std::string& line, const int pagenum, const int doc_id);

    bool do_scrub;
    
    std::string ignored_words_dir;
    std::string corpus_dir;

    std::unordered_set<std::string> ignored_words; 
    std::unique_ptr<Index> index = std::make_unique<Index>();
};

#endif // INDEXER_H
