
#include <iostream>

#include "AesEncrypt.h"
#include "AesTest.h"

std::string data = "hello everybody!hello everybody!hello everybody!hello everybody!";

// is not ok
int RunTest01(){

    AesEncrypt aes;

    std::string encodeStr = aes.aesEncode(data);
    std::string decodeStr = aes.aesDecode(encodeStr);
    std::cout << decodeStr << std::endl;

    return 0;
}

// is ok
int RunTest02(){
    std::string key="1112130987654321";
    std::string iv= "1234567890111213";
    std::string encodeStr = aesEncode(data, key, iv);
    std::cout << encodeStr << std::endl;
    std::string decodeStr = aesDecode(encodeStr, key, iv);
    std::cout << decodeStr << std::endl;
    return 0;
}


int main(){
    RunTest01();
    // RunTest02();
    return 0;
}