#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_DEFAULT_SIZE 4

typedef struct {
  void *elements;
  size_t elements_size;
  int logical_length;
  int allocated_length;
  void (*free_function)(void *);
} Stack;

void stack_new(Stack *stack, size_t elements_size, void (*free_function)(void *));
void stack_dispose(Stack *stack);

bool stack_empty(const Stack *stack);
int stack_size(const Stack *stack);

void stack_push(Stack *stack, void *element_address);
void stack_pop(Stack *stack, void *element_address);

#endif

