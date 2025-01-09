#include <stdio.h>
#include <limits.h> // For INT_MAX

// Define a structure for routing table
struct node {
    unsigned dist[20]; // Distance array
    unsigned from[20]; // From array (next hop)
};

int main() {
    int dmat[20][20];        // Distance matrix
    struct node rt[20];      // Routing tables for each node
    int n, i, j, k, count = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dmat[i][j]);
            // If no direct link, set cost to a very high value (infinity)
            if (dmat[i][j] == 0 && i != j) {
                dmat[i][j] = INT_MAX;
            }
            rt[i].dist[j] = dmat[i][j]; // Initialize distance to the cost matrix
            rt[i].from[j] = j;          // Initialize next hop to itself
        }
    }

    do {
        count = 0; // Reset the count for changes
        for (i = 0; i < n; i++) { // Iterate through each router
            for (j = 0; j < n; j++) { // Iterate through each destination
                for (k = 0; k < n; k++) { // Check all possible next hops
                    if (rt[i].dist[j] > dmat[i][k] + rt[k].dist[j] && rt[k].dist[j] != INT_MAX && dmat[i][k] != INT_MAX) {
                        rt[i].dist[j] = dmat[i][k] + rt[k].dist[j]; // Update the distance
                        rt[i].from[j] = k; // Update the next hop
                        count++;
                    }
                }
            }
        }
    } while (count != 0); // Repeat until no changes occur

    // Print the final routing tables
    for (i = 0; i < n; i++) {
        printf("\nRouting table for router %d:\n", i + 1);
        printf("Destination\tNext Hop\tDistance\n");
        for (j = 0; j < n; j++) {
            if (rt[i].dist[j] == INT_MAX) {
                printf("%d\t\t-\t\tINF\n", j + 1);
            } else {
                printf("%d\t\t%d\t\t%d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
            }
        }
    }

    return 0;
}

