// Round Robin C Program
#include<stdio.h>
struct process
{
int pid,bt,tt,wt;
};
int main()
{
struct process p[30];
int i,j,k,tot=0,ctime=0,m,n;
float wttime=0.0,tottime,a1,a2;
printf("\nEnter No.of processes:");
scanf("%d",&n);
for(i=1;i<=n;i++)
       {    
        
p[i].pid=i;
	printf("Enter the process %d Burst Time:",i);
	scanf("%d",&p[i].bt);
	p[i].wt=0;
	p[i].tt=0;
	tot=tot+p[i].bt;
       }
printf("Total Burst Time:\t%d",tot);
printf("\nEnter The Time Slice:\t");
scanf("%d",&m);
printf("\nprocess id\twt\ttt");
while(tot>0)
{
    for(i=1;i<=n;i++)
	{
        if(p[i].bt!=0)
		{
                 if(p[i].bt-m<0)
		     {
		      p[i].wt=p[i].wt+ctime-p[i].tt;
		      p[i].tt=ctime+p[i].bt;
		      tot-=p[i].bt;
		      printf("\n\t%d\t%d\t%d",p[i].pid,ctime,ctime+p[i].bt);
		      ctime+=p[i].bt;
		      p[i].bt=0;
		     }
		else
		{
		p[i].wt=p[i].wt+ctime-p[i].tt;
		p[i].tt=ctime+m;
		p[i].bt=p[i].bt-m;
		tot-=m;
		printf("\n\t%d\t%d\t%d",p[i].pid,ctime,ctime+m);
		ctime+=m;
		}
	          }

}
}
for(i=1;i<=n;i++)
{
printf("\nProcess %d: Waiting Time:%d Turnaround Time:%d",i,p[i].wt,p[i].tt);
wttime=wttime+p[i].wt;
tottime=tottime+p[i].tt;
}
a1=wttime/n;
a2=tottime/n;
printf("\n\nAverage Waiting Time:\t%f",a1);
printf("\n\nAverage TurnAround Time:\t%f",a2);
return 0;
}
