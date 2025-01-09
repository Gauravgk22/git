#include <stdio.h>

int main() {
    int i, j, w[24] = {0}, cw[24] = {0};
    int P[17] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};

    printf("Enter the 8-bit data (separated by spaces):\n");

    // Read all 8 bits in a single line
    for (i = 0; i < 8; i++) {
        scanf("%d", &w[i]);
    }

    // Initialize the codeword
    for (i = 0; i < 8; i++) {
        cw[i] = w[i];
    }

    for (i = 8; i < 24; i++) {
        cw[i] = 0; // Initialize the rest of the code word to 0
    }

    // Perform XOR operation based on the polynomial
    for (i = 0; i < 8; i++) {
        if (cw[i] == 1) {
            for (j = 0; j < 17; j++) {
                cw[i + j] = (cw[i + j] ^ P[j]);
            }
        }
    }

    // Print the final code word
    printf("Code word is:\n");
    for (i = 0; i < 24; i++) {
        printf("%d", cw[i]);
    }

    printf("\n");
    return 0;
}

