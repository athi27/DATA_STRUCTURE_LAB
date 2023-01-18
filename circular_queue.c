/* IMPLEMENTATION OF CIRCULAR QUEUE*/

#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();
int F=-1,R=-1,item,size=3,A[30];
void main()
{
int opt;
do
{
printf("\nEnter your option\n 1.insertion\n 2.deletion\n 3.display\n 4.exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
     insertion();
     break;
case 2:
     deletion();
     break;
     case 3:
    display();
     break;
     case 4:
     exit(0);
     default :printf("invalid entry\n");
}
}
while(opt!=4);
}
void insertion()
{
if (F==(R+1)%size)
{
printf("Queue is full");
}
else
{
printf("\n Enter the item :");
scanf("%d",&item);

if(F==-1&&R==-1)
{
F=0;
R=0;
A[R]=item;
}
else
{
R=(R+1)%size;
A[R]=item;
}
}
}
void deletion()
{
if(F==-1)
{
printf("\nQueue is empty");
}
else if(F==R)
{
printf("\n Deleted elements %d",A[F]);
F=R=-1;
}
else
{
printf("\nItem to be deleted %d \n",A[F]);
F=(F+1)%size;
}
}
void display()
{
int i;
i=F;
if(i == -1 && R == -1)
{
printf("Queue is empty");
}
else
{
printf("\n Elements are: \n");
while(i>-1)
{
printf("\n%d",A[i]);
if(i==R)
break;
i=(i+1)%size;
}
}
}
