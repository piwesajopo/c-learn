#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Returns Square Root of x using newton method
double nwt_sqrt(double x) {
    if (x < 0) {
        return -1.0;
    }
    if (x == 0) return 0.0;

	double guess   = x/2.0;
	double epsilon = 0.000001;

	while(fabs(guess*guess - x) > epsilon)
		guess = (x/guess + guess) / 2.0;

	
	return guess;

}

int main (int argc, char *argv[]) {
	double x, s;
    char *endptr;

	if(argc == 1) {
		fprintf(stderr, "Please specify a number.\nSyntax:\n    %s [number]\n\n", argv[0]);
		return 1;
	}

	// Convert input to double with error checking
    x = strtod(argv[1], &endptr);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: Invalid number provided\n\n");
        return 1;
    }

	s = nwt_sqrt(x);

	if(x>=0) {
		printf("Square root of %g = %g\n\n", x, s);
	} else{
		printf("Please enter a positive number.\n\n");
	} 
}
