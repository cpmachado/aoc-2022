include ../config.mk


SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
BIN = ${SRC:.c=}

all: ${BIN}
	@echo all built

clean:
	@rm -rf ${BIN} ${OBJ} out-test-*


%:
	${CC} -o $@ $< ${LDFLAGS}

test-a: aoc-08-a
	./aoc-08-a <example/in.txt > out-test-a.txt
	diff example/out-a.txt out-test-a.txt

test-b: aoc-08-b
	./aoc-08-b <example/in.txt > out-test-b.txt
	diff example/out-b.txt out-test-b.txt

aoc-08-a: aoc-08-a.o
aoc-08-b: aoc-08-b.o
