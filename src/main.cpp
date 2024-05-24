#define MAX_DIMENSION 30

#include <iostream>
#include <filesystem>
#include <vector>

extern "C" {
	#include "../include/fpxLIB/fpx_string/fpx_string.h"
}
#include "../include/imagereader/imagereader.h"

char outbuffer[MAX_DIMENSION*MAX_DIMENSION + 31];
bool debug = 0;

/** 
 * Prints the current outputbuffer and
 * terminates the program with the given returncode.
 * Default code is 0.
 */
void end(int returnCode=0) {
	std::cout << outbuffer << std::endl;
  if (debug) std::cout << "Program exited with code " << returnCode << std::endl;
	exit(returnCode);
}

int main(int argc, char** argv) {
  // uint8_t filesPassed;
	std::vector<uint8_t> filenameIndices;
	uint16_t switches = 0;

	// Checking what command switches were passed
	for (int i=1; i<argc; i++) {
		if (*argv[i] == '-') {
			switches++;
			switch (argv[i][1]) {
				case 'd':
					debug = 1;
					std::cout << "Running " << argv[0] << " in debug mode!\n" << std::endl;
					break;
				default:
					sprintf(outbuffer, "Unknown command switch '%s' passed... aborting...\n\n", argv[i]);
					end(1);
			}
		} else {
			filenameIndices.push_back(i);
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
	} else if (filenameIndices.size() > 1) {
    sprintf(outbuffer, "Invalid argument count: requires a maximum of one input image file\n");
    end(1);
  }


  unsigned int* data = nullptr;
  const char* imageToDraw = fpx_substr_replace(argv[filenameIndices[0]], "~", getenv("HOME"));

  try {data = { ImageReader::GetMetaData(imageToDraw, ImageReader::GetFiletype(imageToDraw)) }; }
  catch (fpx::Exception exc) {
    std::cout << exc.Message() << std::endl;
  }

  for (int i=0; i<=(sizeof(data)/sizeof(data[0])); i++) {
    std::cout << "Data" << i+1 << ':' << data[i] << std::endl;
  }

  delete data;
  
	end();
}
