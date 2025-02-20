#include <stdlib.h>
#include "stdbool.h"
#include "stddef.h"
#include "stdio.h"
#include "strong_object.h"


StrongObject new_strong_integer(int data) {
   int* d = (int*)malloc(sizeof(int));
   *d = data;
   StrongObject object = {.type=Integer,.data=d};
   return object;
}

StrongObject new_strong_char(char data){
  char* c = (char*)malloc(sizeof(char));
  *c = data;
  StrongObject object = {.type=Char,.data=c};
  return object;
}


StrongObject new_strong_array(void* data,size_t len) {
  StrongVectorDescriptor descriptor = {.elements=data,.length=len,.capacity=len};
  StrongVectorDescriptor* descriptor_ptr = (StrongVectorDescriptor*)malloc(sizeof(StrongVectorDescriptor));
  *descriptor_ptr = descriptor;
  StrongObject object = {.type=Array,.data=descriptor_ptr};
  return object;
}

void* get_element(StrongObject strong_array,size_t index) {
   if (strong_array.type!=Array && strong_array.type!=Vector) {
      printf("%s","Not a strong array or a vector\n");
      return NULL;
   }
   StrongVectorDescriptor* descriptor_ptr = ((StrongVectorDescriptor*)strong_array.data);
   if (descriptor_ptr->length <= index) {
      printf("%s","array index out of bounds mate\n");
      return NULL;
   }
   return descriptor_ptr->elements[index];
}

StrongObject new_strong_bool(bool data){
   bool* d = (bool*)malloc(sizeof(bool));
   *d = data;
   StrongObject object = {.type=Bool,.data=d};
   return object;
}




//a vector will have ability to grow with time
StrongObject new_strong_vector(){
  void* data = (void*)malloc(sizeof(void*));
  StrongVectorDescriptor descriptor = {.elements=data,.length=0,.capacity=1};
  StrongVectorDescriptor* descriptor_ptr = (StrongVectorDescriptor*)malloc(sizeof(descriptor));
  *descriptor_ptr = descriptor;
  StrongObject object = {.data=descriptor_ptr,.type=Vector};
  return object;
}

StrongObject add_element_to_vector(StrongObject vector,void* element){
   if(vector.type!=Vector){
      printf("expected vector, got %d\n",vector.type);
      exit(-1);
   }
   StrongVectorDescriptor* descriptor = (StrongVectorDescriptor*)vector.data;
   size_t length = descriptor->length;
   size_t capacity = descriptor->capacity;
   if(length<capacity){
       // we have space hehe
       descriptor->elements[length] = element;
       descriptor->length++;
       return vector;
   }
   if(length>capacity){
       printf("length should always be less than capacity\n");
       exit(-1);
   }

   //don't have space as length == capacity
   //realloc
   void* data = (void*)realloc(descriptor->elements,sizeof(descriptor->elements)*2);
   descriptor->elements = data;
   return vector;
}


StrongObject new_strong_string(char* data) {
   StrongObject object = {.type=String,.data=data};
   return object;
}