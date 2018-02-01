//
// Created by uriah on 18-2-1.
//

#include <cstdio>
#include <iostream>
#include <aes256.hpp>
#include <cstring>
#include "uls_decrypt.h"

#define BUFFER_SIZE 1024*1024

#ifdef __APPLE__
#  define fseeko64 fseeko
#endif

int uls_decrypt_file2file(const char * input, const char * output,
                          unsigned char * key, int keyLength){
  FILE * fin = fopen(input, "rb");
  FILE * fout = fopen(output, "wb");
  if(nullptr == fin || nullptr == fout) {
    std::cout<<"文件无法打开"<<std::endl;
    return -1;
  }

  //文件长度
  size_t file_len;
  fseeko64(fin, 0, SEEK_END);
  file_len = ftell(fin);
  fseeko64(fin, 0, SEEK_SET);

  //读取加密数据块长度
  int64_t block_size = -1;
  fread(&block_size, sizeof(block_size), 1, fin);
  if(block_size < 0 || block_size > file_len) {
    std::cout<<"格式错误"<<std::endl;
    return -1;
  }

  srand(time(0));

  ByteArray key_array, dec;

  //保存解密结果
  ByteArray result;
  result.resize(block_size + 32);  //enough
  size_t  size = 0;

  //密钥填充
  for(int i = 0; i< keyLength; i++) {
    key_array.push_back(key[i]);
  }

  Aes256 aes(key_array);

  aes.decrypt_start(block_size);



  size_t read_file_len = 0;

  //解密数据块
  while(read_file_len <  block_size) {

    unsigned char buffer[BUFFER_SIZE];
    size_t buffer_len;
    if(read_file_len + BUFFER_SIZE >= block_size) {
      buffer_len = fread(buffer, 1, block_size - read_file_len, fin);
    } else {
      buffer_len = fread(buffer, 1, BUFFER_SIZE, fin);
    }

    read_file_len += buffer_len;

    if (buffer_len > 0) {
      dec.clear();
      aes.decrypt_continue(buffer, buffer_len, dec);
      memcpy(result.data() + size, dec.data(), dec.size() );
      size += dec.size();
    }


  }

  dec.clear();
  aes.decrypt_end(dec);
  memcpy(result.data() + size, dec.data(), dec.size());
  size += dec.size();

  //保存解密后的数据
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