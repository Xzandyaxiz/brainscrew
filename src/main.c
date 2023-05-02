#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bf.h"

static void print_registers(Parser *parser) {
  int iter = 0;
  while(iter < parser->reg_size) {
    printf("%d\n", parser->reg_list[iter]);
    iter++;
  }
}

static int bf_parse(Parser *parser) {
  long iter = 0;
  char current_char;

  int loop_conditional, loop_start, loop_end;

  while(iter < strlen(parser->source)) {
    current_char = parser->source[iter];

    switch(current_char) {
      case '>':
        parser->reg_pointer ++;
        break;

      case '<':
        parser->reg_pointer --;
        break;

      case '+':
        parser->reg_list[parser->reg_pointer] ++;
        break;

      case '-':
        parser->reg_list[parser->reg_pointer] --;
        break;

      case '.':
        putchar(parser->reg_list[parser->reg_pointer]);
        break;

      case '[':
        loop_start = iter;
        loop_conditional = parser->reg_pointer;
        break;

      case ']':
        loop_end = iter;
        iter = loop_start;

        if (parser->reg_list[loop_conditional] == 0) {
          iter = loop_end;
        }
        break;
    }

    iter ++;
  }
}

int main(int argc, char **argv) 
{
  if (argc < 2) {
    printf("Insufficient arguments!\n");
    return EXIT_FAILURE;
  }

  char *source = Read(argv[1]);

  Parser *parser = calloc(1, sizeof(Parser));

  parser->source = source;
  parser->reg_pointer = 0;
  parser->reg_size = 1;
  parser->reg_list = calloc(100, sizeof(int));

  bf_parse(parser);

  free(source);

  free(parser->reg_list);
  free(parser);

  return 0;
}