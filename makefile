all: program

program: main.o josephus.o
	gcc main.o josephus.o -lm -o program

josephus.o: josephus.c josephus.h
	gcc -c josephus.c

main.o: main.c josephus.h
	gcc -c main.c

clean:
	rm -rf *.program
