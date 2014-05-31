#ifndef STACK_H
#define STACK_H

#define STACK_DEFAULT_SIZE 4

#define BOOL int

typedef struct {
  void *elements;
  size_t elements_size;
  int logical_length;
  int allocated_length;
} Stack;

void stack_new(Stack *stack, size_t elements_size);
void stack_dispose(Stack *stack);

BOOL stack_empty(const Stack *stack);

void stack_push(Stack *stack, void *element_address);
void stack_pop(Stack *stack, void *element_address);

#endif

