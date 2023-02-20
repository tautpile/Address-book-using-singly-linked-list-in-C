SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)
SOBJ:= libfunction_list.so
LDFLAGS:=-shared
CFLAGS:=-Wall -fPIC
CPPFLAGS:=-I./

.PHONY: all clean 

all: $(SOBJ)

$(SOBJ): $(OBJS)
	$(CC) $(LDFLAGS) -o $(SOBJ) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(SOBJ) $(OBJS)

