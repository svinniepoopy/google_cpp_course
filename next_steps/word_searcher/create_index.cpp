// file: query.cpp
//
#include "indexer.h"

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace {
namespace fs = std::filesystem;

void usage() {
  std::cout << "Usage: create_index <ignored_words_file_dir> <word corpus dir>" << std::endl;
}


} // anonymous namespace

int main(int argc, char** argv) {
  if (argc<2) {
    usage();
    return -1;
  }
  const std::string ignored_corpus{argv[1]};
  const std::string text_corpus{argv[2]};

  auto indexer = std::make_unique<Indexer>(ignored_corpus, text_corpus);
  indexer->processIgnoredWords();
  for (const auto& file :files) {
    indexer->processFile(file);
  }

  indexer.summarize();
  indexer.writeToDisk();
}
