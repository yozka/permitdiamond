#include "pdString.h"


//разбить строчку
std::vector<String>  Utils::split(const String &str, const String &sep)
{
	std::vector<String> ls;
	const int len = str.length();
	int left = 0;
	while (left < len)
	{
		int right = str.indexOf(sep, left);
		if (right == -1)
		{
			right = len;
		}
		const int count = right - left;
		if (count > 0)
		{
			ls.push_back(str.substring(left, right));
		}
		left = right + sep.length();
	}
	return ls;
}