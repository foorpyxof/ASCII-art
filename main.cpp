#include <iostream>
#include <fstream>
#include "lib/imagereader.h"

#define MAX_DIMENSION 30

int main() {
	std::cout << "Hello, World!" << (char)10;
	if (Filetype::Other == ImageReader::GetFiletype("hi")) {
		std::cout << "hi\n";
	} else {
		std::cout << "lo\n";
	}
}
