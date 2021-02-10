#include "index.h"
#include "posting_record.h"

#include <ostream>
#include <string>
#include <vector>
#include <utility>

void Index::add(const std::string& word, const int pagenum, const int doc_id) {
  ++doc2word[doc_id][word];
}

void Index::updatePostingsList(int doc_id) {
  auto& wordfreq = doc2word[doc_id];

  for (const auto& item:wordfreq) {
    postings_list[item.first].emplace(doc_id, item.second);
  }
}

std::ostream& operator<<(std::ostream& os, const Index& index) {
  for (const auto& item:index.postings_list) {
    os <<  item.first;
    for (const auto& posting:item.second) {
      os << "<" << posting.doc_id << ","<< posting.freq << ">";
    }
    os << "\n";
  }
  return os;
}
