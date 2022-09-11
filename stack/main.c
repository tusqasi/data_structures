#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n = 10, size = 0, end = 0;
  int *stack = malloc(n * sizeof(int));
  if (!stack) {
    fprintf(stderr, "Memory allocation failed!\n");
    free(stack);
  }

  free(stack);
  return 0;
}
