//
// Created by uriah on 18-2-1.
//

#ifndef AES256_ULS_DECRYPT_H
#define AES256_ULS_DECRYPT_H

/**
 * 解密
 * @param input　　　　　[in]   输入文件
 * @param output　　　　 [in]   输出文件
 * @param key　　　　　　[in]    密钥
 * @param keyLength    [in]　　 密钥长度
 * @return      <0:error
 */
int uls_decrypt_file2file(const char * input, const char * output,
                          unsigned char * key, int keyLength);

/**
 * 解密
 * @param input　　　　　　　[in]   　　输入文件名
 * @param outputBuf        [in]　　　　输出缓冲区地址
 * @param outputLen        [in/out]　　入参作为缓冲区大小，出参作为解密后数据大小
 * @param key              [in]　　　　密钥
 * @param keyLen           [in]　　　　密钥长度
 * @return 　　<0 : error
 */
int uls_decrypt_file2mem(const char * input, char * outputBuf, int * outputLen,
                         unsigned char * key, int keyLen);

/**
 * 解密
 * @param inputBuf　　　　　　　[in]  　　　　 输入缓冲区地址
 * @param inputLen            [in]　　　　　输入缓冲区大小
 * @param outputBuf           [out]　　　　输出缓冲区地址
 * @param outputLen           [in/out]　　入参作为缓冲区大小，出参作为解密后数据大小
 * @param key                 [in]　　　　　密钥　
 * @param keyLen              [in]　　　　　密钥长度　
 * @return
 */
int uls_decrypt_mem2mem(char * inputBuf, int inputLen, char * outputBuf, int * outputLen,
                        unsigned char * key, int keyLen);

#endif //AES256_ULS_DECRYPT_H
