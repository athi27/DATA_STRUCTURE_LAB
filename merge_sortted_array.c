
//Program to merge 2 sorted arrays.
#include<stdio.h>
void main(){
 
 int arr1[10],arr2[10],merged_arr[20],i,j,k,n1,n2;
 //Enter elements to 1st and 2nd sorted array
 printf("Enter the no.of elements to be entered into the 1st array:");
 scanf("%d",&n1);
 printf("Enter the sorted array 1: \n");
 for (i=0;i<n1;i++){
   scanf("%d",&arr1[i]);
 }

 printf("Enter the no.of elements to be entered into the 2nd array:");
 scanf("%d",&n2);
 printf("Enter the sorted array 2: \n");
 for (j=0;j<n2;j++){
   scanf("%d",&arr2[j]);
 }
 //Merge the sorted arrays into a sorted array
 i=j=k=0;
 while (i< n1 && j< n2){
  if(arr1[i] < arr2[j]){
    merged_arr[k] = arr1[i];
    i++;
  }
  else if(arr1[i] > arr2[j]){
    merged_arr[k] = arr2[j];
    j++;
  }
  else{
   merged_arr[k]= arr1[i];
   i++;
   j++;
  }
  k++;  
 }
 while(i < n1){
   merged_arr[k] = arr1[i];
   k++;
   i++;
 }
 while(j < n2){
   merged_arr[k] = arr2[j];
   k++;
   j++;
 }

 //Print the merged sorted array.
 printf("Merged sorted array : \n");
 for (i=0;i<k;i++)
   printf("%d \n",merged_arr[i]);
}
