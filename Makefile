CXX      ?= clang++
CFLAGS   ?= -I include/logging
CXXFLAGS ?= --std=c++11 -Wall -Wextra -Werror

# default for demo
CPPFLAGS ?= -DDEFAULT_LOG_LEVEL=7 -DLOGGING_RUNTIME -DLOGGING_STDIO -DLOGGING_IDENTIFIER="logging_test"  

ifndef CPPFLAGS
$(error CPPFLAGS not set, this is how this library functions)
endif

SRCS     = src/logging.cpp
OBJECTS  = obj/logging.o

all: prep liblogging.a test_run

prep:
	@mkdir -p obj

all: prep $(OBJECTS)

obj/%.o : src/%.cpp
	@echo "[CXX ] $<"
	@$(CXX) $(CXXFLAGS) $(CFLAGS) $< -c -o $@ $(CPPFLAGS)

liblogging.a: $(OBJECTS)
	@echo "[LIB ] $@"
	@ar rcs $@ $(OBJECTS)

test_run: liblogging.a
	@echo "[TEST] $@"
	@$(CXX) $(CXXFLAGS) $(CFLAGS) test/test.cpp liblogging.a -o $@ $(CPPFLAGS)

clean:
	@rm -rf obj 
	@rm -f test_run
