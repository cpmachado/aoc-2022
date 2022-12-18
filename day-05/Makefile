include ../config.mk


SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
BIN = aoc-05-a aoc-05-b

all: ${BIN}
	@echo all built

clean:
	@rm -rf ${BIN} ${OBJ} out-test-*


%:
	${CC} -o $@ $^ ${LDFLAGS}

test-a: aoc-05-a
	./aoc-05-a <example/in.txt > out-test-a.txt
	diff example/out-a.txt out-test-a.txt

test-b: aoc-05-b
	./aoc-05-b <example/in.txt > out-test-b.txt
	diff example/out-b.txt out-test-b.txt

stack.o: stack.c
warehouse.o: warehouse.c

aoc-05-a: aoc-05-a.o stack.o warehouse.o
aoc-05-b: aoc-05-b.o stack.o warehouse.o
