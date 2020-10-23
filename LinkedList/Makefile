CC=g++
CF=-std=c++11
OBJS=ldriver.o allocator.o
OUTPUT=ldriver

all: $(OBJS)
	$(CC) $(CF) $(OBJS) -o $(OUTPUT)

ldriver.o: ldriver.cpp LinkedList.hpp
	$(CC) $(CF) -c ldriver.cpp -o ldriver.o

%.o: %.cpp
	$(CC) $(CF) -c $< -o $@

cleanw:
	del /f $(filter-out tester.o, $(wildcard *.o))
	del /f $(OUTPUT).exe

clean:
	rm -f $(filter-out tester.o, $(wildcard *.o))
	rm $(OUTPUT)