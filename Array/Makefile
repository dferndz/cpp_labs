CC=g++
CF=-std=c++11
OBJS=sdriver.o my_sort.o clock.o
OUTPUT=sdriver

all: $(OBJS)
	$(CC) $(CF) $(OBJS) -o $(OUTPUT)

%.o: %.cpp
	$(CC) $(CF) -c $< -o $@

clean:
	rm -f *.o
	rm $(OUTPUT)