
#ifndef AES256_ULS_FILE_SPLIT_H
#define AES256_ULS_FILE_SPLIT_H

#include <vector>
#include <cstdint>
#include <string>

namespace uls {
class Split{

public:
    void setInputFile(const char * input);
    int  doSplit(int * len, int64_t fileLen[]);
    int copy(int id, char buf[]);

public:
    std::string input_file_;
    std::vector<std::vector<char>> output_mem_;

};
}

#endif //AES256_ULS_FILE_SPLIT_H
