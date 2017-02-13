
CXX=pgc++

CXX_FLAGS=-std=c++11 -ta=tesla:managed,lineinfo -fast -Minfo=accel
SOURCES=main.cc gaussian.cc noacc_gaussian.cc
OBJECTS=$(subst .cc,.o,${SOURCES})

all: main

main: ${OBJECTS}
	${CXX} ${CXX_FLAGS} -o main ${OBJECTS}

main.o: main.cc
	${CXX} ${CXX_FLAGS} -c main.cc

gaussian.o: gaussian.cc
  ${CXX} ${CXX_FLAGS} -c gaussian.cc

noacc_gaussian.o: noacc_gaussian.cc
  ${CXX} ${CXX_FLAGS} -c noacc_gaussian.cc

clean:
	rm ${OBJECTS}
