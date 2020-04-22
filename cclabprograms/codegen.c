#include<stdio.h>
int main()
{
int i=0,ch,k=3;
char a[100];
printf("\nEnter a string: ");
scanf("%s",a);
printf("\n1.single address\n2.Double address\n");
printf("Enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nLOAD %c\n",a[2]);
while(a[i]!='\0')
{
if(a[i+3]=='+')
printf("\nADD %c\n",a[i+4]);
else
if(a[i+3]=='-')
printf("\nSUB %c\n",a[i+4]);
else
if(a[i+3]=='*')
printf("\nMUL %c\n",a[i+4]);
else
if(a[i+3]=='/')
printf("\nDIV %c\n",a[i+4]);
i=i+2;
}
printf("\nSTORE %c\n",a[0]);
break;
case 2:
while(a[k]!='\0')
{
if(a[k]=='+')
printf("\nADD %c %c\n",a[2],a[k+1]);
else if(a[k]=='-')
printf("\nSUB %c %c\n",a[2],a[k+1]);
else if(a[k]=='*')
printf("\nMUL %c %c\n",a[2],a[k+1]);
else if(a[k]=='/')
printf("\nDIV %c %c\n",a[2],a[k+1]);
k=k+2;
}
if(a[1]=='=')
printf("\nMOV %c %c\n",a[0],a[2]);
break;
}
}
