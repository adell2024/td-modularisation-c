CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99
LDFLAGS =

OBJETS = symboles.o \
         nouveau_symbole.o \
         generateur.o \
         pluriel.o \
         formater.o \
         exit_if.o \
         erreurs.o

EXE = symboles

$(EXE): $(OBJETS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXE)

.PHONY: clean
