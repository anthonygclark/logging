
all: ct_syslog rt_syslog ct_stdio rt_stdio


ct_syslog: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DLOGGING_IDENTIFIER="test" -DLOGGING_SYSLOG -DLOGGING_COMPILE_TIME -lpthread -o $@

rt_syslog: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DLOGGING_IDENTIFIER="test" -DLOGGING_SYSLOG -DLOGGING_RUNTIME -lpthread -o $@

ct_stdio: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DCOLORED_LOGGING -DLOGGING_STDIO -DLOGGING_COMPILE_TIME -o $@

rt_stdio: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DCOLORED_LOGGING -DLOGGING_STDIO -DLOGGING_RUNTIME -o $@

clean:
	rm -f rt_stdio
	rm -f ct_stdio
	rm -f rt_syslog
	rm -f ct_syslog
