#include <stdio.h>
#include <string.h>

int main() {
    char a[30], fs[50] = "", x[3], y[3], sd, stuffedData[200];
    char data[100];
    int i, len, count = 0, j = 0;
    int choice = 0;

    printf("--- MENU ---\n");
    printf("1. Character Stuffing\n");
    printf("2. Bit Stuffing\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Character Stuffing
            printf("Character Stuffing\n");
            printf("Enter a word to be stuffed: ");
            scanf("%s", a);

            printf("Enter a character that represents the starting delimiter: ");
            scanf(" %c", &sd);

            x[0] = sd;
            x[1] = '\0'; // Null-terminate the delimiter string

            strcat(fs, x); // Add the starting delimiter

            for (i = 0; i < strlen(a); i++) {
                char t[2] = {a[i], '\0'}; // Convert character to string
                if (t[0] == sd) {         // If character matches the delimiter
                    strcat(fs, x);       // Add the delimiter again
                }
                strcat(fs, t); // Add the character
            }

            strcat(fs, x); // Add the ending delimiter

            printf("After stuffing: %s\n", fs);

            // De-stuffing
            len = strlen(fs);
            j = 0;
            for (i = 1; i < len - 1; i++) { // Skip the starting and ending delimiters
                if (fs[i] == sd && fs[i + 1] == sd) {
                    i++; // Skip the stuffed delimiter
                }
                stuffedData[j++] = fs[i];
            }
            stuffedData[j] = '\0';

            printf("After de-stuffing: %s\n", stuffedData);
            break;

        case 2: // Bit Stuffing
            printf("Bit Stuffing\n");
            printf("Enter the stream of bits (0s and 1s): ");
            scanf("%s", data);

            len = strlen(data);
            count = 0;
            j = 0;

            for (i = 0; i < len; i++) {
                if (data[i] == '1') {
                    count++;
                    stuffedData[j++] = data[i];
                    if (count == 5) { // Insert a '0' after five consecutive 1s
                        stuffedData[j++] = '0';
                        count = 0;
                    }
                } else {
                    stuffedData[j++] = data[i];
                    count = 0; // Reset count for 0
                }
            }

            stuffedData[j] = '\0';

            printf("Data after bit stuffing: %s\n", stuffedData);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

