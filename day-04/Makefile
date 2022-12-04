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

test-a: aoc-04-a
	./aoc-04-a <example/in.txt > out-test-a.txt
	diff example/out-a.txt out-test-a.txt

test-b: aoc-04-b
	./aoc-04-b <example/in.txt > out-test-b.txt
	diff example/out-b.txt out-test-b.txt

aoc-04-a: aoc-04-a.o
aoc-04-b: aoc-04-b.o
