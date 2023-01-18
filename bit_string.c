#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void union_bs(char[],char[], char[]);
void intersect_bs(char[],char[], char[]);
void diff_bs(char[],char[], char[]);
void equal_len(char[],char[]);

char s1[20],s2[20],s3[20];

void main(){

int ch;
printf("\n Enter string1 : ");
scanf("%s",s1);
printf("\n Enter string2 : ");
scanf("%s",s2);
do{
printf("\n Bit String Operations...\n\t 1.Union \n\t 2.Intersection \n\t 3.Difference \n\t 4.Exit");
printf("\n Enter your choice(1-4):");
scanf("%d",&ch);
switch(ch){

case 1: union_bs(s1,s2,s3);
printf("\n Union of %s and %s : %s",s1,s2,s3);
break;
case 2: intersect_bs(s1,s2,s3);
printf("\n Intersection of %s and %s : %s",s1,s2,s3);
break;
case 3: diff_bs(s1,s2,s3);
printf("\n Difference of %s and %s : %s",s1,s2,s3);
break;
case 4: exit;
break;
default: printf("\n Invalid choice!!");
}
}while(ch!=4);
}

void union_bs(char s1[],char s2[], char s3[]){

int i,l1,l2;
l1=strlen(s1);
l2=strlen(s2);
if(l1>l2 || l2>l1)
equal_len(s1,s2);
for(i=0;i<strlen(s1);i++){

if(s1[i]=='0' && s2[i]=='0')
s3[i]='0';
else
s3[i]='1';
}
s3[i]='\0';

}

void intersect_bs(char s1[],char s2[], char s3[]){

int i,l1,l2;
l1=strlen(s1);
l2=strlen(s2);
if(l1>l2 || l2>l1)
equal_len(s1,s2);
for(i=0;i<strlen(s1);i++){

if(s1[i]=='1' && s2[i]=='1')
s3[i]='1';
else
s3[i]='0';
}
s3[i]='\0';

}

void diff_bs(char s1[],char s2[], char s3[]){

int i,l1,l2;
l1=strlen(s1);
l2=strlen(s2);
if(l1>l2 || l2>l1)
equal_len(s1,s2);
for(i=0;i<strlen(s1);i++){

if(s1[i]=='1' && s2[i]=='0')
s3[i]='1';
else
s3[i]='0';
}
s3[i]='\0';

}

void equal_len(char s1[],char s2[]){
int i,l1,l2;
char str[20];
l1=strlen(s1);
l2=strlen(s2);

if (l1 > l2){
for(i=0;i<l1-l2;i++){
str[i]='0';
}
str[i]='\0';
strcat(str,s2);
strcpy(s2,str);
}
else{
for(i=0;i<l2-l1;i++){
str[i]='0';
}
str[i]='\0';
strcat(str,s1);
strcpy(s1,str);
}
}
