#define MAX_DIMENSION 30

#include <iostream>
#include <filesystem>

extern "C" {
	#include "../lib/fpx_string/fpx_string.h"
}
#include "../lib/imagereader/imagereader.h"

char outbuffer[MAX_DIMENSION*MAX_DIMENSION + 31];
bool debug = 0;

/** 
 * Prints the current outputbuffer and
 * terminates the program with the given returncode.
 * Default code is 0.
 */
void end(int returnCode=0) {
	std::cout << outbuffer;
	exit(returnCode);
}

int main(int argc, char** argv) {
	uint8_t filenameIndex = 0;
	uint16_t switches = 0;

	// Checking what command switches were passed
	for (int i=1; i<argc; i++) {
		if (*argv[i] == '-') {
			switches++;
			switch (argv[i][1]) {
				case 'd':
					debug = 1;
					std::cout << "Running " << argv[0] << " in debug mode!\n\n";
					break;
				default:
					sprintf(outbuffer, "Unknown command switch '%s' passed... aborting...\n\n", argv[i]);
					end(1);
			}
		} else {
			filenameIndex = i;
		}
	}

	// debug messages
	if (debug) {
		std::cout << "DEBUG - Command line switches passed: " << switches << std::endl;
		std::cout << "DEBUG - Current working directory: " << std::filesystem::current_path() << std::endl;
		std::cout << std::endl;
	}

	if (switches == argc-1) {
		sprintf(outbuffer, "No filename passed... aborting...\n\n");
		end(1);
	}

	if (argc < 2) {
		sprintf(outbuffer, "Invalid argument count: requires input image file\n");
		end(1);
	}

	ImageReader::GetFiletype(substr_replace(argv[filenameIndex], "~", getenv("HOME")));

	end();
}
