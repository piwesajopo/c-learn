#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** GOOD PRACTICE! *** 
typedef char buffer_1024[1024];
typedef struct {
	void (*func)(void);
	buffer_1024 *buffer;
} safe_struct; // More like "somewhat safe"

safe_struct *init_safe_struct(safe_struct *is, char *data) {
	safe_struct *s;
	if(is != NULL)
		s = is;
	else
		s = malloc(sizeof(safe_struct));

	if(s == NULL)
		return s;
	s->buffer = malloc(sizeof(buffer_1024));
	strncpy(*s->buffer, data, sizeof(buffer_1024));

	// Ensure last byte is '\0'
	// In case strcpy() reached 1024 bytes
	// before finding a '\0' character
	*s->buffer[sizeof(buffer_1024)-1] = '\0';
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
	printf("%s\n", *s.buffer);
	return 0;
}

//* IMPORTANT:
//*   The use of `buffer_1024 *buffer`
//*   May be confusing unless you have
//*   a good understanding of pointers
//*
//*   We define buffer_1024 as a char
//*   array of 1024 bytes. But we don't
//*   want to define buffer inside 
//*   safe_struct as this type (using
//*   `buffer_1024 buffer` would be the
//*   same as typing `char buffer[1024]`
//*   inside the struct definition).
//*
//*   Instead we want a pointer to a 
//*   1024-byte array. So buffer is of 
//*   type `char (*)[1024]`
//*   
//*   This is why you see the strcpy()
//*   function has the form:
//*   strncpy(*s->buffer, data, sizeof(buffer_1024))
//*   
//*   We need to decay s->buffer into a `char *`
//*   by dereferencing it as *s->buffer
//*   You may read *s->buffer to "The array to 
//*   which s->buffer points to". Once you understand
//*   this it is easy to understand why we use the 
//*   "contents of" (*) operator in this case.
