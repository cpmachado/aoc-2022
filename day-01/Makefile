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

test-a: aoc-01-a
	./aoc-01-a <example/in.txt > out-test-a.txt
	diff example/out-a.txt out-test-a.txt

test-b: aoc-01-b
	./aoc-01-b <example/in.txt > out-test-b.txt
	diff example/out-b.txt out-test-b.txt

aoc-01-a: aoc-01-a.o
aoc-01-b: aoc-01-b.o
