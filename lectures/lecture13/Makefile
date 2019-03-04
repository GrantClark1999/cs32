# Makefile

CXX=g++

main: main.o
	${CXX} -o main main.o

hello:
	${CXX} -o hello hello.cpp
	
forkIt: forkIt.o
	${CXX} -o forkIt -std=C++11 forkIt.o

forkExec: forkExec.o
	${CXX} -o forkExec -std=C++11 forkExec.o

clean:
	rm -f *.o main