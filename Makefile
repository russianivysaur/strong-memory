CC=gcc
GCC_FLAGS= -c
LD=ld
LINK_FILES= /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o
DL_FILE=/lib64/ld-linux-x86-64.so.2
TEST_OBJECT_FILES=./build/test/test.o ./build/test/test_object.o ./build/test/test_stack.o ./build/test/munit.o
SYSTEM_FILES=./build/strong_object.o ./build/stack.o

all: pre ./build/strong.bin

pre:
	rm -rf build
	mkdir build


./build/strong.bin:  ./build/main.o $(SYSTEM_FILES)
	$(LD) -o $@ $(LINK_FILES) $^ -lc -dynamic-linker $(DL_FILE)



./build/strong_object.o: ./src/object/strong_object.c
	$(CC) $(GCC_FLAGS) $< -o $@


./build/stack.o: ./src/stack/stack.c
	$(CC) $(GCC_FLAGS) $< -o $@

./build/main.o: ./src/main.c
	$(CC) -c $< -o $@

clean:
	rm -rf build


test_pre:
	rm -rf build
	mkdir build
	mkdir build/test

test: test_pre ./build/test.bin
	./build/test.bin

./build/test.bin: $(TEST_OBJECT_FILES) $(SYSTEM_FILES)
	$(LD) -o $@ $(LINK_FILES) $^ -lc -dynamic-linker $(DL_FILE)


./build/test/test.o: ./test/test.c
	$(CC) -c $< -o $@

./build/test/test_object.o: ./test/object/test_object.c
	$(CC) -c $< -o $@


./build/test/test_stack.o: ./test/stack/test_stack.c
	$(CC) -c $< -o $@

./build/test/munit.o: ./lib/munit.c
	$(CC) -c $< -o $@