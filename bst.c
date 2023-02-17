#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *right;
struct node *left;
};
struct node *root=NULL,*ptr=NULL,*new=NULL,*ptr1=NULL,*parent=NULL,*p=NULL;

void insert();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search(struct node*);
void deletion(int);
void main()
{
int opt,x;
do
{
printf("\n enter your choice:\n1.insert \n2.inorder \n3.preorder \n4.postorder \n5.search \n6.deletion \n7.exit");
scanf("%d",&opt);
switch(opt)
{
case 1: insert();
        break;
case 2: inorder(root);
        break;
case 3: preorder(root);
	break;
case 4: postorder(root);
	break;
case 5: search(root);
        break;
case 6: deletion(x);
        break;
case 7: exit(0);
	break;
default:printf("invalid");	
}
}
while(opt!=7);
}
void insert()
{
int x;
new=(struct node*)malloc(sizeof(struct node));
printf("\n enter the data to be inserted:");
scanf("%d",&x);
if(new==NULL)
{
printf("insufficient memory");
}
else
{
new->left=NULL;
new->right=NULL;
new->data=x;
if(root==NULL)
{
root=new;
return;          
}
else
{
ptr=root;
while(ptr!=NULL)
{
if(x==ptr->data)
{
printf("item present in the tree");
break;
} 
else if(x>ptr->data)
{
ptr1=ptr;
ptr=ptr->right;		
}
else
{
ptr1=ptr;
ptr=ptr->left;
}
}
      
if(ptr==NULL)
{
if(x>ptr1->data)
ptr1->right=new;
else
ptr1->left=new;
}
}
}    
}
void inorder(struct node *ptr)
{
if(ptr!=NULL)
{
inorder(ptr->left);
printf("%d",-ptr->data);
inorder(ptr->right);
}
}
void preorder(struct node *ptr)
{
if(ptr!=NULL)
{
printf("%d",-ptr->data);
preorder(ptr->left);
preorder(ptr->right);
}
}
void postorder(struct node *ptr)
{
if(ptr!=NULL)
{
postorder(ptr->left);
postorder(ptr->right);
printf("%d",-ptr->data);
}
}

void search(struct node *ptr)
{
int data,flag=0;
if(ptr==NULL)
printf("\n empty tree");
else
{
printf("enter the element to be searched:");
scanf("%d",&data);
while(ptr!=NULL)
{
if(data==ptr->data)
{
printf("\n element found");
ptr=NULL;
flag=1;
}
else if(data>ptr->data)
ptr=ptr->right;
else
ptr=ptr->left;
}
if(flag==0)
printf("\n element is not found");
}
}
void deletion(int x)
{
int data;
printf("\nenter the number to be deleted:");
scanf("%d",&x);
if(root==NULL)
{
printf("\n tree is empty");
}
else
{
parent=NULL;
ptr=root;
while(ptr!=NULL)
{
if(ptr->data==x)
break;
parent=ptr;
if(x>ptr->data)
{
ptr=ptr->right;
}
else
{
ptr=ptr->left;
}	
}
if(ptr==NULL)
{
printf("item not present");
}
else{
if(ptr->right==NULL&&ptr->left==NULL)
{
if(parent==NULL)
{
root=NULL;
}
else if(parent->right==ptr)
{
parent->right=NULL;
}
else{
parent->left=NULL;
}
printf("element deleted");
free(ptr);			
}
else if(ptr->right!=NULL && ptr->left!=NULL)
{
p=ptr->right;
while(p->left!=NULL)
{
p=p->left;
}
data=p->data;
deletion(p->data);
ptr->data=data;
}
else if(ptr->right!=NULL && ptr->left==NULL || ptr->right==NULL && ptr->left!=NULL)
{
if(parent==NULL)
{
if(ptr->right==NULL)
{
root=ptr->left;
}
else
{
root=ptr->right;
}
}
else
{
if(parent->right==ptr)
{
if(ptr->right==NULL)
parent->left=ptr->left;
else
parent->right=ptr->right;
}
else
{
if(ptr->left==NULL)
parent->left=ptr->right;
else
parent->left=ptr->left;
}
}
printf("element deleted");
free(ptr);
}
}
}
}
