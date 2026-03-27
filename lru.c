//LRU
#include <stdio.h>
int main()
{
    int i, j, k, n, no, a[50], frame[10], time[10];
    int count = 0, t = 0, avail, min, pos;

    printf("ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);

    printf("ENTER THE PAGE NUMBERS:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("ENTER THE NUMBER OF FRAMES:\n");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nRef String\tPage Frames\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;

        for (j = 0; j < no; j++)
        {
            if (frame[j] == a[i])
            {
                t++;
                time[j] = t;
                avail = 1;
                break;
            }
        }

        if (avail == 0)
        {
            min = time[0]; pos = 0;
            for (j = 1; j < no; j++)
                if (time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }

            frame[pos] = a[i];
            t++;
            time[pos] = t;
            count++;
        }

        for (k = 0; k < no; k++)
        {
            if (frame[k] != -1)
                printf("%d\t", frame[k]);
            else
                printf("-\t");
        }
        printf("\n");
    }

    printf("\nPage Faults = %d\n", count);
    return 0;
}
