
#include "logging.hh"

using namespace logging;

int main(void)
{
    init_logging();
    set_logging_level(DEBUG); 
    /* if the log level is <= 6, this should not do anything when 
     * LOGGING_COMPILE_TIME is defined as you cannot change the
     * log level when it is compiled in */

    write_log<CRIT>("Log level = %d", log_level);
    write_log<INFO>("%s test", "INFO");
    write_log<WARNING>("%s test", "WARNING");
    write_log<DEBUG>("%s test", "DEBUG");

    set_logging_level(WARNING);
    
    write_log<CRIT>("Log level = %d", log_level);
    write_log<INFO>("%s test", "INFO");
    write_log<WARNING>("%s test", "WARNING");
 
    /* should not see these in either mode - runtime or compile time */
    write_log<DEBUG>("%s test", "DEBUG - should not see this");
}