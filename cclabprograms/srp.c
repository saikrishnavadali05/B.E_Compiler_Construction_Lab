#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct stack
{
char a[50];
int top;
}s;
char instring[50];
int isoperator(char c)
{
if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%')
return 1;
else
return 0;
}
void shift_red()
{
char str[30];
char *ptr=instring;
int i,j;
while(*ptr!='$')
{
s.top++;
s.a[s.top]=*ptr++;
for(i=0;i<s.top;i++)
str[i]=s.a[i];
str[i]='\0';
printf("%s\t\t%s\t\t%s\n",str,ptr,"shift");
if(isalpha(s.a[s.top]))
{
s.a[s.top]='E';
for(i=0;i<s.top;i++)
str[i]=s.a[i];
str[i]='\0';
printf("%s\t\t%s\t\t%s\n",str,ptr,"reduce");
}
}
if(s.top==1&&s.a[s.top]=='E')
{
printf("%s\t\t%s\t\t%s\n","$E","$","accept");
printf("\nsuccessful\n");
return;
}
if(s.top<3||(s.top==1&&s.a[s.top]!='E'))
goto e1;
for(i=s.top;i>=3;i--)
{
if(i==s.top&&s.a[i]=='E')
{
f2:
if(isoperator(s.a[i]))
{
i=i-2;
f1:
switch(s.a[i])
{
case')':if(s.a[i-1]==')')
{
i=i-1;
goto f1;
}
else if(s.a[i-1]=='E')
{
i=i-1;
if(s.a[i-1]=='(')
{
s.a[i-1]='E';
for(j=i;j<=s.top-2;j++)
s.a[i]=s.a[j+2];
s.top=s.top-2;
for(j=0;j<=s.top;j++)
str[j]=s.a[i];
str[j]='\0';
if(s.a[s.top]=='E'&&s.top==1)
{
printf("%s\t\t%s\t\t%s\n",str,ptr,"accept");
printf("\nsuccessful\n");
return;
}
else
printf("%s\t\t%s\t\t%s\n",str,ptr,"reduce");
}
else
goto f2;
}
else
{
e1:
for(j=0;j<=s.top;j++)
str[j]=s.a[i];
str[j]='\0';
printf("%s\t\t%s\t\t%s\n",str,ptr,"error");
printf("\nUnsuccessful\n");
return;
}
i=s.top+1;
break;
case'E':s.a[i]='E';
for(j=i+1;j<s.top-2;j++)
s.a[j]=s.a[j+2];
s.top=s.top-2;
for(j=0;j<s.top;j++)
str[j]=s.a[j];
str[j]='\0';
if(s.a[s.top]=='E'&&s.top==1)
{
printf("%s\t\t%s\t\t%s\n",str,ptr,"accept");
printf("\nSuccessful\n");
return;
}
else
printf("%s\t\t%s\t\t%s\n",str,ptr,"reduce");
i=s.top+1;
break;
}
if(i==3)
goto e1;
}
else
goto e1;
}
else if(i==s.top&&s.a[i]==')')
goto f1;
}
}
int main()
{
s.top=0;
s.a[s.top]='$';
printf("\n\nSHIFT REDUCE PARSING\n");
printf("\n");
puts("\nE->E+E\nE->E-E\nE->E*E\nE->(E)\nE->E/E\nE->i\n");
printf("enter the string to be parsed: ");
scanf("%s",instring);
strcat(instring,"$");
printf("stack\t\tbuffer\t\toperation\n");
shift_red();
return 0;
}




