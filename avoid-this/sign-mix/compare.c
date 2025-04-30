#include <stdio.h>

// This example shows why mixing
// signed and unsigned types in
// expressions must be avoided

// The correct approach would be
// to declare i and j as type
// long int. So j can hold the 
// desired range of positive
// numbers.

int main() {
	int i = -1;
	unsigned int j = 1;

	// The compiler will convert i
	// to unsigned int, leading to
	// a wrong result "i>j" 
	if(i>j)
		printf("i>j");
	else
		printf("i<=j");

	return 0;
}

