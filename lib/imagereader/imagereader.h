#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <fstream>
#include <cstdlib>
#include <iostream>

extern "C" {
	#include "../fpx_string/fpx_string.h"
}

enum class Filetype { Other, Bmp, Png, Jpeg};

class ImageReader {
	public:
		static Filetype GetFiletype(const char*);
	private:
		static char* pvt_HeaderData(const char*);
};

#endif
