CXX      = clang++
CFLAGS   = -I include/logging
CXXFLAGS = --std=c++11 -Wall -Wextra -Werror

# default to the max log level
CPPFLAGS  = -DDEFAULT_LOG_LEVEL=7

# Change this
CPPFLAGS += -DLOGGING_IDENTIFIER="logging_test"  

SRCS     = src/logging.cpp
OBJECTS  = obj/logging.o

all:

prep:
	@mkdir -p obj

all: prep $(OBJECTS)

obj/%.o : src/%.cpp
	@echo [CXX ]
	@$(CXX) $(CXXFLAGS) $(CFLAGS) $< -c -o $@ $(CPPFLAGS)

