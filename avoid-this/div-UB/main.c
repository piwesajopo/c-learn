#include <stdio.h>

// Since division by 0 is considered UB (undefined behavior)
// this code may result in different outcomes depending the
// compiler and processor combination.

int main() {
   unsigned x = 4;
   unsigned y = 0;
   unsigned z = x/y; // udiv instruction on ARMv7/ARMv8 (or Apple Silicon) yields 0
   printf("Division OK\n");
   printf("Value of z is %d\n", z);
}
