![screenshot](/screen.png)

This is a simple little logging abstraction that aims to soley be a playground for a small obsession with logging.

###Here is how it works: 

If `LOGGING_COMPILE_TIME` is defined, then `logging.hh` will include `logging_compile_time.hh`. This means that `void set_log_level(LogLevel)` will do nothing to effect the actual logging - though the function may have side effects.

If `LOGGING_RUNTIME` is defined, then `logging.hh` will include `logging_runtime.hh`. `void set_log_level(LogLevel)` will/must effect the decision to log. This has branch overhead to check if `write_log<L>(...)` can log.

If `LOGGING_SYSLOG` is defined, then `logging.cpp` will include `logging_syslog.impl`. This file implements the manadory functions to use syslog.

If `LOGGING_STDIO` is defined, then `logging.cpp` will include `logging_stdio.impl`. This file implements the manadory functions to use stdio logging - like `fprintf(stderr,...)`. This will attempt to uses an ANSI colored tag when logging to a console, but avoid the colors when the log destination is directed to a non-tty (like a file, think `./a.out > log`).
