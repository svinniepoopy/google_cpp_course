#include "index.h"
#include "posting_record.h"

#include <string>
#include <vector>
#include <utility>

Index::add(const std::string& word, const PostingRecord& rec) {
  idx.insert({word, rec});
}

std::vector<std::pair<int, int>>& getRecords(const std::string) {

}
