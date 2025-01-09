#include <stdio.h>
#include <stdlib.h> // For the exit() function

int main() {
    int i, j, flag = 0;
    int dw[8], cw[24];
    int P[17] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

    printf("Enter the 24-bit code word (space-separated):\n");

    // Input all 24 bits in one line
    for (i = 0; i < 24; i++) {
        scanf("%d", &cw[i]);
    }

    // Perform error-checking using XOR with the polynomial
    for (i = 0; i < 8; i++) {
        if (cw[i] == 1) {
            for (j = 0; j < 17; j++) {
                cw[i + j] ^= P[j]; // XOR operation with the polynomial
            }
        }
    }

    // Check if there's an error in the code word
    for (i = 8; i < 24; i++) {
        if (cw[i] == 1) {
            printf("Error occurred in the code word.\n");
            flag = 1;
            exit(0); // Exit the program if an error is found
        }
    }

    // If no error, extract the original 8-bit data
    if (flag == 0) {
        printf("Data is error-free.\n");
        printf("Original 8-bit data:\n");
        for (i = 0; i < 8; i++) {
            dw[i] = cw[i]; // Extract the original 8-bit data
            printf("%d", dw[i]); // Print the original 8-bit data in 0s and 1s
        }
        printf("\n");
    }

    return 0;
}

