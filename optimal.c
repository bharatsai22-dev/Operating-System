//Optimal
#include <stdio.h>
int main()
{
    int i, j, k, n, no, a[50], frame[10];
    int count = 0, avail, pos = -1;
    int farthest, next;

    printf("\nENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);

    printf("\nENTER THE PAGE NUMBERS:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nENTER THE NUMBER OF FRAMES:\n");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    printf("\nRef String\tPage Frames\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;

        for (j = 0; j < no; j++)
        {
            if (frame[j] == a[i])
            {
                avail = 1;
                break;
            }
        }

        if (avail == 0)
        {
            farthest = -1;
            pos = -1;

            for (j = 0; j < no; j++)
            {
                next = -1;

                for (k = i + 1; k < n; k++)
                {
                    if (frame[j] == a[k])
                    {
                        next = k;
                        break;
                    }
                }

                if (next == -1)
                {
                    pos = j;
                    break;
                }

                if (next > farthest)
                {
                    farthest = next;
                    pos = j;
                }
            }

            frame[pos] = a[i];
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
