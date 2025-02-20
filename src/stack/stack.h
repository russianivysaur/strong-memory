#pragma once
#include "stdio.h"
typedef struct {
  size_t size;
  size_t capacity;
  void** data;
}Stack;

Stack* new_stack(size_t capacity);
void* pop(Stack* stack);
void push(Stack* stack,void* data);