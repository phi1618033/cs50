#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

all: find generate

find: find.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror find.c helpers.c -lcs50 -lm -o find 

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core find generate