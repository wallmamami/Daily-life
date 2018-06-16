a.out: main.o add.o sub.o mul.o div.o
		gcc $^ -o $@
%.o: %.c
		gcc -c $^ -o $@
clean:
	rm -rf *.o

