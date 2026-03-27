//Priority C Program
#include<stdio.h>
struct process
{
int pid;
int wt,tt,bt,prior;
}
p[100],temp;
int main()
{
int tottt,totwt,i,j,n,k;
float avgwt,avgtt;
printf("\nEnter Number of process:"); 
scanf("\n%d",&n); for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("\nEnter process %d Burst Time:",i);
scanf("%d",&p[i].bt);
printf("\nEnter process %d priority",i);
scanf("\%d",&p[i].prior);
}
for(i=1;i<=n;i++)
{
k=i;
for(j=i+1;j<=n;j++)
{
if(p[k].prior>p[j].prior)
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
p[i].wt=p[i-1].tt; p[i].tt=p[i].bt+p[i].wt; i++; }
totwt=tottt=0;
i=1;
printf("\n\t===============================");
printf("\n\tPSSID\tBT\tWT\tTT");
printf("\n\t===============================");
while(i<=n)
{
printf("\n\t%d\t%d\t%d\t%d\t",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
totwt=p[i].wt+totwt;
tottt=p[i].tt+tottt;
i++;
}
avgwt=(float)totwt/n;
avgtt=(float)tottt/n;
printf("\n\n\n\tAVGWT\tAVGTT");
printf("\n\t%f\t%f",avgwt,avgtt);
}
