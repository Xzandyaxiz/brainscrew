#include "bf.h"
#include <stdlib.h>
#include <stdio.h>

extern char *Read(char *path) 
{
  FILE *file = fopen(path, "r");
  
  if (file == NULL) {
    printf("Could not open file.\n");
    return NULL;
  }
  
  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  char *source = calloc(size, sizeof(char));

  fseek(file, 0, SEEK_SET);

  size_t iter = 0;
  while(iter < size) {
    *(source + iter) = fgetc(file);
    
    iter ++;
  }

  *(source + iter) = '\0';
  return source;
}