
#include <ios>
#include <fstream>
#include "uls_file_merge.h"

namespace uls {
void Merge::addInputFile(const char *input) {
  input_file_.push_back(std::string(input));
}

void Merge::setOutputFile(const char *output) {
  output_file_ = output;
}

void Merge::doMerge() {


  std::ofstream ofs(output_file_.c_str(), std::ios::binary);
  int8_t  count = input_file_.size();
  ofs.write((char *)&count, sizeof(count));

  for(int8_t i = 0; i< count ;i++) {
    std::ifstream ifs(input_file_[i].c_str(), std::ifstream::ate | std::ifstream::binary);
    int64_t len = ifs.tellg();
    ifs.seekg(0, std::ios_base::beg);

    char * buf = new char[len];
    ifs.read(buf, len);
    ofs.write((char *)&len, sizeof(len));
    ofs.write(buf, len);

    ifs.close();

    delete[] buf;

  }

  ofs.close();


}
}