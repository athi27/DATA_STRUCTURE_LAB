#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL;
struct node *ptr=NULL;
struct node *new;
void main()
{
int n,i;
printf("Enter the number of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
new=(struct node*)malloc(sizeof(struct node));
printf("Enter the data to be inserted:");
scanf("%d",&new->data);
new->next=NULL;
if(head==NULL)
head=new;
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=new;
}
}
printf("The linked list is:\n");
ptr=head;
while(ptr!=NULL)
{
printf("%d\t\n",ptr->data);
ptr=ptr->next;
}
}

