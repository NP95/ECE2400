CFLAG = -std=c99

all: pow

pow: main.c pow.c 
	gcc ${CFLAG} -o pow main.c pow.c pow_ref.o

clean: 
	rm -f pow
	rm -f result.txt

