
all: ct_syslog rt_syslog ct_stdio rt_stdio


ct_syslog: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DDEFAULT_LOG_LEVEL=6 -DLOGGING_IDENTIFIER="test" -DLOGGING_SYSLOG -DLOGGING_COMPILE_TIME -lpthread -o $@

rt_syslog: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DDEFAULT_LOG_LEVEL=6 -DLOGGING_IDENTIFIER="test" -DLOGGING_SYSLOG -DLOGGING_RUNTIME -lpthread -o $@

ct_stdio: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DDEFAULT_LOG_LEVEL=6 -DLOGGING_COLORED -DLOGGING_STDIO -DLOGGING_COMPILE_TIME -o $@

rt_stdio: test.cpp
	clang++ --std=c++11 -ggdb3 *.cpp -DDEFAULT_LOG_LEVEL=6 -DLOGGING_COLORED -DLOGGING_STDIO -DLOGGING_RUNTIME -o $@

clean:
	rm -rf rt_stdio*
	rm -rf ct_stdio*
	rm -rf rt_syslog*
	rm -rf ct_syslog*
