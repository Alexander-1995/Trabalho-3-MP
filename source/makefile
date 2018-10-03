IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -g -fprofile-arcs -ftest-coverage

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = countlines.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_countlines.o countlines.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testa_countlines: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
