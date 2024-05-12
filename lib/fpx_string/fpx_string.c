#include "fpx_string.h"

int getstringlength(const char* stringToCheck) {
  /**
   * Returns the length from the start of the string
   * until the first occurence of a null-byte (\0).
  */

	int i=0;
	const char* current = stringToCheck;
	while (*current != '\0')
	{
    i++;
    current++;
	}
  
  return i;
}

int substringindex(const char* haystack, const char* needle) {
  /**
   * Will find the *first* occurence of a given substring
   * "needle" in the string "haystack".
   * 
   * If not found, returns -1.
  */

  const int haystackLen = getstringlength(haystack);
  const int needleLen = getstringlength(needle);
  const char* needleStart = needle;
  
  int foundSubstringIndex = 0;

	for (int i=0; i<haystackLen; i++) {
    if (*haystack == *needle) {
      needle++;
      if (*haystack == *needleStart && !(*(haystack-1) == *needleStart)) {
        foundSubstringIndex = i;
      }
    } else if (*haystack == *needleStart) {
      needle = needleStart+1;
    }else {
      needle = needleStart;
    }
    haystack++;
    if (needle-needleStart == needleLen) {
      return foundSubstringIndex;
    }
  }
  
  return -1;
}

const char* substr_replace(const char* haystack, const char* needle, const char* replacement) {
  /**
   * Replaces the *first* occurence of the given "needle" string
   * within the "haystack" string with the given replacement string.
   * 
   * Returns original haystack string if substring was not found.
  */

  const int needleLen = getstringlength(needle);
  const int replacementLen = getstringlength(replacement);
  const int haystackStartIndex = substringindex(haystack, needle);
  const int returnedHaystackLen = getstringlength(haystack) + getstringlength(replacement) - getstringlength(needle);

  // allocate string to return on the heap
  char* returnedHaystack = (char*)malloc(returnedHaystackLen + 1);

  // if haystack doesn't contain needle, return haystack back to the caller
  if (haystackStartIndex < 0) return haystack;

  /*
   * perform magic
   * (fill new string allocated earlier that contains the desired result)
   */ 
  for (int i=0; i<returnedHaystackLen+1; i++) {
    if (i < haystackStartIndex) {
      returnedHaystack[i] = haystack[i];
    } else if (i >= haystackStartIndex + getstringlength(replacement)) {
      returnedHaystack[i] = haystack[i + needleLen - replacementLen];
    } else {
      returnedHaystack[i] = replacement[i - haystackStartIndex];
    }
  }

  /*
   *  add null-byte (\0) to the end of the char array, to denote the end of the string
   * (this null-byte was accounted for when allocating memory for the result string)
   */
  returnedHaystack[returnedHaystackLen] = '\0';
  return returnedHaystack;
}

const char* string_to_lower(const char* input) {
  const int inputLength = getstringlength(input);
  // printf("%d", inputLength);
  char* inputCopy = (char*)malloc(inputLength + 1);

  for(int i=0; i<inputLength; i++) {
    inputCopy[i] = (input[i] >= 65 && input[i] <= 90) ? (input[i] + 32) : input[i];
  }

  inputCopy[inputLength] = '\0';
  return inputCopy;
}