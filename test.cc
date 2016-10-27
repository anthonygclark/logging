#include "logging/logging.hh"
using namespace NAMESPACE;

int main(void)
{
    init_logging();
    set_logging_level(DEBUG); 
    write_log<DEBUG>("Logging Mode : %s", log_mode == RUNTIME ?
                     "runtime" : "compile time");

    /* if the log level is <= 6, this should not do anything when 
     * LOGGING_COMPILETIME is defined as you cannot change the
     * log level when it is compiled in */

    write_log<CRIT>("Log level = %d", runtime_log_level);
    write_log<INFO>("%s test", "INFO");
    write_log<WARNING>("%s test", "WARNING");
    write_log<DEBUG>("%s test", "DEBUG");

    set_logging_level(WARNING);
    
    write_log<CRIT>("Log level = %d", runtime_log_level);
    write_log<INFO>("%s test", "INFO");
    write_log<WARNING>("%s test", "WARNING");
 
    /* should not see these in either mode - runtime or compile time */
    bool res = log_mode == RUNTIME && runtime_log_level >= DEBUG;
    res = log_mode || (log_mode == COMPILETIME && compiletime_log_level >= DEBUG);


    return 0;

    write_log<DEBUG>("DEBUG - Should you see this? %s",
                     res ? "yes" : "no");

    for (int i = 0; i < 5; ++i)
    {
        write_log<CRIT>("Logging test %d\n", i);
        write_log<WARNING>("Logging test %d\n", i);
    }
}
