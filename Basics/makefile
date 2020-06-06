objects = main.o functions.o
files = main.cpp functions.h functions.cpp makefile template_class.h template_class.cpp\
		array2d.h array2d.cpp
CC = g++
FLAGS = -g -Wall

all: test

test: $(objects) 
	$(CC) $(objects) $(FLAGS) -o test
	@echo make done

main.o: main.cpp template_class.h template_class.cpp array2d.h array2d.cpp
	$(CC) $(FLAGS) -c main.cpp

functions.o: functions.cpp functions.h
	$(CC) $(FLAGS) -c functions.cpp

clean:
	del test.exe $(objects)
	@echo clean done

upload:
	git add $(files)
	git commit -m"updated"
	git push -u origin master