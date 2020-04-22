#include<stdio.h>
void E();
void T();
void match(char);
int flag=1;
char ch,t;
int main()
{
printf("The grammer is \n");
printf("E-->x+T\nT-->(E)|x\n");
printf("enter input string and end with $\n");
scanf("%c",&ch);
E();
if((ch=='$')&&(flag!=0))
printf("successful\n");
else
printf("unsuccessful\n");
}
void match(char t)
{
if(ch==t)
scanf("%c",&ch);
else
flag=0;
}
void E()
{
if(ch=='x')
match('x');
match('+');
T();
}
void T()
{
if(ch=='(')
{
match('(');
E();
match(')');
}
else
match('x');
}

