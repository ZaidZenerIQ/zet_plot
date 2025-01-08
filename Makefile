cc=g++
lib= -lfltk -lm
ext: example.cpp
	$(cc) $^ $(lib) -o $@
