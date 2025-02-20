CC=gcc
GCC_FLAGS= -c

LD=ld
all: pre objects


pre:
	rm -rf build
	mkdir build

objects: ./build/strong_object.o ./build/test_strong_object.o


./build/strong_object.o: ./src/object/strong_object.c
	$(CC) $(GCC_FLAGS) $< -o $@


./build/test_strong_object.o: ./test/object/test_object.c
	$(CC) $(GCC_FLAGS) $< -o $@



clean:
	rm -rf build