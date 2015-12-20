CXX      = clang++
CFLAGS   = -I include/logging
CXXFLAGS = --std=c++11 -Wall -Wextra -Werror

# default to the max log level
CPPFLAGS  = -DDEFAULT_LOG_LEVEL=7

# default for demo
CPPFLAGS += -DLOGGING_RUNTIME -DLOGGING_STDIO -DLOGGING_COLORED

# Change this
CPPFLAGS += -DLOGGING_IDENTIFIER="logging_test"  

SRCS     = src/logging.cpp
OBJECTS  = obj/logging.o

all: prep lib test_run

prep:
	@mkdir -p obj

all: prep $(OBJECTS)

obj/%.o : src/%.cpp
	@echo [CXX ] $<
	@$(CXX) $(CXXFLAGS) $(CFLAGS) $< -c -o $@ $(CPPFLAGS)

lib: $(OBJECTS)
	@echo [LIB ] obj/liblogging_runtime_stdio.a
	@ar rcs obj/liblogging_runtime_stdio.a $(OBJECTS)

test_run: lib
	@echo [TEST] $@
	@$(CXX) $(CXXFLAGS) $(CFLAGS) test/test.cpp obj/liblogging_runtime_stdio.a -o $@ $(CPPFLAGS)


clean:
	@rm -rf obj 
	@rm -f test_run
