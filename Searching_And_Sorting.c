#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct cricket
{
char name[100];
int age;
char country[50];
char category[10];
int odi, t20;
float avgscore;
int wickets;
}p[50],temp;
int i=0;
void getdata(struct cricket p[]);
void sort_avgscore(struct cricket p[]);
void max_wicket(struct cricket p[]);
void player_country(struct cricket p[],char category[]);
void entire_info(struct cricket p[],char info[]);
int main(int argc, char const *argv[])
{
int n;
int operation;
char player[25];
// struct cricket c[50];
// printf("Enter the number of players to recieve data\n");
// scanf("%d", &n);
do
{
printf("\nEnter an operation\n");
printf("\n1.Accept Data\n2.Batsmen of a particular
country\n3.Batsman with highest average score\n4.Bowlers of particularcountry\n5.Bowler with maximum wickets\n6.Display board information of a
particular player\n7.Quit\n");
scanf("%d", &operation);
switch (operation)
{
case 1:
// printf("Enter information of batsmen");
getdata(p);
break;
case 2:
player_country(p,"batsman");
break;
case 3:
sort_avgscore(p);
// total_info(c, n);
break;
case 4:
player_country(p,"bowler");
break;
case 5:
max_wicket(p);
break;
case 6:
printf("Enter the name of player to show his entire information:
");
scanf("%s",player);
entire_info(p,player);
break;
default:
printf("Incorrect input\n");
break;
}
}while(operation!=7);
printf("THANK YOU");
return 0;
}
void getdata(struct cricket p[50]){
while(1){
printf("Enter information of player %d (Enter 0 in age to stop
accepting):-",i+1);
printf("\nEnter age of cricketer: ");
scanf("%d", &p[i].age);
if(p[i].age==0)
break;
printf("Enter name of cricketer: ");
scanf("%s",p[i].name);
printf("Which country does player belongs to: ");
scanf("%s", p[i].country);
printf("What is category of the player:\n\nBatsman\tBowler\tWicket
Keeper\tAll-rounder\n");
scanf("%s", p[i].category);
printf("Enter the number of matches played in each category \n");
printf("ODI: ");
scanf("%d", &p[i].odi);
printf("T20: ");
scanf("%d", &p[i].t20);
printf("Enter average score of player: ");
scanf("%f", &p[i].avgscore);
printf("Enter wickets taken by bowler: ");
scanf("%d",&p[i].wickets);
i++;
}
}
void player_country(struct cricket p[],char category[]){
char country[20];
printf("Enter the country of player:");
scanf("%s",country);
int count=0;
for(int j=0;j<i;j++)
{
if(strcmp(country,p[j].country)==0&&strcmp(category,p[j].category)==0){
printf("\nName: %s",p[j].name);
count++;
}
}
printf("\nNumber of %s from %s are %d",category,country,count);
}
void sort_avgscore(struct cricket p[]){
for(int j=0;j<i-1;j++){
for (int k = 0; k < i-j-1; k++)
if(p[k].avgscore>p[k+1].avgscore){
temp=p[k];
p[k]=p[k+1];
p[k+1]=temp;
} // if (p[k] > [k+1])
}
for(int j=i-1;j>=0;j--){
printf("Name:%s || Average Score: %f\n",p[j].name,p[j].avgscore);
}
}
void max_wicket(struct cricket p[]){
int max=-1,maxi=0;
for(int j=0;j<i;j++){
if(max>p[j].wickets){
max=p[j].wickets;
maxi=i;
}
}
printf("\nBowler with maximum wickets is %s with %d
wickets\n",p[maxi].name,p[maxi].wickets);
}
void entire_info(struct cricket p[],char info[]){
int in=-1;
printf("%s**",info);
for(int j=0;j<i;j++){
if(strcmp(info,p[j].name)==0){
in=j;
}
}
printf("%d",in);
if(in==-1){
printf("No such player exists\n");
}
else{
printf("\nEntire info of player:=\n");
printf("Name:%s\tAge:%d\t\t\tCountry:%s\nCategory:%s\nMatches
played:\t\t\tODI:%d\t\tT20:%d\nAveraege
Score:%.2f\nWickets:%d",p[in].name,p[in].age,p[in].country,p[in].category,
p[in].odi,p[in].t20,p[in].avgscore,p[in].wickets);
}
}
