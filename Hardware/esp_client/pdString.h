#pragma once
#include <Arduino.h>
#include <vector>

namespace Utils
{

	std::vector<String> split(const String &str, const String &sep); //разбить строчку
}


#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a < b) ? b : a)
