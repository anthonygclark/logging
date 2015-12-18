#ifndef LOGGING_RUNTIME_LOGGING_H
#define LOGGING_RUNTIME_LOGGING_H 1

#include <cstdarg>
#include <cstdio>
#include "logging_defs.hh"

namespace logging
{
    template<enum LogLevel L>
        void write_log(const char * format, ...)
        {
            va_list args;
            va_start(args, format);

            if (L > log_level)
            {
                va_end(args);
                return;
            }

            logging_impl_function(L, format, args);

            va_end(args);
        }
}

#endif /* guard */
