#include <stdio.h>
int main()
{
    int i, n, bt[50], wt[50], tat[50];   
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if(n <= 0){ printf("Invalid number of processes!\n"); return 0; }

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("\nAverage WT = %.2f", avg_wt/n);
    printf("\nAverage TAT = %.2f\n", avg_tat/n);

    return 0;
}
