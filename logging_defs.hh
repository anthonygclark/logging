#ifndef LOGGING_DEFS_H
#define LOGGING_DEFS_H 1

#include <cstdarg>

namespace
{
    constexpr int min(int x, int y)
    { return (x > y) ?  y : x; }
}

namespace logging
{
    /* mirrors syslog */
    enum LogLevel
    {
        CRIT    = 2,
        WARNING = 4,
        INFO    = 6,
        DEBUG   = 7,
        LAST    = DEBUG,
    };
    

    void init_logging();

    void set_logging_level(LogLevel L);

    void logging_impl_function(LogLevel L, const char * format, va_list args);
}

#endif /* guard */
