ser=server
cli=client


.PHONY: all

all: $(ser) $(cli)

$(ser): server.c
	gcc -o $@ $^

$(cli):client.c
	gcc -o $@ $^

.PHONY: clean

clean:
	rm -f $(ser) $(cli)
