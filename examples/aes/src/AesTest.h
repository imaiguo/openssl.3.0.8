
#pragma once

#include <string>

void autoAes();

std::string aesEncode(std::string data, std::string key, std::string iv);
std::string aesDecode(std::string data, std::string key, std::string iv);
