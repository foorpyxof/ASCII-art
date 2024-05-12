compile:
	@if ! test -d "./build/unlinked" ; then \
		mkdir -p ./build/unlinked; \
	fi
	find . -type f \( -name "*.c" \) -exec gcc -c {} \;
	find . -type f \( -name "*.cpp" \) -exec g++ -c {} \;
	mv *.o ./build/unlinked/
	g++ -I $(shell pwd) ./build/unlinked/*.o -o ./build/ascii.o
	# g++ *.o -o ./build/ascii.o
