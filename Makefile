flags = -Wall -Werror -std=c89 -pedantic

default: libshlang.a

test: test.out
	./test.out

test.out: test.c libshlang.a
	gcc $< -o $@ $(flags) -g -L. -lshlang

libshlang.a: shlang.o
	ar -rc $@ $^
	ranlib $@

shlang.o: shlang.c shlang.h
	gcc $< -c -o $@ $(flags)

clean:
	rm -f *.o *.a test.out

.PHONY: clean test
