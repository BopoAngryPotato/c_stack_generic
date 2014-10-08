#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_DEFAULT_SIZE 4

#ifndef THROW_ERROR

#define THROW_ERROR(E) { \
  fprintf(stderr, (E)); \
  exit(1); \
}

#endif

typedef void (*stack_free_function)(void *);

typedef struct stack_s {
  void *elements;
  size_t elements_size;
  int logical_length;
  int allocated_length;
  stack_free_function free_function;
} stack_s;

void stack_new(stack_s *stack, size_t elements_size, stack_free_function free_function);
void stack_free(stack_s *stack);

bool stack_empty(const stack_s *stack);
int stack_size(const stack_s *stack);

void stack_push(stack_s *stack, void *element_address);
void stack_pop(stack_s *stack, void *element_address);

#endif

