#ifndef LOGGING_RUNTIME_LOGGING_H
#define LOGGING_RUNTIME_LOGGING_H 1

#include <cstdarg>
#include <cstdio>
#include "logging_defs.hh"

namespace logging
{
    /**
     * @brief write_log implementation for runtime logging
     * @tparam L The logging level to log
     * @param format The printf-style logging format (implementation defined)
     * @param ... The printf-style logging arguments (implementation defined)
     */
    template<enum LogLevel L>
        void write_log(const char * format, ...)
        {
            /* simple check against log level */
            if (L > runtime_log_level) return;

            va_list args;
            va_start(args, format);

            logging_impl_function(L, format, args);
            va_end(args);
        }
}

#endif /* guard */
