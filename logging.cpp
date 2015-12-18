#include "logging.hh"

namespace
{
    /* to avoid including <algorithm> */
    constexpr int _min(int x, int y)
    { return (x > y) ?  y : x; }
}

namespace logging
{
    /* Set the default log level unless specified */
#ifndef DEFAULT_LOG_LEVEL
    #define DEFAULT_LOG_LEVEL 7
#endif
    
    int log_level = _min(LogLevel::LAST, DEFAULT_LOG_LEVEL);

#undef DEFAULT_LOG_LEVEL
}

#if defined (LOGGING_SYSLOG)
    #include "logging_syslog.impl"
#elif defined (LOGGING_STDIO)
    #include "logging_stdio.impl"
#else
    #error "No logging implementation defined"
#endif
