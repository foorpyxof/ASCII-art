#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../fpxLIB/fpx_cpp-utils/fpx_cpp-utils.h"

extern "C" {
	#include "../fpxLIB/fpx_string/fpx_string.h"
}

enum class Filetype { Other, Bmp, Png, Jpeg};

class ImageReader {
	public:
		static Filetype GetFiletype(const char*);
    static unsigned int* GetMetaData(const char*, Filetype);
    static char* MakeAscii(const char*, Filetype);
	private:
		static char* pvt_RawHeaderData(const char*);
};

#endif /* IMAGEREADER_H */