all: dictionary spellcheck
	g++ Dictionary.o Spellcheck.o -o out
dictionary: Dictionary.cpp
	g++ -c Dictionary.cpp
spellcheck: Spellcheck.cpp
	g++ -c Spellcheck.cpp
clean:
	rm Dictionary.o Spellcheck.o out
