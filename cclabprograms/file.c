#include<stdio.h>
void main()
{
char a[100];
int i;
printf("Enter a statement\n");
gets(a);
for(i=0;a[i]!='\0';i++)
{
if((a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'))
{
printf("\n %c is a variable\n",a[i]);
}
else if(a[i]=='=')
{
printf("\n= is an assignment operator\n");
}
else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
{
printf("\n %c is an arithmetic operator\n",a[i]);
}
else if(a[i]>='0'&&a[i]<='9')
{
printf(" %c is a number\n",a[i]);
}
else
printf("%c is other symbol\n",a[i]);
}
}
