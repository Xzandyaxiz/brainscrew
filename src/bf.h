#ifndef read
  #define read

typedef struct {
  long reg_pointer, reg_size;
  int *reg_list;
  char *source;
} Parser;

char *Read(char *path);

#endif /*endif read*/