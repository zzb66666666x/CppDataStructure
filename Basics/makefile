objects = main.o
files = main.cpp functions.h makefile
CC = g++
CFLAGS = -g -Wall

main: $(objects)
	$(CC) $(objects) -o main $(CFFLAGS)
	@echo make done

clean:
	del main.exe $(objects)
	@echo clean done

upload:
	git add $(files)
	git commit -m"updated"
	git push -u origin master