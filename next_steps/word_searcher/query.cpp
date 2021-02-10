
#include "indexer.h"

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace {

namespace fs = std::filesystem;

std::vector<std::string> processCmdLineArgs(int argc, char** argv) {
  if (argc == 1) {
    return {};
  }

  return {std::string{argv[1]}};
}

std::vector<std::string> getFileNames(const std::string& path) {
  std::vector<std::string> files;
  for (const auto& p: fs::directory_iterator(path)) {
    files.emplace(p);
  }
  return filepath;
}

} // anonymous namespace

int main(int argc, char** argv) {
  auto args{processCmdLineArgs(argc, argv)};
  if (args.empty()) {
    usage();
    return -1;
  }

  auto files{getFileNames(args[0])};

  auto indexer = std::make_unique<Indexer>();
  for (const auto& file :files) {
    indexer->processFile(file);
  }

  indexer.summarize();
}
