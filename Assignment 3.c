#include<stdio.h>
int main()
{
 int a[10][3],b[10][3],c[10][3],r1,c1,v1,r2,c2,v2,k=1;
 int choice;
 int count=0;
 printf("1)addition of two matrix\n2)transpose of matrix\nenter ur choice:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
printf("enter no of rows,columns and values of matrix 1\n");
 scanf("%d%d%d",&r1,&c1,&v1);
 a[0][0]=r1;
 a[0][1]=c1;
 a[0][2]=v1;
 printf("----MATRIX_1----\n");
 printf("ROW\tCOLUMN\tVALUE\n");
 for(int i=1;i<=v1;i++)
 {
 scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
 }

printf("enter no of rows ,columns and values of matrix 2\n");
 scanf("%d%d%d",&r2,&c2,&v2);
 b[0][0]=r2;
 b[0][1]=c2;
 b[0][2]=v2;
printf("----MATRIX_2----\n");
 printf("ROW\tCOLUMN\tVALUE\n");
 for(int i=1;i<=v2;i++)
 {
scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
 }
if(r1!=r2 || c1!=c2)
 {
 printf("addition is not possible");
 }
else
 {
 for(int i=1,j=1;i<=v1||j<=v2;)
 { count++;
 if(a[i][0]>b[j][0])
 {
 c[k][0]=b[j][0];
 c[k][1]=b[j][1];
 c[k][2]=b[j][2];
 j++,k++;
 }
 else if(a[i][0]<b[j][0])
 {
 c[k][0]=a[i][0];
 c[k][1]=a[i][1];
 c[k][2]=a[i][2];
 i++,k++;
 }
 else if(a[i][1]>b[j][1])
 {
 c[k][0]=b[j][0];
 c[k][1]=b[j][1];
 c[k][2]=b[j][2];
 j++,k++;
 }
 else if(a[i][1]<b[j][1])
 {
 c[k][0]=a[i][0];
 c[k][1]=a[i][1];
 c[k][2]=a[i][2];
 i++,k++;
 }
 else
 {
 c[k][0]=a[i][0];
 c[k][1]=a[i][1];
 c[k][2]=a[i][2]+b[j][2];
 i++,j++,k++;
 }
}
}
printf("sum of 2 sparse matrix is :\n");
printf("ROW\tCOLUMN\tVALUE\n");
for(int i=0;i<k;i++)
{
printf("%d\t\t%d\t\t%d\n",c[i][0],c[i][1],c[i][2]);
}
case 2:
printf("enter no of rows,columns and values of matrix 1\n");
 scanf("%d%d%d",&r1,&c1,&v1);
 a[0][0]=r1;
 a[0][1]=c1;
 a[0][2]=v1;
 printf("----MATRIX_1----\n");
 printf("ROW\tCOLUMN\tVALUE\n");
 for(int i=1;i<=v1;i++)
 {
 scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
 }
b[0][0]=c1;
b[0][1]=r1;
b[0][2]=v1;
for(int i=0;i<c1;i++)
{
 for(int j=0;j<=v1;j++)
 {
 if(i==a[j][1])
 {b[k][0]=i;
 b[k][1]=a[j][0];
 b[k][2]=a[j][2];
 k++;
 }
 }
}
printf("transpose matrix:\n");
printf("ROW\tCOLUMN\tVALUE\n");
for(int i=1;i<=v1;i++)
{
 printf("%d\t%d\t%d\t\n",b[i][0],b[i][1],b[i][2]);
}
 }
}