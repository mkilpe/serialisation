#include "util.hpp"

#include <time.h>

namespace securepath::serialisation {

bool gmtime(std::time_t time, std::tm& out) {
	return
#if defined(WIN32) or defined(__MINGW32__)
	::gmtime_s(&out, &time) == 0;
#else
	::gmtime_r(&time, &out) != nullptr;
#endif
}

std::time_t timegm(std::tm& in) {
	return
#if defined(WIN32) or defined(__MINGW32__)
	::_mkgmtime(&in);
#else
	::timegm(&in);
#endif
}

}
