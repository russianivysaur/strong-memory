#include "test.h"
#include "stdio.h"
int main(){
  run_all_object_tests();
  run_all_stack_tests();
  printf("All tests OK\n");
  return 0;
}