#include "imagereader.h"

Filetype ImageReader::GetFiletype(const char* filepath) {
  const char* filepathLowercase = string_to_lower(pvt_HeaderData(filepath));

  if (substringindex(filepathLowercase, "png") > -1) {
    std::cout << "PNG found";
    return Filetype::Png;
  } else if (substringindex(filepathLowercase, "\xFF\xD8") == 0) {
    std::cout << "JPEG found";
    return Filetype::Jpeg;
  }
  std::cout << "Not recognized";
	return Filetype::Other;
}

char* ImageReader::pvt_HeaderData(const char* filepath) {
  char readBuf[20];
  for (char& character : readBuf) {
    character = '\0';
  }

  std::ifstream(filepath).read(readBuf, 19);

  char* charArray = new char;
  return charArray;
}
