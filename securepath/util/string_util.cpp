#include "string_util.hpp"

#include <cwchar>
#include <string>

namespace securepath {

std::string to_hex(std::string const& str, std::string const& sep) {
	char const encoded[] = "0123456789ABCDEF";
	std::string ret;
	for(auto&& c : str) {
		if(!ret.empty()) {
			ret += sep;
		}
		ret += encoded[std::uint8_t(c) >> 4];
		ret += encoded[std::uint8_t(c) & 0x0f];
	}
	return ret;
}

std::vector<std::string_view> split_view(std::string_view view, std::string_view sep) {
	std::vector<std::string_view> res;
	std::string_view::size_type start = 0, end = 0;

	if(!view.empty()) {
		while(end != std::string_view::npos) {
			end = view.find_first_of(sep, start);
			if(end == std::string_view::npos) {
				res.emplace_back(view.substr(start));
			} else {
				res.emplace_back(view.substr(start, end-start));
			}
			start = end + 1;
		}
	}

	return res;
}

octet_span make_span(std::string_view v) {
	return octet_span(reinterpret_cast<std::uint8_t const*>(v.data()), v.size());
}

std::string_view make_view(octet_span s) {
	return std::string_view(reinterpret_cast<char const*>(s.data()), s.size());
}

std::vector<std::wstring_view> tokenise_view(std::wstring_view view, std::wstring_view sep) {
	std::vector<std::wstring_view> res;
	std::wstring_view::size_type start = 0, end = 0;

	if(!view.empty()) {
		while(end != std::wstring_view::npos) {
			end = view.find_first_of(sep, start);
			if(end == std::wstring_view::npos) {
				res.emplace_back(view.substr(start));
			} else if(end-start > 0) {
				res.emplace_back(view.substr(start, end-start));
			}
			start = end + 1;
		}
	}

	return res;
}

}

