#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define WRGBUF_SIZE 1032

// BAD PRACTICE!
// Function pointer is below a buffer.
// Overflowing the buffer will alter 
// the function pointer address.
typedef struct {
	char buffer[BUFFER_SIZE];
	void (*func)(void);
} unsafe_struct;
//********************************
//* Note:                        *
//*  Is better to avoid mixing   *
//*  function pointers with data *
//*                              *
//*  Check safe_struct.c for the *
//*  correct approach for this   *
//********************************

void hello_func(void) {
	printf("Hello Buffer!\n");
}

int main() {
	unsafe_struct s;
	
	// Dangerous if size is incorrect
	// Use WRGBUF_SIZE to see how this can go wrong
	char some_rnd_data[BUFFER_SIZE];
	memcpy(s.buffer, some_rnd_data, BUFFER_SIZE);

	s.func = hello_func;
	s.func();
	return 0;
}
