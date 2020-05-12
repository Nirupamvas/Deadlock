#include <stdio.h>
#include <conio.h>
#include <graphics.h>
//Methods
void bankers();
void printMsg();
void start();
//con
void conditions();
void mutualex();
void holdandwait();
void nopreemption();
void circularwait();
//hand
void handling();
void ignorance();
void prevention();
void avoidance();
void detandrec();
//Main method
void main()
{
int ch;
clrscr();
//printMsg();
//printf(&quot;welcome %s\n&quot;,acc[employeeIndex].fname);
//printf(&quot;1.accounts\n2.new\n3.profile\n4.logout\n&quot;);
start();
//bankers();
getch();
}
//start
void start()
{
int ch;
clrscr();
printf("Welcome to the world of DeadLock\n");
printf("1.Necessary Conditions\n2.Methods of handling DeadLocks\n");
printf("Enter your choice:\t");
scanf("%d",&ch);
switch(ch)
{
case 1:clrscr();
       conditions();
break;
case 2:clrscr();
       handling();
break;
default:
exit(1);
}
}
//bankers method
void bankers()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;

printf("Enter the no of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
	completed[i] = 0;

printf("\n\nEnter the no of resources : ");
scanf("%d", &r);

printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ", i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &Max[i][j]);
}

printf("\n\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ",i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &alloc[i][j]);
}

printf("\n\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
		scanf("%d", &avail[i]);


	for(i = 0; i < p; i++)
		for(j = 0; j < r; j++)
			need[i][j] = Max[i][j] - alloc[i][j];

do
{
	printf("\n Max matrix:\tAllocation matrix:\n");
	for(i = 0; i < p; i++)
	{
		for( j = 0; j < r; j++)
			printf("%d  ", Max[i][j]);
		printf("\t\t");
		for( j = 0; j < r; j++)
			printf("%d  ", alloc[i][j]);
		printf("\n");
	}

	process = -1;

	for(i = 0; i < p; i++)
	{
		if(completed[i] == 0)//if not completed
		{
			process = i ;
			for(j = 0; j < r; j++)
			{
				if(avail[j] < need[i][j])
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\nProcess %d runs to completion!", process + 1);
		safeSequence[count] = process + 1;
		count++;
		for(j = 0; j < r; j++)
		{
			avail[j] += alloc[process][j];
			alloc[process][j] = 0;
			Max[process][j] = 0;
			completed[process] = 1;
		}
	}
}while(count != p && process != -1);

if(count == p)
{
	printf("\nThe system is in a safe state!!\n");
	printf("Safe Sequence : < ");
	for( i = 0; i < p; i++)
			printf("%d  ", safeSequence[i]);
	printf(">\n");
}
else
	printf("\nThe system is in an unsafe state!!");
}
//DeadLock Animation

void printMsg()
{
    // auto detection
    int gdriver = DETECT,gmode,i;
    // initialize graphics mode
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    for (i=5; i<=5; i++)
    //{
	// setcolor of cursor
	setcolor(i);
	// set text style as settextstyle(font, orientation, size)
	settextstyle(i,0,i*10);
	outtextxy(75,20*i,"DeadXLock");
	delay(500);
//}
   delay(2000);
}
//Handling method
void handling()
{
int ch;
printf("Methods of handling DeadLocks\n");
printf("1.Deadlock Ignorance\n2.Deadlock prevention\n3.Deadlock avoidance\n4.Deadlock detection and recovery\n");
printf("Enter your choice:\t");
scanf("%d",&ch);
switch(ch)
{
case 1:ignorance();
break;
case 2:prevention();
break;
case 3:avoidance();
break;
case 4:detandrec();
break;
default:clrscr();
        start();
}
}

void ignorance()
{

    int ch;
    clrscr();
    printf("IGNORANCE:-Deadlock Ignorance is the most widely used approach among all the mechanism. This is being used by many operating systems mainly for end user uses. In this approach, the Operating system assumes that deadlock never occurs. It simply ignores deadlock. This approach is best suitable for a single end user system where User uses the system only for browsing and all other normal stuff.There is always a tradeoff between Correctness and performance. The operating systems like Windows and Linux mainly focus upon performance. However, the performance of the system decreases if it uses deadlock handling mechanism all the time if deadlock happens 1 out of 100 times then it is completely unnecessary to use the deadlock handling mechanism all the time.In these types of systems, the user has to simply restart the computer in the case of deadlock. Windows and Linux are mainly using this approach.");
    printf("\nPress 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();handling();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
    getch();
}
//handling- prevention
void prevention()
{

    int ch;
    clrscr();
    printf("PREVENTION:-Deadlock happens only when Mutual Exclusion, hold and wait, No preemption and circular wait holds simultaneously. If it is possible to violate one of the four conditions at any time then the deadlock can never occur in the system.The idea behind the approach is very simple that we have to fail one of the four conditions but there can be a big argument on its physical implementation in the system.");
    printf("Press 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();handling();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
    getch();
}
//handling- avoidance
void avoidance()
{
    int ch;
    clrscr();
    printf("AVOIDANCE:-In deadlock avoidance, the operating system checks whether the system is in safe state or in unsafe state at every step which the operating system performs. The process continues until the system is in safe state. Once the system moves to unsafe state, the OS has to backtrack one step.In simple words, The OS reviews each allocation so that the allocation doesn't cause the deadlock in the system.");
    getch();
	printf("Deadlock avoidance\n");
	printf("1.Deadlock Ignorance(Bankers algorithm)\n");
	printf("Enter your choice:\t");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:clrscr();bankers();
	break;
	default:handling();
	}

    printf("\nPress 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();handling();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
}
//handling- detandrec
void detandrec()
{

    int ch;
    clrscr();
    printf("This approach let the processes fall in deadlock and then periodically check whether deadlock occur in the system or not. If it occurs then it applies some of the recovery methods to the system to get rid of deadlock.Deadlock RecoveryA traditional operating system such as Windows doesn’t deal with deadlock recovery as it is time and space consuming process. Real-time operating systems use Deadlock recovery.Recovery methodKilling the process: killing all the process involved in the deadlock. Killing process one by one. After killing each process check for deadlock again keep repeating the process till system recover from deadlock.Resource Preemption: Resources are preempted from the processes involved in the deadlock, preempted resources are allocated to other processes so that there is a possibility of recovering the system from deadlock. In this case, the system goes into starvation.");
    printf("\nPress 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();handling();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
    getch();
}
//Conditions Method
void conditions()
{
int ch;
clrscr();
printf("Conditions of DeadLocks\n");
printf("1.Mutual Exclusion\n2.Hold and Wait\n3.No Preemption\n4.Cirular Wait\n");
printf("Enter your choice:\t");
scanf("%d",&ch);
switch(ch)
{
case 1:mutualex();
break;
case 2:holdandwait();
break;
case 3:nopreemption();
break;
case 4:circularwait();
break;
default:clrscr();start();
}
}
//conditions- mutualex
void mutualex()
{

    int ch;
    clrscr();
    printf("MUTUAL EXCLUSION:-The resources involved must be unshareable; otherwise, the processes would not be prevented from using the resource when necessary.");
    printf("\nPress 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();conditions();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
    getch();
}
//conditions- holdandwait
void holdandwait()
{

    int ch;
    clrscr();
    printf("HOLD AND WAIT or PARTIAL ALLOCATION:-The processes must hold the resources they have already been allocated while waiting for other (requested) resources. If the process had to release its resources when a new resource or resources were requested, deadlock could not occur because the process would not prevent others from using resources that it controlled.no pre-emption");
    printf("\nPress 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();conditions();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
    getch();
}
//conditions- nopreemption
void nopreemption()
{

    int ch;
    clrscr();
    printf("NO-PREEMPTION:-The processes must not have resources taken away while that resource is being used. Otherwise, deadlock could not occur since the operating system could simply take enough resources from running processes to enable any process to finish.");
    printf("\nPress 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();conditions();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
    getch();
}
//conditions- circularwait
void circularwait()
{

    int ch;
    clrscr();
    printf("RESOURCE WAITING or CIRCULAR WAIT:-A circular chain of processes, with each process holding resources which are currently being requested by the next process in the chain, cannot exist. If it does, the cycle theorem (which states that a cycle in the resource graph is necessary for deadlock to occur) indicated that deadlock could occur.");
    printf("\nPress 1 to go back 0 to exit:\t");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:clrscr();conditions();
    break;
    case 0:clrscr();start();
    break;
    default:
    exit(1);    
    }
    getch();
}

