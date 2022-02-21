#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20
char infix[MAX], postfix[MAX], prefix[MAX];
int top = -1;
int stack[MAX];
int pop();
int precedence(char symbol);
int precedence1(char alpha);
int isEmpty();
void infix_to_postfix();
int check_space(char symbol);
void push(long int symbol);
char pop1();
char pop2();
void push1(int);
void push2(char);
void infix_to_prefix();
void postfix_to_prefix();
int isOperator(char);
void infix_to_postfix()
{
 unsigned int count, temp = 0;
 char next;
 char symbol;
 for (count = 0; count < strlen(infix); count++)
 {
 symbol = infix[count];
 if (!check_space(symbol))
 {
 switch (symbol)
 {
 case '(':
 push(symbol);
 break;
 case ')':
 while ((next = pop()) != '(')
 {
 postfix[temp++] = next;
 }
 break;
 case '+':
 case '-':
 case '*':
 case '/':
 case '%':
 case '^':
 while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
 postfix[temp++] = pop();
 push(symbol);
 break;
 default:
 postfix[temp++] = symbol;
 }
 }
 }
 while (!isEmpty())
 {
 postfix[temp++] = pop();
 }
 postfix[temp] = '\0';
}
void infix_to_prefix()
{
 int i = 0, j = 0, len;
 len = strlen(infix);
 for (i = len - 1; i >= 0; i--)
 {
 printf("%c", infix[i]);
 }
 while (infix[i] != '\0')
 {
 if (infix[i] >= 'a' && infix[i] <= 'z')
 {
 prefix[j] = infix[i];
 j++;
 i++;
 }
 else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
 {
 push(i);
 i++;
 }
 else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
 {
 if (infix[i] == '(')
 {
 while (stack[top] != ')')
 {
 prefix[j] = pop();
 j++;
 }
 pop();
 i++;
 }
 else if (infix[i] == '[')
 {
 while (stack[top] != ']')
 {
 prefix[j] = pop();
 j++;
 }
 pop();
 i++;
 }
 else if (infix[i] == '{')
 {
 while (stack[top] != '}')
 {
 prefix[j] = pop();
 j++;
 }
 pop();
 i++;
 }
 }
 else
 {
 if (top == -1)
 {
 push(i);
 i++;
 }
 else if (precedence(infix[i]) < precedence(stack[top]))
 {
 prefix[j] = pop();
 j++;
 while (precedence(stack[top]) > precedence(infix[i]))
 {
 prefix[j] = pop();
 j++;
 if (top < 0)
 {
 break;
 }
 }
 push(i);
 i++;
 }
 else if (precedence(infix[i]) >= precedence(stack[top]))
 {
 push(i);
 i++;
 }
 }
 }
 while (top != -1)
 {
 prefix[j] = pop();
 j++;
 }
 len = strlen(prefix);
 for (i = len - 1; i >= 0; i--)
 {
 printf("%c", prefix[i]);
 }
 prefix[j] = '\0';
}
void postfix_to_prefix()
{
 int i, n, j = 0;
 char c[MAX];
 char a, b, op;
 n = strlen(postfix);
 for (i = 0; i < MAX; i++)
 stack[i] = '\0';
 for (i = n - 1; i >= 0; i--)
 {
 if (isOperator(postfix[i]))
 {
 push(postfix[i]);
 }
 else
 {
 c[j++] = postfix[i];
 while ((top != -1) && (stack[top] == '#'))
 {
 a = pop();
 c[j++] = pop();
 }
 push('#');
 }
 }
 c[j] = '\0';
 i = 0;
 j = strlen(c) - 1;
 char d[20];
 while (c[i] != '\0')
 {
 d[j--] = c[i++];
 }
 printf("%s\n", d);
}
int precedence(char symbol)
{
 switch (symbol)
 {
 case '(':
 return 0;
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 case '%':
 return 2;
 case '^':
 return 3;
 default:
 return 0;
 }
}
int precedence1(char alpha)
{
 if (alpha == '+' || alpha == '-')
 {
 return (1);
 }
 if (alpha == '*' || alpha == '/')
 {
 return (2);
 }
 return 0;
}
int check_space(char symbol)
{
 if (symbol == '\t' || symbol == ' ')
 {
 return 1;
 }
 else
 {
 return 0;
 }
}
void push(long int symbol)
{
 if (top > MAX)
 {
 printf("Stack Overflow\n");
 exit(1);
 }
 top = top + 1;
 stack[top] = symbol;
}
void push1(int pos)
{
 if (top == MAX - 1)
 {
 printf("\nSTACK OVERFLOW\n");
 }
 else
 {
 top++;
 stack[top] = infix[pos];
 }
}
void push2(char c)
{
 stack[++top] = c;
}
int isEmpty()
{
 if (top == -1)
 {
 return 1;
 }
 else
 {
 return 0;
 }
}
int pop()
{
 if (isEmpty())
 {
 printf("Stack is Empty\n");
 exit(1);
 }
 return (stack[top--]);
}
char pop1()
{
 char ch;
 if (top < 0)
 {
 printf("\nSTACK UNDERFLOW\n");
 exit(0);
 }
 else
 {
 ch = stack[top];
 stack[top] = '\0';
 top--;
 return (ch);
 }
 return 0;
}
char pop2()
{
 return stack[top--];
}
int checkIfOperand(char ch)
{
 return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int isOperator(char x)
{
 switch (x)
 {
 case '+':
 case '-':
 case '/':
 case '*':
 return 1;
 }
 return 0;
}
int main()
{
 int count, length;
 char temp;
 printf("****** Expression conversion using stack ******");
 int ch = 0;
 while (ch != 4)
 {
 printf("\n\nEnter the operation to be performed\n");
 printf("\n1.Convert Infix to Postfix\n2.Convert Infix to Prefix\n3.Convert Postfix to Prefix\n4.Exit\n");
 scanf("\n%d", &ch);
 switch (ch)
 {
 case 1:
 printf("\nInput the Infix expression : ");
 scanf("%s", infix);
 infix_to_postfix();
 printf("\nEquivalent Postfix expression : %s\n", postfix);
 break;
 case 2:
 printf("\nInput the Infix expression : ");
 scanf("%s", infix);
 printf("\nEquivalent Prefix expression : %s\n", prefix);
 infix_to_prefix();
 break;
 case 3:
 printf("\nInput the postfix expression : ");
 scanf("%s", postfix);
 printf("\nEquivalent Prefix expression : %s\n", prefix);
 postfix_to_prefix();
 break;

case 4:
 exit(0);
 break;
 default:
 printf("Enter valid option");
 }
 }
}