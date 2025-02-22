#include <stdlib.h>
#include "stdbool.h"
#include "stdio.h"
#include "strong_object.h"


strong_object* new_strong_integer(const int data) {
   int* d = (int*)malloc(sizeof(int));
   *d = data;
   const strong_object object = {.type=integer,.data=d};
   strong_object* object_ptr = (strong_object*)malloc(sizeof(strong_object));
   *object_ptr = object;
   return object_ptr;
}

strong_object* new_strong_char(const char data){
   char* c = (char*)malloc(sizeof(char));
   *c = data;
   const strong_object object = {.type=character,.data=c};
   strong_object* object_ptr = (strong_object*)malloc(sizeof(strong_object));
   *object_ptr = object;
   return object_ptr;
}


strong_object* new_strong_array(void* data, const size_t len) {
  const strong_vector_descriptor descriptor = {.elements=data,.length=len,.capacity=len};
  strong_vector_descriptor* descriptor_ptr = (strong_vector_descriptor*)malloc(sizeof(strong_vector_descriptor));
  *descriptor_ptr = descriptor;
  const strong_object object = {.type=array,.data=descriptor_ptr};
  strong_object* object_ptr = (strong_object*)malloc(sizeof(strong_object));
   *object_ptr = object;
   return object_ptr;
}

void* get_element(const strong_object* strong_array, const size_t index) {
   if (strong_array->type!=array && strong_array->type!=vector) {
      printf("%s","Not a strong array or a vector\n");
      return NULL;
   }
   strong_vector_descriptor* descriptor_ptr = ((strong_vector_descriptor*)strong_array->data);
   if (descriptor_ptr->length <= index) {
      printf("%s","array index out of bounds mate\n");
      return NULL;
   }
   return descriptor_ptr->elements[index];
}

strong_object* new_strong_bool(const bool data){
   bool* d = (bool*)malloc(sizeof(bool));
   *d = data;
   const strong_object object = {.type=boolean,.data=d};
   strong_object* object_ptr = (strong_object*)malloc(sizeof(strong_object));
   *object_ptr = object;
   return object_ptr;
}




//a vector will have ability to grow with time
strong_object* new_strong_vector(){
  void* data = (void*)malloc(sizeof(void*));
  strong_vector_descriptor descriptor = {.elements=data,.length=0,.capacity=1};
  strong_vector_descriptor* descriptor_ptr = (strong_vector_descriptor*)malloc(sizeof(descriptor));
  *descriptor_ptr = descriptor;
  const strong_object object = {.data=descriptor_ptr,.type=vector};
   strong_object* object_ptr = (strong_object*)malloc(sizeof(strong_object));
   *object_ptr = object;
   return object_ptr;
}

void add_element_to_vector(const strong_object* vector_object,void* element){
   if(vector_object->type!=vector){
      printf("expected vector, got %d\n",vector_object->type);
      exit(-1);
   }
   strong_vector_descriptor* descriptor = (strong_vector_descriptor*)vector_object->data;
   const size_t length = descriptor->length;
   const size_t capacity = descriptor->capacity;
   if(length<capacity){
       // we have space hehe
      descriptor->elements[length] = element;
      descriptor->length++;
      return;
   }
   if(length>capacity){
       printf("length should always be less than capacity\n");
       exit(-1);
   }

   //don't have space as length == capacity
   //reallo
   void* data = (void*)realloc(descriptor->elements,sizeof(void*)*descriptor->capacity*2);
   descriptor->elements = data;
   descriptor->capacity *= 2;
   descriptor->elements[length] = element;
   descriptor->length++;
}


strong_object* new_strong_string(char* data) {
   const strong_object object = {.type=string,.data=data};
   strong_object* object_ptr = (strong_object*)malloc(sizeof(strong_object));
   *object_ptr = object;
   return object_ptr;
}