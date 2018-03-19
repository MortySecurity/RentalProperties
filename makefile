CC = gcc
CC_FLAGS = -g -pedantic -Wall -W 
FILES = main.c rental.c Node.c sort.c
OUT_EXE = ass1

build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

clean:
	rm -f *.o core *.exe *~ *.out *.stackdump
	

rebuild: clean build
	
