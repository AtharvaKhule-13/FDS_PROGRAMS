#include<stdio.h>
#include<stdlib.h>
void get_element(int *arr,int m);
void display_set(int *arr,int m);
void swap(int *a, int *b);
int sort(int *arr,int n);
void intersection(int *arr,int *arr1,int m,int n);
void union__(int *arr,int *arr1,int m,int n);
void diff(int *arr,int *arr1,int m,int n);
void symmetric(int *arr,int *arr1,int m,int n);
int main()
{ int m,n;
printf("Enter No of elements of 1st set : \n");
scanf("%d",&n);
printf("Enter No of elements of 2nd set : \n");
scanf("%d",&m);
int *set1,*set2;
set1=(int*)malloc(sizeof(int)*n);
set2=(int*)malloc(sizeof(int)*m);
get_element(set1,n);
get_element(set2,m);
display_set(set1,n);
display_set(set2,m);
sort(set1, n);
sort(set2,m);
int choice;
printf("1.UNION\n");
printf("2.INtersection\n");
printf("3.difference\n");
printf("4.symmetric difference\n");
printf("Enter YOUR CHOICE : ");
scanf("%d",&choice);
switch(choice)
{
case 1: union__(set1,set2,m,n);
break;
case 2:intersection(set1,set2,m,n);
break;
case 3:
printf("\nA-B = ");
diff(set1,set2,m,n);
printf("\nB-A= ");
diff(set2,set1,n,m);
break;
case 4:
printf("\n(A-B)U(B-A) = ");
symmetric(set1,set2,m,n);
break;
}
}
void get_element(int *arr,int m)
{ printf("Enter Elements : \n");
for(int i=0;i<m;i++)
{
scanf("%d",&*(arr+i));
}
}
void display_set(int *arr,int m)
{
printf("set = { ");
for(int i=0;i<m;i++)
{
printf("%d ",*(arr+i));
}
printf("}\n");
}
void union__(int *arr,int *arr1,int m,int n)
{ int i=0,j=0,set[m+n],k=0;
while(i<n && j<m)
{
if(arr[i]<arr1[j])
{
set[k]=arr[i];
i++;
k++;
}
else if(arr[i]>arr1[j])
{
set[k]=arr1[j];
j++;
k++;
}
else if(arr[i]==arr1[j])
{
set[k]=arr[i];
i++;
j++;
k++;
}
}
while(i<n)
{
set[k]=arr[i];
k++;
i++;
}
while(j<m)
{
set[k]=arr1[j];
k++;
j++;
}
printf("\nUnion of Two sets (A U B ) : \n");
display_set(set,k);
}
void intersection(int *arr,int *arr1,int m,int n)
{
int set[m+n],k=0;
int i=0,j=0;
while(i<n && j<m)
{
if(arr[i]<arr1[j])
{
i++;
}
else if(arr[i]>arr1[j])
{
j++;
}
else if(arr[i]==arr1[j])
{
set[k]=arr[i];
i++;
j++;
k++;
}
}
printf("\nIntersection Of Two Sets: \n");
display_set(set,k);
}
void diff(int *arr,int *arr1,int m,int n)
{
int set[n],k=0,i=0,flag=0;
while(i<n)
{ flag=1;
for(int j=0;j<m;j++)
{
if(arr[i]==arr1[j])
{ flag=0;
break;
}
}
if(flag==1)
{
set[k]=arr[i];
k++;
}
i++;
}
while(i<n)
{
set[k]=arr[i];
k++;
i++;
}
display_set(set,k);
}
void symmetric(int *arr,int *arr1,int m,int n)
{
int set[n+m],k=0,i=0,flag=0;
while(i<n)
{ flag=1;
for(int j=0;j<m;j++)
{
if(arr[i]==arr1[j])
{ flag=0;
break;
}
}
if(flag==1)
{
set[k]=arr[i];
k++;
}
i++;
}
while(i<n)
{
set[k]=arr[i];
k++;
i++;
}
i=0;
while(i<m)
{ flag=1;
for(int j=0;j<m;j++)
{
if(arr1[i]==arr[j])
{ flag=0;
break;
}
}
if(flag==1)
{
set[k]=arr1[i];
k++;
}
i++;
}
while(i<m)
{
set[k]=arr1[i];
k++;
i++;
}
display_set(set,k);
}
int sort(int *arr,int n)
{
for(int i=0;i<n-1;i++)
{
for( int j=0;j<n-i-1;j++)
{
if (arr[j] > arr[j+1])
{
swap(&arr[j], &arr[j+1]);
}
}
}
return 0;
}
void swap(int *a,int *b)
{
int c;
c=*a;
*a=*b;
*b=c;
}