CPP_COMPILER = clang++
CFLAGS = -g -Wall
CPP_VERSION=c++17
ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all

.PHONY: all bin runMe clean valgrind

all: bin bin/main.exe

bin:
	mkdir -p bin

bin/main.exe: bin src/*.cpp include/*.h
	${CPP_COMPILER} ${CFLAGS} -std=${CPP_VERSION} -o bin/main.exe src/*.cpp -Iinclude

bin/main.o: src/main.cpp include/template.h
	${CPP_COMPILER} ${CFLAGS} -std=${CPP_VERSION} -o bin/main.o -c src/main.cpp

# bin/Rational.o:  src/Rational.cpp include/Rational.h
# 	${CPP_COMPILER} ${CFLAGS} -std=${CPP_VERSION} -o bin/Rational.o -c src/Rational.cpp

runMe: bin/main.exe
	bin/main.exe

clean:
	rm -rf bin/main.exe  bin/*.o bin/main.dSYM bin/*.pdf

valgrind:
		valgrind ${VALGRIND_FLAGS} bin/main.exe