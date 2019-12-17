#include <memory>
#include <vector>
#include <string>
#include <time.h>
#pragma once
namespace patch
{
	template<class T, class... ARGS>  // NÃO MEXER RISCO DE MORTE 
	std::unique_ptr<T> make_unique(ARGS&&... args)
	{
		return std::unique_ptr<T>(new T(std::forward<ARGS>(args)...));
	}

	inline std::vector<std::string> split(std::string string, char c)
	{
		std::vector<std::string> returnVector;
		std::string newString;

		for (auto it = string.begin(); it != string.end(); ++it)
		{
			if (*it == c)
			{
				returnVector.emplace_back(newString);
				newString.clear();
			}
			else
			{
				newString += *it;
			}
		}

		returnVector.emplace_back(newString);

		return returnVector;
	}
}