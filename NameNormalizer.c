#include "NameNormalizer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned int SplitOnSpace(char* string, char** tokens) {
  tokens[0] = strtok(string, " ");
  unsigned int count = 0;
  while (tokens[count] != NULL)
    tokens[++count] = strtok(NULL, " ");
  return count;
}

char* AllocChar(unsigned int length) {
   return (char*)malloc(length * sizeof(char*));
}

char* Format(char* lastName, char* firstName, char* middleInitials) {
  char* output;
  asprintf(&output, "%s, %s%s", lastName, firstName, middleInitials);
  return output;
}

char* First(char* nameParts[]) {
  return nameParts[0];
}

char* Last(char* nameParts[], int size) {
  return nameParts[size - 1];
}

char* MiddleInitial(char* name) {
   bool isSingleLetterMiddleName = strlen(name) == 1;
   char* middleInitial;
   asprintf(&middleInitial, " %c%s", name[0], isSingleLetterMiddleName ? "" : ".");
   return middleInitial;
}

char* MiddleInitials(char* nameParts[], int partsCount) {
   char* all = AllocChar(3 * (partsCount - 2));
   for (int i = 1; i < partsCount - 1; i++)
      strcat(all, MiddleInitial(nameParts[i]));
   return all;
}

unsigned int CountSpaces(const char* str) {
  unsigned int count = 0;
  for (int i = 0; str[i]; i++)
    count += str[i] == ' ';
  return count;
}

char* NameNormalizer_Convert(const char* fullName) {
  if (strlen(fullName) == 0) return (char*)"";

  char* nameParts[CountSpaces(fullName)]; // overallocates for untrimmed strings
  int partsCount = SplitOnSpace(strdup(fullName), nameParts);
  if (partsCount == 1) return First(nameParts);

  return Format(Last(nameParts, partsCount), First(nameParts), MiddleInitials(nameParts, partsCount));
}
