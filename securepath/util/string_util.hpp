#ifndef SECUREPATH_UTIL_STRING_UTIL_HEADER
#define SECUREPATH_UTIL_STRING_UTIL_HEADER

#include "span.hpp"

#include <string>
#include <vector>

namespace securepath {

std::string to_hex(std::string const& str, std::string const& sep = "");
std::vector<std::string_view> split_view(std::string_view, std::string_view sep = " ");

octet_span make_span(std::string_view);
std::string_view make_view(octet_span);

std::vector<std::wstring_view> tokenise_view(std::wstring_view view, std::wstring_view sep = L" ");

}

#endif
