#include "fpx_string.h"

int getstringlength(const char* stringToCheck) {
	int i=0;
	const char* current = stringToCheck;
	while (*current != '\0')
	{
    i++;
    current++;
	}
  
  return i;
}

int substringexists(const char* haystack, const char* needle) {
  const char* needleStart = needle;

	for (int i=0; i<getstringlength(haystack); i++) {
    if (*haystack == *needle) {
      needle++;
    } else if (*haystack == *needleStart) {
      needle = needleStart+1;
    } else {
      needle = needleStart;
    }
    haystack++;
  }
  if (getstringlength(needleStart) != needle-needleStart) {
    return 0;
  }
  return 1;
}
