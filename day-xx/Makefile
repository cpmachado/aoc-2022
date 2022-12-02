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

test-a: aoc-xx-a
	./aoc-xx-a <test/in-a.txt > out-test-a.txt
	diff test/out-a.txt out-test-a.txt

test-b: aoc-xx-b
	./aoc-xx-b <test/in-b.txt > out-test-b.txt
	diff test/out-b.txt out-test-b.txt

aoc-xx-a: aoc-xx-a.o
aoc-xx-b: aoc-xx-b.o
