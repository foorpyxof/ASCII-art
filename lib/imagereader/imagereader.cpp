#include "imagereader.h"

Filetype ImageReader::GetFiletype(const char* filepath) {
	return Filetype::Other;
}

std::byte* ImageReader::pvt_HeaderData(const char* filepath) {
  return (std::byte*)(std::byte)0xff;
}
