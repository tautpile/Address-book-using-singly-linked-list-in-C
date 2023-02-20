.PHONY: all clean bin lib

all: lib bin

lib: 
	$(MAKE) -C ./lib

bin:
	$(MAKE) -C ./src

clean:
	$(MAKE) -C ./src clean
	$(MAKE) -C ./lib clean

