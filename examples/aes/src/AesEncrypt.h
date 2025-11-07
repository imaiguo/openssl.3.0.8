

#include <string>

#include <openssl/aes.h>

class AesEncrypt{

public:
    std::string aesEncode(std::string& plaintext);
    std::string aesDecode(std::string& ciphertext);
};