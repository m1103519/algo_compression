OPTS = -Wall -O2
INCLUDES = -I ./include

all: clean compil/arithencode.o compil/arithdecode.o compil/arithmodel.o main.o
	@gcc $(OPTS) compil/*.o -o compil/arithmetic_compression
	@echo compilation OK
	@mv compil/arithmetic_compression bin/
	@echo generation OK

compil/arithencode.o: src/arithencode.c
	@gcc $(OPTS) $(INCLUDES) -c src/arithencode.c -o compil/arithencode.o

compil/arithdecode.o: src/arithdecode.c
	@gcc $(OPTS) $(INCLUDES) -c src/arithdecode.c -o compil/arithdecode.o

compil/arithmodel.o: src/arithmodel.c
	@gcc $(OPTS) $(INCLUDES) -c src/arithmodel.c -o compil/arithmodel.o

main.o: main.c
	@gcc $(OPTS) $(INCLUDES) -c main.c -o compil/main.o

clean:
	@rm -f compil/*.o
	@rm -f compil/arithmetic_compression
	@echo clean OK
