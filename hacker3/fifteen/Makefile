#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

fifteen: fifteen.c libfifteen.o
	clang -ggdb3 -O0 -std=c11 -Wall -Werror fifteen.c libfifteen.o -lcs50 -lm -o fifteen
libfifteen.o: libfifteen.c libfifteen.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -c libfifteen.c 


clean:
	rm -f *.o a.out core fifteen
