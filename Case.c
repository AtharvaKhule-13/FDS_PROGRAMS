#include <string.h>
int main()
{
    char str[100];   
    printf("Enter  the string : ");
    gets(str);         
    for(int i=0;str[i];i++)  
    {
        if(str[i]>=65 && str[i]<=90)
         str[i]+=32;
        else if(str[i]>=97 && str[i]<=122)
         str[i]-=32;
 	}
 	
     
    printf("string in togglecase ='%s'\n",str);
 
 
    return 0;
}