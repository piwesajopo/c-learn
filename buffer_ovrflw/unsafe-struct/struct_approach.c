#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ****************************************************
// * The example program at main.c is generally more  *
// * elegant and consice, however using a pointer to  *
// * a 1024 array may confuse novice programmers.     *
// *                                                  *
// * Here's a version that uses an struct to hold the *
// * buffer. It is named in a way that the code looks *
// * easier to understand.                            *
// ****************************************************

typedef struct {
	char sized_1024[1024];
} s_buffer;

typedef struct {
	void (*func)(void);
	s_buffer *buffer;
} safe_struct;

safe_struct *init_safe_struct(safe_struct *is, char *data) {
	safe_struct *s;
	if(is != NULL)
		s = is;
	else
		s = malloc(sizeof(safe_struct));

	if(s == NULL)
		return s;

	s->buffer = malloc(sizeof(s_buffer));
	strncpy(s->buffer->sized_1024, data, sizeof(s->buffer->sized_1024));

    // Ensure last byte is '\0'
	// In case strcpy() reached 1024 bytes
	// before finding a '\0' character
	s->buffer->sized_1024[sizeof(s->buffer->sized_1024)-1] = '\0';
	return s;
}

void hello_func(void) {
	printf("Hello Buffer!\n");
}

int main() {
	safe_struct s;
	if(init_safe_struct(&s, "Let's Be Cool!") == NULL) {
		printf("Error Initializing safe_struct!\n");
	}

	s.func = hello_func;
	s.func();
	printf("%s\n", s.buffer->sized_1024);
	return 0;
}
