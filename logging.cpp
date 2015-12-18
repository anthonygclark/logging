#include "logging.hh"

namespace logging
{
#ifndef DEFAULT_LOG_LEVEL
#define DEFAULT_LOG_LEVEL 7
#endif
    
    int log_level = min(LogLevel::LAST, DEFAULT_LOG_LEVEL);

#undef DEFAULT_LOG_LEVEL

}

#if defined (LOGGING_SYSLOG)
    #include "logging_syslog.impl"
#elif defined (LOGGING_STDIO)
    #include "logging_stdio.impl"
#else
    #error "No logging implementation defined"
#endif
