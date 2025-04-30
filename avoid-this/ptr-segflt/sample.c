#include <stdio.h>

// Even if we comment this so
// p is not pointing to i, the
// program will run properly
// and detect the error.
#define INITIALIZE

// Use [[nodiscard]] to force return value assignment
[[nodiscard]] int f(int *p)
{
	if(p == NULL)
		return -1; // p is not valid

	printf("%d", *p);
	return 0;
}

int main()
{
	int *p = NULL; // Always initialize your pointers
	int r, i = 5;

#ifdef INITIALIZE
	p = &i; // Make sure it's pointing to something
#endif

	r = f(p);

	// Have some way to check for errors.
	if(r == -1) printf("Error returned by f()\n");
	else		printf("\nOK\n");

	return 0;
}
// Use these flags when compiling: 
//    -Wall -Wextra 
