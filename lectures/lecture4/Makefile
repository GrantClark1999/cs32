# Makefile

CXX=g++
DEPENDENCIES=main.o F1.o F2.o
# Note: F1.h and F2.h are NOT required, but can list them to make sure
# that the files exist.
main: ${DEPENDENCIES}
	${CXX} -o main -std=c++11 main.o ${DEPENDENCIES}

clean:
	rm -f *.o main
