CC=g++
CF=-std=c++11
OBJS=sdriver.o operations.o clock.o tester.o utils.o
OUTPUT=sdriver

all: $(OBJS)
	$(CC) $(CF) $(OBJS) -o $(OUTPUT)

%.o: %.cpp
	$(CC) $(CF) -c $< -o $@

clean:
	rm -f sdriver.o operations.o clock.o utils.o
	rm $(OUTPUT)