#include <stdio.h>

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++) allocation[i] = -1;

    int tempBlock[blocks];
    for (int i = 0; i < blocks; i++) tempBlock[i] = blockSize[i];

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < blocks; j++) {
            if (tempBlock[j] >= processSize[i]) {
                allocation[i] = j;
                tempBlock[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++) allocation[i] = -1;

    int tempBlock[blocks];
    for (int i = 0; i < blocks; i++) tempBlock[i] = blockSize[i];

    for (int i = 0; i < processes; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (tempBlock[j] >= processSize[i]) {
                if (bestIdx == -1 || tempBlock[j] < tempBlock[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            tempBlock[bestIdx] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++) allocation[i] = -1;

    int tempBlock[blocks];
    for (int i = 0; i < blocks; i++) tempBlock[i] = blockSize[i];

    for (int i = 0; i < processes; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (tempBlock[j] >= processSize[i]) {
                if (worstIdx == -1 || tempBlock[j] > tempBlock[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            tempBlock[worstIdx] -= processSize[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
    }
}

int main() {
    int blocks, processes;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);

    int blockSize[blocks];
    printf("Enter size of each block:\n");
    for (int i = 0; i < blocks; i++) scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    int processSize[processes];
    printf("Enter size of each process:\n");
    for (int i = 0; i < processes; i++) scanf("%d", &processSize[i]);

    firstFit(blockSize, blocks, processSize, processes);
    bestFit(blockSize, blocks, processSize, processes);
    worstFit(blockSize, blocks, processSize, processes);

    return 0;
}
