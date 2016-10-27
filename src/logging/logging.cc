#include "logging/logging.hh"

namespace
{
    /**
     * @brief Stupid min function
     * @details Exists to avoid including <algorithm>
     * @return The min of x and y
     */
    constexpr int _min(int x, int y)
    { return (x > y) ?  y : x; }
}

namespace NAMESPACE
{
#ifndef DEFAULT_LOG_LEVEL
#define DEFAULT_LOG_LEVEL (7)
#endif
    int compiletime_log_level = DEFAULT_LOG_LEVEL;
    int runtime_log_level = _min(LogLevel::LAST, DEFAULT_LOG_LEVEL);
#undef DEFAULT_LOG_LEVEL

#if defined (LOGGING_COMPILETIME)
    LogMode log_mode = COMPILETIME;
#elif defined (LOGGING_RUNTIME)
    LogMode log_mode = RUNTIME;
#endif
}

/* Load the logging implementation here. Each 
 * impl file must define the functions in namespace
 * logging. This technique will limit the resolution
 * of write_log. Meaning, if you have some compiled code
 * that uses LOGGING_SYSLOG and another that uses LOGGING_STDIO,
 * the results are undefined.
 */
#if defined (LOGGING_SYSLOG)
#include "logging_syslog.impl"
#elif defined (LOGGING_STDIO)
#include "logging_stdio.impl"
#else
#error "No logging implementation defined, see logging.cc"
#endif
