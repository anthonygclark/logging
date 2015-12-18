
#include "logging.hh"

using namespace logging;

int main(void)
{
    logging::init_logging();

    write_log<CRIT>("Log level = %d", log_level);
    write_log<INFO>("%s test", "test");

    set_logging_level(WARNING);
    
    write_log<CRIT>("Log level = %d", log_level);
    write_log<INFO>("You shouldnt see this");

}
