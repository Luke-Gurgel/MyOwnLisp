// https://stackoverflow.com/a/64914811
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// Fake readline function
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

// Fake add_history function
void add_history(char* unused) {}

#else
#include <editline.h>
#endif

int main(int argc, char** argv) {
  // print version and exit info
  puts("Lispy version 0.0.1");
  puts("Press ctrl + c to exit\n");

  // start repl loop
  while (1) {
    char* input = readline("lispy >>> ");
    add_history(input);
    printf("%s\n", input);
    free(input);
  }

  return 0;
}