IDIR =.
CC=g++
CFLAGS=-I$(IDIR) -std=c++14 

ODIR=.
LDIR =.

LIBS=-lpthread -latomic

_DEPS = lock_free_queue.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = spin_lock_version.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

spin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ spin 
