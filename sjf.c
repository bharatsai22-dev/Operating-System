//SJF C Program
#include<stdio.h>
struct process
{
int pid;
int wt,tt,bt;
}
p[100];
int main()
{
struct process temp;
int tottt,totwt,avgtt,avgwt,i,j,n,k;
printf("\nEnter Number of process:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("\nEnter %d Burst Time:",i);
scanf("%d",&p[i].bt);
}
for(i=1;i<=n;i++)
{
k=i;
for(j=i+1;j<=n;j++)
{
if(p[k].bt>p[j].bt)
{
k=j;
}
}
temp=p[i];
p[i]=p[k];
p[k]=temp;
}
p[1].wt=0;
p[1].tt=p[1].bt+p[1].wt;
i=2;
while(i<=n)
{
p[i].wt=p[i-1].tt;
p[i].tt=p[i].bt+p[i].wt;
i++;
}
totwt=tottt=0;
i=1;
printf("\n\t=================================");
printf("\n\t Process id \tBT\tWT\tTT");
printf("\n\t================================");
while(i<=n)
{
printf("\n\t%d\t%d\t%d\t%d\t",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
totwt=p[i].wt+totwt;
tottt=p[i].tt+tottt;
i++;
}
avgwt=totwt/n;
avgtt=tottt/n;
printf("\n\n\n\tAVGWT\tAVGTT");
printf("\n\t%d\t%d",avgwt,avgtt);
return 0;
}
