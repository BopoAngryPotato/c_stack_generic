#include <stdio.h>
#include "stack.h"

int main(int argc, const char *argv[])
{
  stack_s stack;

  stack_new(&stack, sizeof(int), NULL);

  for (int i = 0; i < 24; i++) {
    stack_push(&stack, &i);
    printf("Pushing: %i\n", i);
  }

  int result;

  while(!stack_empty(&stack)) {
    stack_pop(&stack, &result);
    printf("Popping: %i\n", result);
  }

  stack_free(&stack);

  return 0;
}
