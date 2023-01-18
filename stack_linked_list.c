//Program to implement stack as a linked list.
#include<stdio.h>
#include<stdlib.h>

//Declare functions for Push,Pop and Displaying the stack.
void push();
void pop();
void disp();

//Define structure of the node.
struct node{
int data;
struct node *next;
};

//Declaring top pointer for the stack of type struct node.
struct node *top=NULL,*ptr=NULL;

void main(){
int opt;
do{
printf("\nStack Operations: \n\t 1.Push \n\t 2.Pop \n\t 3.Display \n\t 4.Exit ");
printf("\nEnter your choice:");
scanf("%d",&opt);
switch(opt){
case 1: push();
break;
case 2: pop();
break;
case 3: disp();
break;
case 4: exit;
break;
default:printf("Invalid choice!!");
}
}while(opt !=4);
}

//Push function
void push(){
struct node *new=NULL;
int n;
printf("Enter the no.of nodes to be inserted to the stack:");
scanf("%d",&n);
for (int i=1;i<=n;i++){
new = (struct node*)malloc(sizeof(struct node));
if(new==NULL)
printf("\nStack Overflow..\n Insufficient memory!!!");
else{
printf("\nEnter the data to be pushed into the stack:");
scanf("%d",&new->data);
new->next=top;
top=new;
}
}
printf("\nStack post insertion:");
disp();
}

//Pop function
void pop(){
if(top==NULL){
printf("\nStack Underflow..\n Pop cannot be performed!!!");
return ;
}
else{
int n;
printf("Enter the no.of nodes to be removed from the stack:");
scanf("%d",&n);
for(int i=1;i<=n;i++){
if (top==NULL){
printf("\n No more elements to be deleted from the stack.");
break;
}

else{
ptr=top;
//printf("\nThe data popped out of the stack is %d.",top->data);
top=top->next;
free(ptr);
}
}
}
printf("\nStack post deletion:");
disp();
}

//Stack display function

void disp(){
if(top==NULL)
printf("\nStack is empty!!!");
else{
ptr=top;
printf("\nStack elements are :");
while(ptr!=NULL){
printf("\n%d",ptr->data);
ptr=ptr->next;
}
}
}
