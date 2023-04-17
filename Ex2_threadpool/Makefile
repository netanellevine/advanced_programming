.PHONY: all
all: task stdinExample

task:	codec.h basic_main.c
	gcc -g -Wall basic_main.c -L. -lCodec -lpthread -o encoder

stdinExample:	stdin_main.c
		gcc -g -Wall stdin_main.c -L. -lCodec -lpthread -o tester

.PHONY: clean
clean:
	-rm encoder tester  2>/dev/null

# export LD_LIBRARY_PATH=/home/netanel/private/advanced_programming/Ex2_threadpool

