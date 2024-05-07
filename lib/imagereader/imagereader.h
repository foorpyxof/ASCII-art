#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <fstream>
#include <cstddef>

enum class Filetype { Other, Bmp, Png, Jpeg };

class ImageReader {
	public:
		static Filetype GetFiletype(const char*);
	private:
		static std::byte* pvt_HeaderData(const char*);
};

#endif
