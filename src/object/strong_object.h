//
// Created by bulbasaur on 20/2/25.
//

#pragma once
#include <stdbool.h>

// We support only signed 32 bit intergers, strings, characters, bools, arrays and vectors
// The arrays and vecotrs are pointer stores which can store pointers to any objects being passed to it
typedef enum {
   integer,
   character,
   boolean,
   vector,
   string,
   array,
} strong_object_type;


typedef struct {
    strong_object_type type;
    void* data;
    size_t ref_count;
} strong_object;


typedef struct {
  size_t length;
  size_t capacity;
  void** elements;
} strong_vector_descriptor;

strong_object* new_strong_integer(int data);
strong_object* new_strong_char(char data);
strong_object* new_strong_bool(bool data);
strong_object* new_strong_string(char* data);
strong_object* new_strong_vector();
strong_object* new_strong_array(void* data,size_t len);
void* get_element(const strong_object* strong_array,size_t index);
void add_element_to_vector(const strong_object* vector,void* element);