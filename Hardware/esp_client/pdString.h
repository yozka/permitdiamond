#pragma once
#include <Arduino.h>
#include <vector>

namespace Utils
{

	std::vector<String> split(const String &str, const String &sep); //разбить строчку
}

