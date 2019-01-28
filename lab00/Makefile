# Makefile for lab00, Grant Clark, CS32, W19

CXX=clang++ # CXX is a special variable name denoting which compiler to use.
# CXX=g++

lab00Test: lab00Test.o tddFuncs.o arrayFuncs.o
	${CXX} lab00Test.o tddFuncs.o arrayFuncs.o -o lab00Test

helloWorld: helloWorld.o # Target: helloWorld; Dependencies: helloWorld.o
	${CXX} helloWorld.o -o helloWorld

# helloWorld.o NOT NEEDED since this is the default implementation defined in
# Make already.
helloWorld.o: helloWorld.cpp
	${CXX} -c helloWorld.cpp

clean: # No dependencies
	/bin/rm -f *.o helloWorld lab00Test

# Examples of when "clean" might be necessary
#	- Switching between two compilers (clang++ and g++). The .o files
#	produced by on compiler are not compatible with the other.
#	- After making significant changes to the interface (.h files) between
#	multiple parts of a program that uses separate compilation.
#	- If we are about to copy the files to another directory, or if we are
#	finished with a project and want to save disk space.

# Note: "make clean" almost always runs the clean rule unless there is a file
# that has the exact same name as the rule in the file.

# Clean
#	"/bin/rm" specifies what version of the rm program to use.
#	"-f" stands for "force" and to "do this even if there is a problem".
