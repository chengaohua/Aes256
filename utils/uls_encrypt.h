//
// Created by uriah on 18-2-1.
//

#ifndef AES256_ULS_ENCRYPT_H
#define AES256_ULS_ENCRYPT_H

#include <stdint.h>

int uls_encrypt_file2file(const char * input, const char * output,
                          unsigned char * key, int keyLength, int64_t blockSize);


#endif //AES256_ULS_ENCRYPT_H
