objects = main.o 
CC = g++
FLAGS = -g -Wall

all: test

test: $(objects)
	$(CC) $(FLAGS) $(objects)
	@echo make done

main.o: main.cpp arrayList.cpp arrayList.h
	$(CC) $(FLAGS) -c main.cpp

clean:
	del test $(objects)
	@echo clean done