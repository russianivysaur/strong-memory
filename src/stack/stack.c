#include "stack.h"
#include "stdlib.h"

//you basic push pointers onto the stack

Stack* new_stack(size_t capacity) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->size = 0;
  stack->data = (void*)malloc(sizeof(void*)*capacity);
  return stack;
}

void push(Stack* stack,void* data) {
  if(stack->size == stack->capacity) {
    //resize
    stack->data = (void*)realloc(stack->data,sizeof(void*)*stack->capacity*2);
    if (stack->data == NULL ) {
      printf("realloc failed for stack\n");
      exit(0);
      return;
    }
    stack->capacity *= 2;
  }
  stack->data[stack->size] = data;
  stack->size++;
}

void* pop(Stack* stack) {
  if(stack->size == 0) return NULL;
  stack->size--;
  return stack->data[stack->size];
}