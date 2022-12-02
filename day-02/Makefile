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

test-a: aoc-02-a
	./aoc-02-a <example/in.txt > out-test-a.txt
	diff example/out-a.txt out-test-a.txt

test-b: aoc-02-b
	./aoc-02-b <example/in.txt > out-test-b.txt
	diff example/out-b.txt out-test-b.txt

aoc-02-a: aoc-02-a.o
aoc-02-b: aoc-02-b.o
