#ifndef LOGGING_COMPILE_TIME_H
#define LOGGING_COMPILE_TIME_H 1

#include <type_traits>
#include <cstdarg>

#include "logging_defs.hh"

namespace logging
{

#ifndef DEFAULT_LOG_LEVEL
#define DEFAULT_LOG_LEVEL 7
#endif
    constexpr static int ct_log_level = DEFAULT_LOG_LEVEL;
#undef DEFAULT_LOG_LEVEL


    template<enum LogLevel L>
        typename std::enable_if<(ct_log_level >= L), void>::type
        write_log(const char * format, va_list args)
        {
            logging_impl_function(L, format, args);
        }

    template<enum LogLevel L>
        typename std::enable_if<(ct_log_level >= L), void>::type
        write_log(const char * format, ...)
        {
            va_list args;
            va_start(args, format);
            write_log<L>(format, args);
            va_end(args);
        }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
    
    template<enum LogLevel L>
        typename std::enable_if<(ct_log_level < L), void>::type
        write_log(const char * format, va_list args)
        {
            /* Intentionally left black for SFINAE */
        }

    template<enum LogLevel L>
        typename std::enable_if<(ct_log_level < L), void>::type
        write_log(const char * format, ...)
        {
            /* Intentionally left black for SFINAE */
        }

#pragma GCC diagnostic pop
}

#endif /* guard */
