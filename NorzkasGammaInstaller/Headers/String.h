#pragma once

#include <string>

/* TODO: ADD TO NOSLIB */
namespace CustomStrings
{
	std::wstring trim(const std::wstring& str, const std::wstring& whitespace = L" \t")
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::wstring::npos)
			return L""; // no content

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	std::wstring reduce(const std::wstring& str, const std::wstring& fill = L" ", const std::wstring& whitespace = L" \t")
	{
		// trim first
		auto result = trim(str, whitespace);

		// replace sub ranges
		auto beginSpace = result.find_first_of(whitespace);
		while (beginSpace != std::wstring::npos)
		{
			const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
			const auto range = endSpace - beginSpace;

			result.replace(beginSpace, range, fill);

			const auto newStart = beginSpace + fill.length();
			beginSpace = result.find_first_of(whitespace, newStart);
		}

		return result;
	}
}
