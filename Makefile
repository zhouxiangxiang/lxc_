C = gcc
CFLAGS =

main 	: main.cpp
	$(CXX) $(CFLAGS) -o $@ $<

.PHONY	: clean

clean:
	rm -f main