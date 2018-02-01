//
// Created by uriah on 18-2-1.
//

#ifndef AES256_ULS_DECRYPT_H
#define AES256_ULS_DECRYPT_H

int uls_decrypt_file2file(const char * input, const char * output,
                          unsigned char * key, int keyLength);

int uls_decrypt_file2mem(const char * input, char * outputBuf, int * outputLen,
                         unsigned char * key, int keyLen);

int uls_decrypt_mem2mem(char * inputBuf, int inputLen, char * outputBuf, int * outputLen,
                        unsigned char * key, int keyLen);

#endif //AES256_ULS_DECRYPT_H
