#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H 1

#include "logging_defs.hh"

namespace logging
{
    extern int runtime_log_level;
}



/* Load the header for the type of logging allowed.
 * This is going to be weird if mulitple sources/libs
 * a different type - as in, write_log calls may not
 * resolve.
 */
#if defined (LOGGING_COMPILE_TIME)
    #include "logging_compile_time.hh"
#elif defined (LOGGING_RUNTIME)
    #include "logging_runtime.hh"
#else
    #error "No logging pattern defined"
#endif

#endif /* guard */
