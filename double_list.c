/*IMPLEMENTATION OF DOUBLY LINKED LIST*/

#include<stdio.h>
#include<stdlib.h>
void insertb();
void inserte();
void insertm();
void delb();
void dele();
void delm();
void display();
struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node *head=NULL;
struct node *ptr=NULL;
struct node *new=NULL;
struct node *temp=NULL;
void main()
{
int n,i,opt;
printf("enter the no of elements");
scanf("%d",&n);
for(i=0;i<n;i++)
{
new=(struct node *)malloc(sizeof(struct node));
printf("enter the data to be inserted ");
scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
if(head==NULL)
{
head=new;
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
new->prev=ptr;
ptr->next=new;
}
}
do
{
printf("\nEnter your choice:\n1. Insert ath beginning\n2. Insert at end\n3. insert at middle\n4.delete atthe beginning\n5. delete at the end\n6. delete at the middle\n7. display\n8. exit");
scanf("%d",&opt);
switch (opt)
{
case 1:insertb();
break;
case 2:inserte();

break;
case 3:insertm();
break;
case 4:delb();
break;
case 5:dele();
break;
case 6:delm();
break;
case 7:display();
break;
case 8:printf("EXIT");
break;
default:printf("invalid chooise");
}
}
while(opt!=8);
}
void insertb()
{
new=(struct node *)malloc(sizeof(struct node));
printf("enter the data to be inserted at beginning ");
scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
new->next=head;
head=new;
}
void inserte()
{
new=(struct node *)malloc(sizeof(struct node));
printf("\nenter the data to be inserted end ");
scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
if(head==NULL)
{
head=new;
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
new->prev=ptr;
ptr->next=new;
}
}
void insertm()
{
int key;
printf("enter the key ");
scanf("%d",&key);
new=(struct node *)malloc(sizeof(struct node));
printf("\nenter the data to be inserted ");

scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
if(head==NULL)
{
head=new;
}
else
{
ptr=head;
while(ptr->next!=NULL && ptr->data!=key)
{
ptr=ptr->next;
}
}
if(ptr->next==NULL)
{
if(ptr->data!=key)
printf("%d is not found in list so insert the element as last element",key);
ptr->next=new;
new->prev=ptr;
}
else
{
temp=ptr->next;
new->next=temp;
new->prev=ptr;
ptr->next=new;
temp->prev=new;
}
}
void display()
{
printf("list is ");
ptr=head;
while(ptr!=NULL)
{
printf("%d->",ptr->data);
ptr=ptr->next;
}
}
void delb()
{
if(head->next!=NULL)
{
printf("\n %d is deleted ",head->data);
head=head->next;
}
}
void dele()
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
if(ptr->next==NULL)
{
temp=ptr->prev;
temp->next=NULL;
ptr->prev=NULL;
printf("\n %d is deleted ",ptr->data);
}
}
void delm()
{
int key;
printf("enter the key to be deleted ");
scanf("%d",&key);
if(head->data==key)
{
head=head->next;
}
temp=head;
ptr=head->next;
while(ptr!=NULL)
{
if(ptr->data==key)
{
temp->next=ptr->next;
temp->prev=ptr->prev;
free(ptr);
printf("\n %d is deleted ",key);
}
else
{
temp=ptr;
ptr=ptr->next;
}
}
}
