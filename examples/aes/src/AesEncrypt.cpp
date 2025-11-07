
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "AesEncrypt.h"

std::string AesEncrypt::aesEncode(std::string& data){
    std::string key = "1112130987654321";
    std::string iv = "1234567890111213";
    AES_KEY aes;

    if (AES_set_encrypt_key((const unsigned char *)key.c_str(), 128, &aes) < 0) {
        std::cout << "Unable to set encryption key in AES" <<std::endl;
        return "";
    }

    // 1. set the encryption length
    int len = 0;
    if ((data.length() + 1) % AES_BLOCK_SIZE == 0) {
        len = data.length() + 1;
    } else {
        len = ((data.length() + 1) / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;
    }

    // 2. alloc encrypt_string
    unsigned char *encrypt_string = (unsigned char*)calloc(len, sizeof(unsigned char));
    if (encrypt_string == NULL) {
        std::cout << "Unable to allocate memory for encrypt_string" <<std::endl;
        return "";
    }

    // 3. encrypt (iv will change)
    AES_cbc_encrypt((const unsigned char*)data.c_str(), encrypt_string, len, &aes, (unsigned char *)iv.c_str(), AES_ENCRYPT);

    std::string enStr(reinterpret_cast<const char*>(encrypt_string), len);
    return enStr;
}

std::string AesEncrypt::aesDecode(std::string& data){
    std::string key = "1112130987654321";
    std::string iv = "1234567890111213";
    AES_KEY aes;

    if (AES_set_decrypt_key((const unsigned char*)key.c_str(), 128, &aes) < 0) {
        std::cout << "Unable to set decryption key in AES" <<std::endl;
        return "";
    }

    int len = data.length();

    // 1. alloc decrypt_string
    unsigned char* decrypt_string = (unsigned char*)calloc(len, sizeof(unsigned char));
    if (decrypt_string == NULL) {
        std::cout << "Unable to allocate memory for decrypt_string" <<std::endl;
        return "";
    }

    // 2. decrypt
    std::cout << "encrypted string = ";
    for (int i=0; i < len; ++i) {
        std::cout << std::hex << int(data[i] & 0xff);
        // printf("%X%X", (data[i] >> 4) & 0xf, data[i] & 0xf);
    }

    std::cout << std::endl;
    AES_cbc_encrypt((const unsigned char*)data.c_str(), decrypt_string, len, &aes, (unsigned char*)iv.c_str(), AES_DECRYPT);

    std::string deStr = (char*)decrypt_string;
    return deStr;
}
