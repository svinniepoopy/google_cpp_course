#include "index.h"
#include "indexer.h"
#include "str_utility.h"

#include <istringstream>
#include <string>
#include <utility>
#include <vector>

Indexer::addIgnoredWordsFromFile(const std::string& file) {

}

void Indexer::processLine(
    const std::string& line,
    const int pagenum,
    const int doc_id) {

  std::istringstream istr{line};
  std::string word;
  while (istr>>word) {
    if (do_scrub) {
      util::scub(word);
    }
    index->add(word, pagenum, doc_id);
  }

}

bool Indexer::processFile(const std::string& file, const int doc_id) {
      std::ifstream ifs{file, std::ios::in};
      if (!ifs.is_open()) {
	return false;
      }

      int total_freq;
      int page_freq;
      int page_num = 1;
      int line_no = 1;

      while (!ifs.eof()) {
	std::getline(ifs, line);
	processLine(line, pagenum, doc_id);
	++line_no;
	if (line_no>0 && line_no%100==0) {
	  ++page_num;
	  line_no = 1;
	}
      }

      return true;
    }
}

std::vector<std::pair<int, int>> Indexer::find(const std::string& word) {

}
