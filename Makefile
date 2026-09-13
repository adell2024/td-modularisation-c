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

OBJETS_TESTS = tests/tests.o \
               nouveau_symbole.o \
               generateur.o \
               pluriel.o \
               formater.o \
               exit_if.o \
               erreurs.o

EXE   = symboles
TESTS = tests/tests

all: $(EXE)

$(EXE): $(OBJETS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TESTS): $(OBJETS_TESTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

check: $(TESTS)
	./$(TESTS)

clean:
	rm -f *.o $(EXE) tests/*.o $(TESTS)

.PHONY: all clean check
