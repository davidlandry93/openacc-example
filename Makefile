
CXX=pgc++
CXXFLAGS=-std=c++11 -ta=tesla:cuda8.0 -fast
CXXFLAGS_LOOP=-Minfo=all,accel,intensity

OBJECTS=main.o gaussian.o noacc_gaussian.o

all: main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $(OBJECTS)

gaussian.o: gaussian.h point.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_LOOP) -c gaussian.cc

# Implicit rules.
main.o: gaussian.h noacc_gaussian.h point.h
noacc_gaussian.o: noacc_gaussian.h gaussian.h point.h

.PHONY: clean
clean:
	rm main $(OBJECTS)
