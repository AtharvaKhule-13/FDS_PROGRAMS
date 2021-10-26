#include <stdio.h>

int main() 
{
  int a,b;
  printf("Enter the interval for which all prime numbers should be printed\n");
  scanf("%d%d",&a,&b);
  for(int i=a+1;i<b;i++)
  {
    int c=0;
    for(int j=1;j<=i;j++)
    {
      if(i%j==0)
      c=c+1;
    }
    if(c==2)
    printf("%d\n",i);
  }
  return 0;
}