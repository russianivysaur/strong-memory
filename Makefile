CC=gcc
GCC_FLAGS= -c
LD=ld

LD=ld
all: pre ./build/strong.bin

pre:
	rm -rf build
	mkdir build


./build/strong.bin: ./build/strong_object.o ./build/main.o
	$(LD) -o  $@ /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o $^ -lc /usr/lib/x86_64-linux-gnu/crtn.o -dynamic-linker /lib64/ld-linux-x86-64.so.2



./build/strong_object.o: ./src/object/strong_object.c
	$(CC) $(GCC_FLAGS) $< -o $@



./build/main.o: ./src/main.c
	$(CC) -c $< -o $@

clean:
	rm -rf build