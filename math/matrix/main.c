#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define COLS 5

int *add_matrix(int *m1, int *m2, size_t size) {

	if(m1 == NULL || m2 == NULL) {
		assert(0 && "Null pointer passed.");
		return NULL;
	}

	int *r = malloc(size);
	if(r == NULL) {
		assert(0 && "Memory Allocation Error.");
		return NULL;
	}
	
	//int *m3 = r;

	// The pragma instruction below is optional and not needed in most cases.
	// However it's a good practice to use it to encourage SIMD vectorization.
	#pragma GCC ivdep
	for(int i = 0; i<size; i++)	r[i] = m1[i]+m2[i]; // Uses SIMD vectorization on some arquitectures

	// Other ways that use pointer arithmetic but won't be optimized by the compiler:
	//	for(int i = 0; i<size; i++)	                 *r++ = *(m1++) + *(m2++); // Faster (on some compilers)
	//	for(int i = 0; i<size; i++, r++, m1++, m2++) *r = *m1 + *m2;           // Readability (pointer version)
	//  return m3; // instead of r (uncomment m3 definition above)

	return r;	
}

int main() {
    // A 6x5 Matrix (the first dimension can me ommited) 
	int matrix1[][COLS] = {
		{ 1, 2, 3, 4, 5},
		{ 6, 7, 8, 9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25},
		{26,27,28,29,30}
	};

	int matrix2[][COLS] = {
		{ 1, 2, 3, 4, 5},
		{ 6, 7, 8, 9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25},
		{26,27,28,29,30}  
	};

	int *m1_ptr = &matrix1[0][0];
	int *m2_ptr = &matrix2[0][0];

	size_t size = sizeof(matrix1);
	
	if (size != sizeof(matrix2)) {
		printf("Matrix size mismatch\n");
		return 1;
	}

	int *m3 = add_matrix(m1_ptr, m2_ptr, size);

	if (m3 != NULL) {
	    size_t rows = sizeof(matrix1) / sizeof(matrix1[0]);
		size_t cols = sizeof(matrix1[0]) / sizeof(matrix1[0][0]);

		printf("Matrix(%zu, %zu) Added:\n", rows, cols);

		int *r = m3;
		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++)
				printf("%2d ", *r++); // This works because the array is stored in the order of the initialization sintax
			printf("\n");
		} 

		// If you want to index using i,j:
		int (*m)[COLS] = (int (*)[COLS])m3; // but you should know the array size at compile time
		// Please note the syntax for the above pointer declaration
		// We declare m to be a pointer to an array of COLS columns
		// Also notice that m3 is a pointer to an int (int *) 
		// so we need to cast it properly using (int (*)[COLS])

		printf("\nAccessing using m[i][j]:\n");
		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++)
				printf("%2d ", m[i][j]);
			printf("\n");
		} 
	} else {
		printf("Unexpected Error\n");
	}
	return 0;
}
