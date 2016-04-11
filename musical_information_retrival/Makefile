CC=g++

CFLAGS= -std=c++11 -Wall -Wextra -g

PROGSRC= Song.cpp Parameters.cpp Parser.cpp MIR.cpp LyricalSong.cpp InstrumentalSong.cpp SortHelper.cpp
PROGHDS= Song.h Parameters.h Parser.h LyricalSong.h InstrumentalSong.h SortHelper.h

TAR=tar
TARFLAGS=-cvf
TARNAME=ex2.tar
TARSRC= $(PROGSRC) $(PROGHDS) Makefile README

MIR: MIR.o Song.o Parameters.o Parser.o LyricalSong.o InstrumentalSong.o SortHelper.o
	$(CC) $(CFLAGS) $^ -o $@
	
MIR.o: MIR.cpp
	$(CC) $(CFLAGS) -c $<
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<
tar:
	$(TAR) $(TARFLAGS) $(TARNAME) $(TARSRC)
clean:
	rm -f *.o MIR $(TARNAME)

.PHONY: all tar clean MIR
