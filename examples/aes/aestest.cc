/*
* aes.cc
* - Show the usage of AES encryption/decryption
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>

using namespace std;

void autoAes() {
    char *data = "hello world!hello world!hello world!hello world!hello world!hello world!hello world!hello world!hello world!";
    AES_KEY aes;
    unsigned char key[AES_BLOCK_SIZE];      // AES_BLOCK_SIZE = 16
    unsigned char iv[AES_BLOCK_SIZE];       // init vector
    unsigned char* input_string;
    unsigned char* encrypt_string;
    unsigned char* decrypt_string;
    unsigned int len;                       // encrypt length (in multiple of AES_BLOCK_SIZE)
    unsigned int i;

    // set the encryption length
    len = 0;
    if ((strlen(data) + 1) % AES_BLOCK_SIZE == 0) {
        len = strlen(data) + 1;
    } else {
        len = ((strlen(data) + 1) / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;
    }

    // set the input string
    input_string = (unsigned char*)calloc(len, sizeof(unsigned char));
    if (input_string == NULL) {
        fprintf(stderr, "Unable to allocate memory for input_string\n");
        exit(-1);
    }

    strncpy((char*)input_string, data, strlen(data));

    // Generate AES 128-bit key
    for (i=0; i<16; ++i) {
        key[i] = 32 + i;
    }

    // Set encryption iv
    for (i=0; i<AES_BLOCK_SIZE; ++i) {
        iv[i] = 0;
    }

    if (AES_set_encrypt_key(key, 128, &aes) < 0) {
        fprintf(stderr, "Unable to set encryption key in AES\n");
        exit(-1);
    }

    // alloc encrypt_string
    encrypt_string = (unsigned char*)calloc(len, sizeof(unsigned char));
    if (encrypt_string == NULL) {
        fprintf(stderr, "Unable to allocate memory for encrypt_string\n");
        exit(-1);
    }

    // encrypt (iv will change)
    AES_cbc_encrypt(input_string, encrypt_string, len, &aes, iv, AES_ENCRYPT);

    // alloc decrypt_string
    decrypt_string = (unsigned char*)calloc(len, sizeof(unsigned char));
    if (decrypt_string == NULL) {
        fprintf(stderr, "Unable to allocate memory for decrypt_string\n");
        exit(-1);
    }
 
    // Set decryption key
    for (i=0; i<AES_BLOCK_SIZE; ++i) {
        iv[i] = 0;
    }

    if (AES_set_decrypt_key(key, 128, &aes) < 0) {
        fprintf(stderr, "Unable to set decryption key in AES\n");
        exit(-1);
    }
 
    // decrypt
    AES_cbc_encrypt(encrypt_string, decrypt_string, len, &aes, iv, AES_DECRYPT);
 
    // print
    printf("input_string = %s\n", input_string);
    printf("encrypted string = ");
    for (i=0; i<len; ++i) {
        printf("%X%X", (encrypt_string[i] >> 4) & 0xf, encrypt_string[i] & 0xf);
    }
    printf("\n");
    printf("decrypted string = %s\n", decrypt_string);
}


std::string aesEncode(std::string data, std::string key, std::string iv){
    std::string enStr;
    AES_KEY aes;

    if (AES_set_encrypt_key((const unsigned char *)key.c_str(), 128, &aes) < 0) {
        fprintf(stderr, "Unable to set encryption key in AES\n");
        exit(-1);
    }

    // set the encryption length
    int len = 0;
    if ((data.length() + 1) % AES_BLOCK_SIZE == 0) {
        len = data.length() + 1;
    } else {
        len = ((data.length() + 1) / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;
    }

    // alloc encrypt_string
    unsigned char *encrypt_string = (unsigned char*)calloc(len, sizeof(unsigned char));
    if (encrypt_string == NULL) {
        fprintf(stderr, "Unable to allocate memory for encrypt_string\n");
        exit(-1);
    }

    // encrypt (iv will change)
    AES_cbc_encrypt((const unsigned char*)data.c_str(), encrypt_string, len, &aes, (unsigned char *)iv.c_str(), AES_ENCRYPT);
    enStr = (char *)encrypt_string;
    return enStr;
}

std::string aesDecode(std::string data, std::string key, std::string iv){
    std::string deStr;
    AES_KEY aes;


    if (AES_set_decrypt_key((const unsigned char*)key.c_str(), 128, &aes) < 0) {
        fprintf(stderr, "Unable to set decryption key in AES\n");
        exit(-1);
    }

    int len = data.length();

    // alloc decrypt_string
    unsigned char* decrypt_string = (unsigned char*)calloc(len, sizeof(unsigned char));
    if (decrypt_string == NULL) {
        fprintf(stderr, "Unable to allocate memory for decrypt_string\n");
        exit(-1);
    }

    // decrypt
    AES_cbc_encrypt((const unsigned char*)data.c_str(), decrypt_string, len, &aes, (unsigned char*)iv.c_str(), AES_DECRYPT);

    // print
    // printf("input_string = %s\n", data);
    printf("encrypted string = ");
    for (int i=0; i < len; ++i) {
        printf("%X%X", (data[i] >> 4) & 0xf, data[i] & 0xf);
    }
    printf("\n");
    printf("decrypted string = %s\n", decrypt_string);
    deStr = (char*)decrypt_string;
    return deStr;
}


void aesTest(){
    std::string data = "hello everybody!hello everybody!hello everybody!hello everybody!";
    std::string key="1112130987654321";
    std::string iv= "1234567890111213";
    std::string encodeStr = aesEncode(data, key, iv);
    std::string decodeStr = aesDecode(encodeStr, key, iv);
}

int main(){
    // autoAes();
    aesTest();
    return 0;
}
