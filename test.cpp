
#include "logging.hh"

using namespace logging;

int main(void)
{
    logging::init_logging();

    write_log<CRIT>("Log level = %d", log_level);
    write_log<INFO>("%s test", "INFO");
    write_log<WARNING>("%s test", "WARNING");
    write_log<DEBUG>("%s test", "DEBUG");

    set_logging_level(WARNING);
    
    write_log<CRIT>("Log level = %d", log_level);
    write_log<INFO>("%s test", "INFO");
    write_log<WARNING>("%s test", "WARNING");
    write_log<DEBUG>("%s test", "DEBUG");
    
    write_log<INFO>("You shouldnt see this unless you're a compile time (ct) implementation");
}
