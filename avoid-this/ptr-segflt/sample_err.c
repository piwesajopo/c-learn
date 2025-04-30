#include <stdio.h>

// There are several problems with
// this example code. We deliberately
// avoided setting p to a valid address
// in order to generate warnings
//#define INITIALIZE

// Please check sample.c to see the
// proper way to handle pointers in
// this scenario.

int f(int *p)
{
	printf("%d", *p); // Avoid using a pointer without checking it's not NULL
	return 0;
}

int main()
{
	int *p; // Avoid declaring unitialized pointers
	int i = 5;

#ifdef INITIALIZE
	p = &i;
#endif

	// If p is not initialized can lead to UB.
	// That is, either will access a valid 
	// random memory location, or will cause a
	// segmentation fault.
	f(p);

	// Will cause a segmentation fault if 
	// NULL pointer is used inside f().
	f(NULL); 

	printf("\n");

	return 0;
}
// Use these flags when compiling: 
//    -Wall -Wextra 

