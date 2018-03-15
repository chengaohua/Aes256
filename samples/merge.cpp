

#include <stdio.h>
#include <iostream>
#include "uls_decrypt.h"
#include "uls_file_merge.h"
#include "uls_file_split.h"

#include "aes256.hpp"


int main(int argc, char **argv)
{

  if (argc != 5) {
    fprintf(stderr, "Missing arguments\n");
    fprintf(stderr, "Usage: %s  <input file> <input file> <input file> <output file>\n", argv[0]);
    return 1;
  }


  uls::Merge merge;
  merge.addInputFile(argv[1]);
  merge.addInputFile(argv[2]);
  merge.setOutputFile(argv[4]);
  merge.addInputFile(argv[3]);
  merge.doMerge();


  uls::Split split;
  split.setInputFile(argv[4]);
  int len = 0;
  int64_t fileLen[5];
  split.doSplit(&len, fileLen);
  std::cout<<"len = "<<len<<std::endl;
  for(int i = 0; i < len; i++) {
    std::cout<<"fileLen["<<i<<"] = "<<fileLen[i]<<std::endl;
  }


  return 0;
}
