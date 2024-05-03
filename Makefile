compile:
	@if ! test -d "./build" ; then \
		mkdir ./build; \
	fi
	g++ *.cpp -o ./build/ascii.o
