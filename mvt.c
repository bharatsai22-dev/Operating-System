// MVT Simulation
#include <stdio.h>
#define MAX_TASKS 10

int main() {
    int totalMemory;
    int n;
    int taskSize[MAX_TASKS];
    int allocated[MAX_TASKS];
    int i;
    int memoryUsed = 0;

    printf("Enter total memory size (in KB): ");
    scanf("%d", &totalMemory);

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    if (n > MAX_TASKS) {
        printf("Number of tasks exceeds system limit.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter memory required for Task %d (in KB): ", i + 1);
        scanf("%d", &taskSize[i]);
        allocated[i] = 0; // initially not allocated
    }

    printf("\n--- Memory Allocation Table (MVT) ---\n");
    printf("Task\tTask Size\tStatus\n");

    for (i = 0; i < n; i++) {
        if (memoryUsed + taskSize[i] <= totalMemory) {
            allocated[i] = 1;
            memoryUsed += taskSize[i];
            printf("%d\t%d KB\t\tAllocated\n", i + 1, taskSize[i]);
        } else {
            printf("%d\t%d KB\t\tNot Allocated (Insufficient memory)\n", i + 1, taskSize[i]);
        }
    }

    printf("\nTotal Memory Used = %d KB\n", memoryUsed);
    printf("Remaining Memory = %d KB\n", totalMemory - memoryUsed);

    return 0;
}

