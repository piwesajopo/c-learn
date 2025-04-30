#include <stdio.h>

// Comment this to generate proper code
#define BAD

int main()
{
#ifdef BAD
	char *str = "Hello world";
#else
	char str[] = "Hello world";
#endif

	// Avoid modifying constant
	// Will yield bus error or
	// Segmentation Fault 
	str[6] = 'W';
	// The above code will work if 
	// str is a char str[], since 
	// compiler will make a copy 
	// of the constant string into
	// the array variable

	printf("%s\n", str);
	return 0;
}
