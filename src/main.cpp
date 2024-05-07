#include <iostream>
#include <filesystem>

#include "../lib/fpx_string/fpx_string.h"
#include "../lib/imagereader/imagereader.h"

#define MAX_DIMENSION 30
#define DEBUGGING 1

char outbuffer[MAX_DIMENSION*MAX_DIMENSION + 31];

/** Prints the current outputbuffer and
 *  terminates the program with the given returncode.
 *  Default code is 0.
 */
void end(int returnCode=0) {
	std::cout << outbuffer;
	exit(returnCode);
}

int main(int argc, char** argv) {
	if (DEBUGGING) std::cout << std::filesystem::current_path() << std::endl;
	if (argc < 2) {
		sprintf(outbuffer, "Invalid argument count: requires input image file\n");
		end(1);
	}
	std::cout << "Hello, World!" << std::endl;
	if (Filetype::Other == ImageReader::GetFiletype("hi")) {
		std::cout << "hi" << std::endl;
	} else {
		std::cout << "lo" << std::endl;
	}

  std::cout << getstringlength("heyy") << substringexists("hilloo", "il");

	end();
}
