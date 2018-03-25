driver: driver.o stack.o
	gcc -g -o driver driver.o stack.o -lm -lcs50
driver.o: driver.c stack.h
	gcc -g -c driver.c -lm -lcs50
stack.o: stack.c stack.h
	gcc -g -c stack.c -lm -lcs50