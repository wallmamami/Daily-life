.PHONY: clean

a.out: test.o List.o
	gcc $^ -o a.out

%.o: %.c
	gcc -c $^ -o $@

clean: 
	rm -rf *.o  rm-rf a.out

