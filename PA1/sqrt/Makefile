CFLAG = -std=c99

all: sqrt

sqrt: main.c sqrt.c 
	gcc ${CFLAG} -o sqrt main.c sqrt.c sqrt_ref.o

clean: 
	rm -f sqrt
	rm -f result.txt
