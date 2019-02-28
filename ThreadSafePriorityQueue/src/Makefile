CC = g++
CFLAGS  = -std=c++11 -g -Wall -lpthread

all: thread_safe_priority_queue

thread_safe_priority_queue: main.cpp TagData.o Model.o
	$(CC) $(CFLAGS) -o thread_safe_priority_queue TagData.o Model.o main.cpp

Model.o: Model.cpp Model.h ThreadsafePriorityQueue.hpp
	$(CC) $(CFLAGS) -c Model.cpp

TagData.o: TagData.cpp TagData.h
	$(CC) $(CFLAGS) -c TagData.cpp

clean:
	rm -f *.o thread_safe_priority_queue