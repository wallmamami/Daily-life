.PHONY: all clean

all: test rd

test: test.c 
	gcc -o $@ $^ -L. -ladd

rd: rd.c
	gcc -o $@ $^

clean:
	rm -f test rd
