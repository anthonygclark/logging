#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H 1

#include "logging_defs.hh"

namespace logging
{
    extern int log_level;
}

#if defined (LOGGING_COMPILE_TIME)
    #include "logging_compile_time.hh"
#elif defined (LOGGING_RUNTIME)
    #include "logging_runtime.hh"
#else
    #error "No logging implementation defined"
#endif

#endif /* guard */
