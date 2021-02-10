#include "index.h"
#include "posting_record.h"

#include <string>
#include <vector>
#include <utility>

void Index::add(const std::string& word, const PostingRecord& rec) {
  idx[word].emplace(rec);
}

std::vector<std::pair<int, int>> Index::getRecords(const std::string) {
  return {{}};
}

void Index::add(const std::string& word, const int pagenum, const int doc_id) {

}
