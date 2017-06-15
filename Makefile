#!/usr/bin/make -f

LIBDIR=lib
SRCDIR=src
INCDIR=include
OBJDIR=obj
OBJS=
CXXFLAGS=--std=c++14 -Werror -Wall -Wextra

.PHONY: all
all: 

define LOGGING
  IDENTIFIER := $(1)
  IDENTIFIER_U := $(shell echo $(1) | tr '[:lower:]' '[:upper:]')
  MODE := $(2)
  METHOD := $(3)
  COLORS := $(4)

  ifeq ($$(COLORS), yes)
	COLORS=-DLOGGING_ENABLE_COLORS
  else
	COLORS=
 endif

  LOGFLAGS := -D$$(MODE) -D$$(METHOD) -DLOGGING_IDENTIFIER="$$(IDENTIFIER)" $$(COLORS)
  STATIC_LIB := $(LIBDIR)/liblogging_$$(IDENTIFIER).a

  # Create dirs if they don't exist
  prep_logging_$$(IDENTIFIER):
	@mkdir -p $$(OBJDIR)/logging
	@mkdir -p $$(LIBDIR)

  # Objects
  $$(OBJDIR)/logging/logging_$$(IDENTIFIER).o: $$(SRCDIR)/logging/logging.cc
	$(CXX) $(CXXFLAGS) $(CFLAGS) -I $$(INCDIR) $$< -c -o $$@ $(CPPFLAGS) $$(LOGFLAGS)

  # Static lib
  $$(STATIC_LIB) : $$(OBJDIR)/logging/logging_$$(IDENTIFIER).o
	ar rcs $$@ $$^

  # Main build rule
  logging_$$(IDENTIFIER): prep_logging_$$(IDENTIFIER) $$(OBJDIR)/logging/logging_$$(IDENTIFIER).o

  # Export some important vars
  LOGGING_$$(IDENTIFIER_U)_CPPFLAGS := $$(LOGFLAGS)
  LOGGING_$$(IDENTIFIER_U)_CFLAGS := $(CFLAGS) -I $(INCDIR)
  LOGGING_$$(IDENTIFIER_U)_LIB := $$(STATIC_LIB)

  export $$(LOGGING_$$(IDENTIFIER_U)_CPPFLAGS)
  export $$(LOGGING_$$(IDENTIFIER_U)_CFLAGS)
  export $$(LOGGING_$$(IDENTIFIER_U)_LIB)
endef

# exapand function, creates rules
$(eval $(call LOGGING, test1, LOGGING_RUNTIME, LOGGING_STDIO, yes))
#$(eval $(call LOGGING, test2, LOGGING_COMPILETIME, LOGGING_STDIO, yes))
#$(eval $(call LOGGING, test3, LOGGING_RUNTIME, LOGGING_SYSLOG, no))
#$(eval $(call LOGGING, test4, LOGGING_COMPILETIME, LOGGING_SYSLOG, yes))

all: test1 
	
test1: logging_test1 lib/liblogging_test1.a
	$(CXX) $(CXXFLAGS) $(CFLAGS) test.cc $(LOGGING_TEST1_CFLAGS) -lpthread $(LOGGING_TEST1_LIB) $(LOGGING_TEST1_CPPFLAGS) -o test_1

test2: logging_test2 lib/liblogging_test2.a
	$(CXX) $(CXXFLAGS) $(CFLAGS) test.cc $(LOGGING_TEST2_CFLAGS) -lpthread $(LOGGING_TEST2_LIB) $(LOGGING_TEST2_CPPFLAGS) -o test_2

test3: logging_test3 lib/liblogging_test3.a
	$(CXX) $(CXXFLAGS) $(CFLAGS) test.cc $(LOGGING_TEST3_CFLAGS) -lpthread $(LOGGING_TEST3_LIB) $(LOGGING_TEST3_CPPFLAGS) -o test_3

test4: logging_test4 lib/liblogging_test4.a
	$(CXX) $(CXXFLAGS) $(CFLAGS) test.cc $(LOGGING_TEST4_CFLAGS) -lpthread $(LOGGING_TEST4_LIB) $(LOGGING_TEST4_CPPFLAGS) -o test_4

clean:
	@rm -rf obj 
	@rm -rf lib
	@rm -f test_{1,2,3,4,5}

# Helper to print any variable via `make print-VAR`
print-%:
	@echo $* = $($*) | tr ' ' '\n'

