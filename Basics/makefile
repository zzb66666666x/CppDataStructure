DIR_OBJ = ./obj

cpp_files = $(wildcard *.cpp)
header_files = $(wildcard *.h)
all_files = $(cpp_files) $(header_files) makefile 
objects = $(patsubst %.cpp,  $(DIR_OBJ)/%.o, $(cpp_files))

CC = g++
FLAGS = -g -Wall

all: test

test: $(objects) 
	$(CC) $(objects) $(FLAGS) -o $@
	@echo make done

$(DIR_OBJ)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	@rm *.exe
	@rm $(objects)
	@echo clean done

upload:
	git add $(all_files)
	git commit -m"updated"
	git push -u origin master