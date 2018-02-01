//
// Created by uriah on 18-2-1.
//

#ifndef AES256_ULS_ENCRYPT_H
#define AES256_ULS_ENCRYPT_H

#include <stdint.h>


/**
 * 加密文件（若是比较大的二进制文件，建议部分加密）
 * @param input 　　      [in]  输入文件，未加密文件
 * @param output 　　　　  [in]   输出文件，加密后文件
 * @param key 　　　　　　 [in]   密钥
 * @param keyLength 　　  [in]   密钥长度
 * @param blockSize      [in]    要加密数据块大小（<=0 则全部加密）
 * @return 　　<0 :error;
 */
int uls_encrypt_file2file(const char * input, const char * output,
                          unsigned char * key, int keyLength, int64_t blockSize);

#endif //AES256_ULS_ENCRYPT_H
