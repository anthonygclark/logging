#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H 1

#include "logging_defs.hh"

namespace NAMESPACE
{
    extern int runtime_log_level;
    extern int compiletime_log_level;
    extern LogMode log_mode;
}

/* Load the header for the type of logging allowed.
 * This is going to be weird if mulitple sources/libs
 * a different type - as in, write_log calls may not
 * resolve.
 */
#if defined (LOGGING_COMPILETIME)
#include "logging_compile_time.hh"
#elif defined (LOGGING_RUNTIME)
#include "logging_runtime.hh"
#else
#error "No logging pattern defined, see logging.hh"
#endif

#endif /* guard */
