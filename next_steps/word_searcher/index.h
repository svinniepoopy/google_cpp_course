#ifndef INDEX_H
#define INDEX_H

#include "posting_record.h"

#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

class Index {
  public:
    void add(const std::string word, const PostingRecord& rec);

    std::vector<std::pair<int, int>>& getRecords(const std::string);

  private:
    std::unordered_map<std::string, std::set<PostingRecord>> idx;
}:

#endif // INDEX_STORE_H
