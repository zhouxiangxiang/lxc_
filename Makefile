C = gcc
CFLAGS =

main 	: container.c
	$(C) $(CFLAGS) -o $@ $<

.PHONY	: clean

clean:
	rm -f main
