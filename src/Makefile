CFLAGS=-g -O3

OBJS= ui.o tokenizer.o history.o

all: tok


tok: $(OBJS)
	cc -o tok $(CFLAGS) $(OBJS)

$(OBJS):tokenizer.h history.h

clean:
	rm -f *.o
cleanX:
	rm -f tok

run: tok clean
	./tok




