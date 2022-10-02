#ifndef SECUREPATH_UTIL_CONVERSIONS_HEADER
#define SECUREPATH_UTIL_CONVERSIONS_HEADER

#include "types.hpp"
#include "span.hpp"

#include <string>
#include <string_view>

namespace securepath {

	/// creates hex encoded string from binary data, uses capital letters in the encoding
	std::string to_hex(octet_span);

	/// create binary data from hex encoded string, accepts small and capital letters in the encoding
	octet_vector from_hex(std::string_view);

}

#endif
