//
// Created by bulbasaur on 20/2/25.
//

#pragma once
#include <stdbool.h>

// We support only signed 32 bit intergers, strings, characters, bools, arrays and vectors
// The arrays and vecotrs are pointer stores which can store pointers to any objects being passed to it
typedef enum {
   Integer,
   Char,
   Bool,
   Vector,
   String,
   Array,
} StrongObjectType;


typedef struct {
  StrongObjectType type;
  void* data;
} StrongObject;


typedef struct {
  size_t length;
  size_t capacity;
  void** elements;
} StrongVectorDescriptor;

StrongObject new_strong_integer(int data);
StrongObject new_strong_char(char data);
StrongObject new_strong_bool(bool data);
StrongObject add_element_to_vector(StrongObject vector,void* element);