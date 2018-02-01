//
// Created by uriah on 18-2-1.
//

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <aes256.hpp>
#include <cstring>
#include "uls_encrypt.h"

#define BUFFER_SIZE 1024*1024

#ifdef __APPLE__
#  define fseeko64 fseeko
#endif


int uls_encrypt_file2file(const char * input, const char * output,
                          unsigned char * key, int keyLength, int64_t blockSize){
     FILE * fin = fopen(input, "rb");
     FILE * fout = fopen(output, "wb");
     if(nullptr == fin || nullptr == fout) {
       std::cout<<"文件无法打开"<<std::endl;
       return -1;
     }

    srand(time(0));

    fseeko64(fin, 0, SEEK_END);
    auto file_len = ftell(fin);
    fseeko64(fin, 0, SEEK_SET);

  //如果加密大小<=0，或者>= file_len 则全加密
   if(blockSize <= 0 || blockSize > file_len) {
     blockSize = file_len;
   }

    ByteArray key_array, enc;
    ByteArray result;
    result.resize(blockSize + 32);  //enough
    int64_t size = 0;

    for(int i = 0; i< keyLength; i++) {
      key_array.push_back(key[i]);
    }

    Aes256 aes(key_array);
    enc.clear();
    aes.encrypt_start(blockSize, enc);
    memcpy(result.data() + size , enc.data(), enc.size());
    size += enc.size();

    size_t read_file_len = 0; //
    while(read_file_len < blockSize) {

      unsigned char buffer[BUFFER_SIZE];
      size_t buffer_len;
      if(read_file_len + BUFFER_SIZE >= blockSize) {
        buffer_len = fread(buffer, 1, blockSize - read_file_len, fin);
      } else {
        buffer_len = fread(buffer, 1, BUFFER_SIZE, fin);
      }

      read_file_len += buffer_len;


      if (buffer_len > 0) {
        enc.clear();
        aes.encrypt_continue(buffer, buffer_len, enc);
        memcpy(result.data() + size, enc.data(), enc.size());
        size += enc.size();

      }

    }

    enc.clear();
    aes.encrypt_end(enc);
    memcpy(result.data() + size, enc.data(), enc.size());
    size += enc.size();

    //记录加密数据块长度
    fwrite(&size, sizeof(size), 1, fout);

    //记录加密数据
    fwrite(result.data(), size, 1, fout);

    //保存未加密数据
  while (!feof(fin)) {
    unsigned char buffer[BUFFER_SIZE];
    size_t buffer_len;

    buffer_len = fread(buffer, 1, BUFFER_SIZE, fin);

    if (buffer_len > 0) {
      fwrite(buffer, buffer_len, 1, fout);
    }
  }

  fclose(fin);
  fclose(fout);

  return 0;

}