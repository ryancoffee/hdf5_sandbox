CC=g++
SDIR=./src
IDIR=./include
ODIR=./objects
CFLAGS=-Wall -c -std=c++11 -D_USE_MATH_DEFINES -O3 
MPIDIR=/usr/include/x86_64-linux-gnu
MPICFLAGS=`pkg-config --cflags-only-I mpi`
MPILFLAGS=`pkg-config --cflags-only-L mpi`
MPIlFLAGS=`pkg-config --libs mpi`
LDFLAGS=-L/usr/local/lib -L/usr/local/lib /usr/local/lib/libhdf5_hl.a /usr/local/lib/libhdf5.a -lz -ldl -lm -Wl,-rpath -Wl,/usr/local/lib -ldl -lpthread -lrt
#LDFLAGS=-L/usr/local/lib $(MPILFLAGS) $(MPIlFLAGS) -lm -ldl -lpthread -lrt 
#LDFLAGS=-L/usr/local/lib -L/usr/local/hdf5/lib -lmpi -lm -ldl -lpthread -lrt 
#INCFLAGS=-I/usr/local/include -I$(IDIR) -I$(MPIIDIR) $(HDF5) $(MPIFLAGS)
INCFLAGS=-I/usr/local/include -I/opt/hdf5-1.14.0/src/H5FDsubfiling -I$(IDIR) 
_SRCS=testh5.cpp 
_HEADS=testh5.hpp 

#mpicc -I/opt/hdf5-1.14.0/src/H5FDsubfiling -L/usr/local/lib /usr/local/lib/libhdf5_hl.a /usr/local/lib/libhdf5.a -lz -ldl -lm -Wl,-rpath -Wl,/usr/local/lib


OBJECTS=$(patsubst %,$(ODIR)/%,$(_SRCS:.cpp=.o))
HEADERS=$(patsubst %,$(IDIR)/%,$(_HEADS))
SOURCES=$(patsubst %,$(SDIR)/%,$(_SRCS))
EXECUTABLE ?= testh5

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(HEADERS)
	$(CC) $(INCFLAGS) $(CFLAGS) -c $< -o $@ 

.PHONY: clean

clean:
	rm $(ODIR)/*.o $(EXECUTABLE)
