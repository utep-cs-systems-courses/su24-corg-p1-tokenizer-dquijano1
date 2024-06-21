CFLAGS=-g -O3

OBJS= ui.o tokenizer.o

all: tok


tok: $(OBJS)
	cc -o tok $(CFLAGS) $(OBJS)

$(OBJS):tokenizer.h

clean:
	rm -f *.o

run: tok clean
	./tok




