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
	./aoc-01-a <test/in-a.txt > out-test-a.txt
	diff test/out-a.txt out-test-a.txt

test-b: aoc-01-b
	./aoc-01-b <test/in-b.txt > out-test-b.txt
	diff test/out-b.txt out-test-b.txt

aoc-01-a: aoc-01-a.o
aoc-01-b: aoc-01-b.o
