#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
int i,j,p,k;

void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES], int n, int m) {
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafe(int processes[], int avail[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int n, int m) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeed(need, max, allocation, n, m);

    bool finish[MAX_PROCESSES] = {0};
    int work[MAX_RESOURCES];
    for (i = 0; i < m; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < n) {
        bool found = false;
        for (p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (k = 0; k < m; k++)
                        work[k] += allocation[p][k];
                    finish[p] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state\n");
            return false;
        }
    }
    printf("System is in a safe state\n");
    return true;
}

int main() {
    int n, m;
    int processes[MAX_PROCESSES];
    int avail[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter the Max Matrix (each row represents a process):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Allocation Matrix (each row represents a process):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the Available resources vector: ");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    isSafe(processes, avail, max, allocation, n, m);

    return 0;
}

