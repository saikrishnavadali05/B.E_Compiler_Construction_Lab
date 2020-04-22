#include<stdio.h>
#define max 20
static int r=0;
int top=-1;
char st[max];
int main()
{
int h;
char ip[10];
printf("\nEnter the postfix expression: ");
scanf("%s",ip);
h=0;
while(ip[h]!='\0')
{
while(islower(ip[h])!=0)
{
push(ip[h]);
h++;
}
getregister();
printf("\nload %c R%d\n",st[top-1],r);
switch(ip[h])
{
case '+':
{
printf("\nadd %c R%d\n",st[top],r);
empty();
h++;
}
break;
case '-':
{
printf("\nsub %c R%d\n",st[top],r);
empty();
h++;
}
break;
case '*':
{
printf("\nmul %c R%d\n",st[top],r);
empty();
h++;
}
break;
case '/':
{
printf("\ndiv %c R%D\n",st[top],r);
empty();
h++;
}
break;
default:
printf("\n Invalid choice");
}
}
return 0;
}
empty()
{
char t1;
pop();
pop();
printf("\n st R%d i\n",r);
t1='t';
push(t1);
}
getregister()
{
r++;
if(r>2)
r=1;
}
push(int x)
{
if(top==max-1)
printf("\n Stack full\n");
else
{
top++;
st[top]=x;
}
}
pop()
{
if(top==-1)
printf("\nstack empty\n");
else
top--;
}
