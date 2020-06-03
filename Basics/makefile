objects = main.o
CC = g++
CFLAGS = -g -Wall

main: $(objects)
	$(CC) $(objects) -o main $(CFFLAGS)
	@echo make done

clean:
	del main.exe, main.o
	@echo clean done

upload:
	git add --all
	git commit -m"updated"
	git push -u origin master