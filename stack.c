#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "stack.h"

void stack_new(Stack *stack, size_t elements_size) {
  stack->elements = malloc(STACK_DEFAULT_SIZE * elements_size);

  stack->elements_size = elements_size;
  stack->logical_length = 0;
  stack->allocated_length = STACK_DEFAULT_SIZE;

  assert(stack->elements != NULL);
}

void stack_dispose(Stack *stack) {
  free(stack->elements);
}

BOOL stack_empty(const Stack *stack) {
  return stack->logical_length == 0;
}

int stack_size(const Stack *stack) {
  return stack->logical_length;
}

void *stack_address_for_item(Stack *stack, int index) {
  return (char *)stack->elements + (index * stack->elements_size);
}

void stack_push(Stack *stack, void *element_address) {
  stack->logical_length += 1;

  if (stack->logical_length == stack->allocated_length) {

    // Double content size
    int new_size = stack->allocated_length * stack->elements_size * 2;
    stack->elements = realloc(stack->elements, new_size);
    stack->allocated_length *= 2;
  }

  void *address = stack_address_for_item(stack, stack->logical_length);
  memcpy(address, element_address, stack->elements_size);
}

void stack_pop(Stack *stack, void *element_address) {

  if (stack->allocated_length / 2 >= stack->logical_length) {

    // Otherwise will keep shrinking
    if (stack->allocated_length > STACK_DEFAULT_SIZE) {
      int new_size = stack->allocated_length * stack->elements_size / 2;
      stack->elements = realloc(stack->elements, new_size);
      stack->allocated_length /= 2;
    }
  }

  void *address = stack_address_for_item(stack, stack->logical_length);
  memcpy(element_address, address, stack->elements_size);
  stack->logical_length -= 1;
}

