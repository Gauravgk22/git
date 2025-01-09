#include <stdio.h>

int main() {
    int size, orate, n, i, pkt[50];

    printf("Enter the bucket size: ");
    scanf("%d", &size);

    printf("Enter the total number of packets: ");
    scanf("%d", &n);

    printf("Enter the output rate: ");
    scanf("%d", &orate);

    for (i = 0; i < n; i++) {
        printf("Enter the size of packet %d: ", i + 1);
        scanf("%d", &pkt[i]);
    }

    for (i = 0; i < n; i++) {
        if (pkt[i] > size) {
            printf("Packet %d of size %d is discarded (exceeds bucket size).\n", i + 1, pkt[i]);
            continue;
        }

        while (pkt[i] > 0) {
            if (pkt[i] > orate) {
                printf("From packet %d, %d bytes are transmitted.\n", i + 1, orate);
                pkt[i] -= orate;
            } else {
                printf("%d bytes of packet %d are directly transmitted.\n", pkt[i], i + 1);
                pkt[i] = 0;
            }
        }
        printf("Packet %d is completely transmitted.\n", i + 1);
    }

    return 0;
}

