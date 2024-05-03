#ifndef IMAGEREADER_H
#define IMAGEREADER_H

enum class Filetype { Other, Bmp, Png, Jpeg };

class ImageReader {
	public:
		static Filetype GetFiletype(const char*);
};

#endif
