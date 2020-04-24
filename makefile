CC=gcc
CFLAGS=-g -Wall $(shell sdl2-config --cflags)
LDFLAGS=-export-dynamic $(shell sdl2-config --libs)
EXEC=main

all:$(EXEC)

main:main.o game1.o editer.o fonction.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

main.o:main.c constante.h game1.h editer.h fonction.h
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

game1.o:game1.c fonction.o editer.o constante.h
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

fonction.o:fonction.c editer.o constante.h
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

editer.o:editer.c constante.h
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

#$@ cible
#$< name of the first dependency
#$^ list of dep
