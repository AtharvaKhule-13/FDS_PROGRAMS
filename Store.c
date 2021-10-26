#include <stdio.h>
struct bill
  {
    char Product_Code[100];
    float price;
    char Product_Name[100];
  }b1;

int main() 
{
  printf("Enter product name:");
  scanf("%s",b1.Product_Name);
  printf("Enter product code:");
  scanf("%s",b1.Product_Code);
  printf("Enter product price:");
  scanf("%f",&b1.price);
  printf("\n");

  printf("********BILL**********\n");
  printf("Product='%s'\n",b1.Product_Name);
  printf("Code='%s'\n",b1.Product_Code);
  printf("Price='%f'\n",b1.price);
  return 0;
}