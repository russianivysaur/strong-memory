#include "../../lib/munit.h"
#include "../../src/object/strong_object.h"
#include "stdio.h"
#include "../test.h"
void test_object() {
    // a strong int
    const int c_int = 10;
    const strong_object* int_object = new_strong_integer(c_int);
    munit_assert_int(*(int*)(int_object->data),==,c_int);

    // a strong char
    const char c_char = 's';
    const strong_object* char_object = new_strong_char('s');
    munit_assert_char(c_char,=,*(char*)(char_object->data));

    // a strong string
    char* c_string = "Hello my name is stronger";
    const strong_object* string_object = new_strong_string(c_string);
    munit_assert_string_equal(c_string,(char*)(string_object->data));


    // a strong array
    // the array will contain a int,a string
    int element1 = 10;
    char* element2 = "I am element 2";
    void* pointer_array[2];
    pointer_array[0] = &element1;
    pointer_array[1] = element2;
    const strong_object* array_object = new_strong_array(pointer_array,2);
    void* element_ptr = get_element(array_object,1);
    munit_assert_ptr_not_null(element_ptr);
    munit_assert_string_equal(element2,(char*)element_ptr);
    element_ptr = get_element(array_object,0);
    munit_assert_ptr_not_null(element_ptr);
    munit_assert_int(element1,==,*(int*)element_ptr);

    // a strong vector
    const strong_object* vector_object = new_strong_vector();
    int a = 2000;
    add_element_to_vector(vector_object,&a);
    char c = 't';
    add_element_to_vector(vector_object,&c);
    char* string = "Ankit";
    add_element_to_vector(vector_object,string);
    munit_assert_int(a,==,*(int*)get_element(vector_object,0));
    munit_assert_char(c,==,*(char*)get_element(vector_object,1));
    munit_assert_string_equal(string,(char*)get_element(vector_object,2));
}

void run_all_object_tests() {
    test_object();
}