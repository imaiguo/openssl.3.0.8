#include <iostream>
#include "generateRsa.h"

using namespace std;

std::string readFileData( std::string path ){

  std::ifstream is (path, std::ifstream::binary);
  std::string res="";
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    char * buffer = new char [length+1];

    std::cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);
    buffer[length]='\0';

    if (is)
      std::cout << "all characters read successfully.";
    else
      std::cout << "error: only " << is.gcount() << " could be read";
    is.close();

    res = buffer;

    delete[] buffer;
    return res;
  }
  return res;
}

void generate()
{
    // 原始明文  
    std::string src_text = "test begin\n this is an rsa test example!test begin\n this is an rsa test example!test begin\n this is an rsa test example!test begin\n this is an rsa test example!test begin\n this is an rsa test example!test begin\n this is an rsa test example!test begin\n this is an rsa test example!test begin\n this is an rsa test example!";
 
    std::string encrypt_text;
    std::string decrypt_text;
 
    // 生成密钥对
    std::string pub_key;
    std::string pri_key;
    OpensslTool::GenerateRSAKey(pub_key, pri_key);
    printf("public key:\n");
    printf("%s\n", pub_key.c_str());
    printf("private key:\n");
    printf("%s\n", pri_key.c_str());
 
    // 私钥加密-公钥解密
    encrypt_text = OpensslTool::RsaPriEncrypt(src_text, pri_key);
    printf("encrypt: len=%d\n", encrypt_text.length());
    decrypt_text = OpensslTool::RsaPubDecrypt(encrypt_text, pub_key);
    printf("decrypt: len=%d\n", decrypt_text.length());
    printf("decrypt: %s\n", decrypt_text.c_str());
 
    // 公钥加密-私钥解密
    encrypt_text = OpensslTool::RsaPubEncrypt(src_text, pub_key);
    printf("encrypt: len=%d\n", encrypt_text.length());
    decrypt_text = OpensslTool::RsaPriDecrypt(encrypt_text, pri_key);
    printf("decrypt: len=%d\n", decrypt_text.length());
    printf("decrypt: %s\n", decrypt_text.c_str());
}

void rsaTest(){
    // 原始明文  
    std::string src_text = "You're my sunshine!";
 
    std::string encrypt_text;
    std::string decrypt_text;
 
    // 读取公钥文件
    std::string pub_key = readFileData(TEST_PUB_KEY_FILE);
    std::string pri_key = readFileData(TEST_PRI_KEY_FILE);

    printf("public key:\n");
    printf("%s\n", pub_key.c_str());
    printf("private key:\n");
    printf("%s\n", pri_key.c_str());
 
    // 私钥加密-公钥解密
    encrypt_text = OpensslTool::RsaPriEncrypt(src_text, pri_key);
    printf("encrypt: len=%d\n", encrypt_text.length());
    decrypt_text = OpensslTool::RsaPubDecrypt(encrypt_text, pub_key);
    printf("decrypt: len=%d\n", decrypt_text.length());
    printf("decrypt: %s\n", decrypt_text.c_str());

    // 公钥加密-私钥解密
    encrypt_text = OpensslTool::RsaPubEncrypt(src_text, pub_key);
    printf("encrypt: len=%d\n", encrypt_text.length());
    decrypt_text = OpensslTool::RsaPriDecrypt(encrypt_text, pri_key);
    printf("decrypt: len=%d\n", decrypt_text.length());
    printf("decrypt: %s\n", decrypt_text.c_str());
}

int main(){
    rsaTest();
    generate();
    return 0;
}