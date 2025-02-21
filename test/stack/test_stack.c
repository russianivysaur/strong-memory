#include "../test.h"
#include "../../src/stack/stack.h"
#include "../../lib/munit.h"

void test_stack() {
  int capacity = 10;
  Stack* stack = new_stack(10);
  munit_assert_ptr_not_null(stack);
}


void run_all_stack_tests(){
  test_stack();
}