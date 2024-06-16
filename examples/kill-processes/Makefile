all: runner subrunner main

runner:
	gcc -o $@ $@.c

subrunner:
	gcc -o $@ $@.c

main:
	gcc -o test main.c

clean:
	rm -f runner subrunner test
