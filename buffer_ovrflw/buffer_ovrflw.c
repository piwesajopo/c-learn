#include <stdio.h>
#include <string.h>

// This an example of buffer overflow. 

// Please don't run this program on
// your main machine (use a test device)
// as it may lead to unexpected behavior.

// Comment this to run proper code
//#define OVERFLOW

int main () {
    char buffer[8];
    char input[64];

    printf("Enter input:");
    fgets(input, sizeof(input), stdin);

#ifdef OVERFLOW
    // Produces a buffer overflow if
    // User string is bigger than 7 bytes
    strcpy(buffer, input);
#else
    // Correct code to avoid buffer overflow:
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
#endif

    // // Please notice that sizeof when applied to an array will
    // // only return the real size in the block where it is declared!

    printf("Buffer content: %s\n", buffer);
    return 0;
}
