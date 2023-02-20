SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)
BIN:=address
CPPFLAGS:=-I../lib
LDFLAGS:= -L../lib -lfunction_list
CFLAGS:=-Wall

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(BIN) $(OBJS) $(LDFLAGS) 

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(BIN) $(OBJS)
