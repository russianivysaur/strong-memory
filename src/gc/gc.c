#include "../object/strong_object.h"
#include "stdlib.h"

void free_object(strong_object*);

//reference count collector
void ref_count_inc(strong_object* object){
  object->ref_count++;
}


void ref_count_dec(strong_object* object){
  if(object == NULL) return;
  object->ref_count--;
  if(object->ref_count <= 0){
    free_object(object);
  }
}

void free_object(strong_object* object) {
  switch(object->type){
    case integer:
    case boolean:
    case string:
    case character:
      free(object->data);
      free(object);
      break;
    case array:
    case vector:
      strong_vector_descriptor* descriptor_ptr = (strong_vector_descriptor*)object->data;
      free(descriptor_ptr->elements);
      free(descriptor_ptr);
      free(object);
      break;
  }
}



// mark and sweep
