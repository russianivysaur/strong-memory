//
// Created by bulbasaur on 20/2/25.
//

#include "./object/strong_object.h"
#include "./gc/gc.h"
#include "./stack/stack.h"
#include "stdio.h"

int main(){
  printf("%s","Welcome to strong VM\n");

  // a strong int
  StrongObject int_object = new_strong_integer(10);
  printf("%d\n",*(int*)(int_object.data));

  //a strong bool
  StrongObject bool_object = new_strong_bool(false);
  printf("%b\n",*(bool*)(bool_object.data));

  // a strong char
  StrongObject char_object = new_strong_char('s');
  printf("%c\n",*(char*)(char_object.data));

  // a strong string
  StrongObject string_object = new_strong_string("Hello my name is stronger");
  printf("%s\n",(char*)(string_object.data));

  // a strong array
  // the array will contain a int,a string
  int element1 = 10;
  char* element2 = "I am element 2";
  void* pointer_array[2];
  pointer_array[0] = &element1;
  pointer_array[1] = &element2;
  StrongObject array_object = new_strong_array(pointer_array,2);
  void* element_ptr = get_array_element(array_object,2);
  printf("%s\n",(char*)element_ptr);
  element_ptr = get_array_element(array_object,0);
  printf("%d\n",*(int*)element_ptr);

  return 0;
}
