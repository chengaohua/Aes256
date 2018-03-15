#include "uls_file_split.h"
#include <fstream>
#include <cstring>
#include <iostream>

namespace uls {
  void Split::setInputFile(const char * input) {
    input_file_ = input;
  }

  int Split::doSplit(int *len, int64_t fileLen[]) {

    //读取文件个数
    std::ifstream ifs(input_file_.c_str(),  std::ifstream::binary);

    int8_t count = 0;
    ifs.read((char *)&count, sizeof(count));

    for(int8_t i = 0 ; i < count; i++){
      int64_t len = 0;
      ifs.read((char *)&len, sizeof(len));
      std::vector<char> fBuf;
      fBuf.resize(len);
      ifs.read(fBuf.data(), len);
      output_mem_.push_back(fBuf);

      fileLen[i] = len;
    }

    ifs.close();

    *len = output_mem_.size();

    return 0;

  }

int Split::copy(int id, char *buf) {
  memcpy(buf, output_mem_[id].data(), output_mem_[id].size());
  return 0;
}
}
