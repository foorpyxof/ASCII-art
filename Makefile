compile:
	@if ! test -d "./build/unlinked" ; then \
		mkdir -p ./build/unlinked; \
	fi
	@find . -type f \( -name "*.c" -o -name "*.cpp" \) -exec gcc -c {} \;
	@mv *.o ./build/unlinked/
	g++ ./build/unlinked/*.o -o ./build/ascii.o
