#include "../test.h"
#include "../../src/stack/stack.h"
#include "../../lib/munit.h"
#include "stdio.h"

void test_stack() {
  int capacity = 2;
  Stack* stack = new_stack(capacity);
  munit_assert_ptr_null(pop(stack));
  munit_assert_ptr_not_null(stack);
  munit_assert_int(stack->capacity,==,capacity);
  int test_number = 20;
  push(stack,&test_number);
  munit_assert_int(*(int*)pop(stack),==,test_number);
  push(stack,&test_number);
  push(stack,&test_number);
  push(stack,&test_number);
  munit_assert_int(stack->size,==,3);
  munit_assert_int(stack->capacity,==,4);
}


void run_all_stack_tests(){
  test_stack();
}