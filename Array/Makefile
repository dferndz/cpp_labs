CC=g++
CF=-std=c++11
OBJS=sdriver.o operations.o clock.o tester.o utils.o
OUTPUT=sdriver

all: $(OBJS)
	$(CC) $(CF) $(OBJS) -o $(OUTPUT)

%.o: %.cpp
	$(CC) $(CF) -c $< -o $@

cleanw:
	del /f $(filter-out tester.o, $(wildcard *.o))
	del /f $(OUTPUT).exe

clean:
	rm -f $(filter-out tester.o, $(wildcard *.o))
	rm $(OUTPUT)