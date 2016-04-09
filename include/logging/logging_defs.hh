#ifndef LOGGING_DEFS_H
#define LOGGING_DEFS_H 1

#include <cstdarg>

namespace logging
{
    /**
     * \enum LogLevel
     * @details Log Level enum. This is not an enum
     *          class intentionally.
     * @note This must mirror syslog or must contain
     *       the syslog members.
     */
    enum LogLevel
    {
        CRIT    = 2,
        CRITICAL= CRIT,
        ERR     = 3,
        ERROR   = ERR,
        WARNING = 4,
        WARN    = WARNING,
        INFO    = 6,
        DEBUG   = 7,
        LAST    = DEBUG,
    };

    /**
     * @brief Initialized the logging system.
     * @note This is defined for each implementation
     */
    void init_logging();

    /**
     * @brief Sets the logging level to use
     * @details This should only work with runtime logging
     * @param L The new log level
     * @note This is defined for each implementation
     */
    void set_logging_level(LogLevel L);

    /**
     * @brief Actual logging call (i.e., printf)
     * @param L The log level to log against
     * @param format printf-style formatting (implementation defined)
     * @param args The arguments to the format (implementation defined)
     * @note This is defined for each implementation
     */
    void logging_impl_function(LogLevel L, const char * format, va_list args);
}

#endif /* guard */
