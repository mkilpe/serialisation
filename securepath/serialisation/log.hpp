
#ifndef SECUREPATH_SERIALISATION_LOG_HEADER
#define SECUREPATH_SERIALISATION_LOG_HEADER

namespace {
	template<typename... Args>
	inline void ser_no_log(char const*, Args...) {}
}

#ifndef LOG_TRACE
#define LOG_TRACE ser_no_log
#endif

#ifndef LOG_INFO
#define LOG_INFO ser_no_log
#endif

#ifndef LOG_WARN
#define LOG_WARN ser_no_log
#endif

#endif