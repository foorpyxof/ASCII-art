#include "imagereader.h"

Filetype ImageReader::GetFiletype(const char* filepath) {
  char* fileHeader = pvt_RawHeaderData(filepath);
  char* lowercaseFileHeader = fpx_string_to_lower(fileHeader);
  std::cout << lowercaseFileHeader << std::endl;

  if (fpx_substringindex(lowercaseFileHeader, "png") > -1) {
    free(fileHeader);
    free(lowercaseFileHeader);
    return Filetype::Png;
  } else if (fpx_substringindex(fileHeader, "\xFF\xD8") == 0) {
    free(fileHeader);
    free(lowercaseFileHeader);
    return Filetype::Jpeg;
  } else if (fpx_substringindex(fileHeader, "\x42\x4D") == 0) {
    free(fileHeader);
    free(lowercaseFileHeader);
    return Filetype::Bmp;
  }
  free(fileHeader);
  free(lowercaseFileHeader);
	return Filetype::Other;
}

char* ImageReader::MakeAscii(const char* filepath, Filetype fType) {
  // char readBuf[10];
  GetMetaData(filepath, fType);
  switch (fType) {
    case Filetype::Png:
      std::cout << "PNG found" << std::endl;
      break;
    case Filetype::Jpeg:
      std::cout << "JPEG found" << std::endl;
      break;
    case Filetype::Bmp:
      std::cout << "BMP found" << std::endl;
      break;
    default:
      std::cout << "Not recognized" << std::endl;
      break;
  }
}

char* ImageReader::pvt_RawHeaderData(const char* filepath) {
  int length = 16;
  char readBuf[length+1];

  for (char& character : readBuf) {
    character = '\0';
  }

  std::ifstream(filepath).read(readBuf, length);

  char* returnArray = new char[length+1];
  for (int i=0; i<length; i++) returnArray[i] = readBuf[i];
  returnArray[length] = '\0';

  return returnArray;
}

unsigned int* ImageReader::GetMetaData(const char* filepath, Filetype fType) {
  unsigned int* data = new unsigned int[3];
  
  // throw fpx::NotImplementedException();

  // Returns integer array
  switch (fType) {
    case Filetype::Bmp:
      /**
       * index 0: width in pixels
       * index 1: height in pixels
       * index 2: bits per pixel
      */
      char readBuf[54];
      std::ifstream(filepath).read(readBuf, 54);

      // data[0] = (unsigned int)readBuf[2];
      data[0] = (unsigned int)readBuf[18];
      data[1] = (unsigned int)readBuf[22];
      data[2] = (unsigned short)readBuf[28];
      break;

    default:
      throw new fpx::NotImplementedException("This filetype is not supported.");
      break;
  }

  return data;
}