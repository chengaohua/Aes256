
#ifndef AES256_ULS_FILE_MERGE_H
#define AES256_ULS_FILE_MERGE_H

#include <string>
#include <cstdint>
#include <vector>

namespace uls {
class Merge{
public:
    void addInputFile(const char * input);
    void setOutputFile(const char * output);
    void doMerge();
public:
    std::vector<std::string> input_file_;
    std::string output_file_;
};
}

#endif //AES256_ULS_FILE_MERGE_H
