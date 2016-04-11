CC=g++
FLAGS=-std=c++11 -Wall -Wextra -pthread -Wvla
PARALLEL_FLAGS=${FLAGS} -O -DNDEBUG
MATRIX=Matrix.hpp  
EXCEPTIONS=MultiplyEx.h AddDimsEx.h NotMatchingVectorSizeEx.h NotSquareMatrixEx.h SubDimsEx.h OndDimZeroEx.h

Matrix: ${EXCEPTIONS}
	${CC} ${FLAGS} ${MATRIX}

GenericMatrixDriver: ${MATRIX} ${EXCEPTIONS} Complex.h Complex.cpp GenericMatrixDriver.cpp
	${CC} ${FLAGS} $^ -o $@

ParallelChecker: ParallelChecker.cpp Complex.cpp ${MATRIX} ${EXCEPTIONS}
	${CC} ${PARALLEL_FLAGS} $^ -o $@

tar:
	tar cfv ex3.tar ${MATRIX} ${EXCEPTIONS} Makefile README

clean:
	rm -f *.o ParallelChecker GenericMatrixDriver Matrix.hpp.gch

.PHONY: clean tar
