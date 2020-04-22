#include<stdio.h>
void E();
void E1();
void T();
void T1();
void F();
void match(char);
int flag=1;
char ch,t;
int main()
{
printf("The grammar is \n");
printf("E-->E+T\nT-->T*F|F\nF-->i\n");
printf("The elimination of left recursion is needed for implementing recursive descent parser\n");
printf("The grammar after elimination of left recursion is \n");
printf("E-->TE\nE-->+TE'|%c\nT-->*FT'|%c\nF-->i\n","epselon","epselon");
printf("enter input string and the end string with $\n");
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
T();
E1();
}
void E1()
{
if(ch=='+')
{
match('+');
T();
E1();
}
else
return;
}
void T()
{
F();
T1();
}
void T1()
{
if(ch=='*')
{
match('*');
F();
T1();
}
else
return;
}
void F()
{
match('i');
}
