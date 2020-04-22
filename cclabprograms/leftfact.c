#include<stdio.h>
#include<string.h>
char a[30];
char b[30];
char g[30];
char gr[30];
char p1[30];
char p2[30];
char gam[30];
void left()
{
int i=0,j=0,k=0,l=0,m=0,len2;
while(gr[i]!='>')
i++;
for(i=i+1;gr[i]!='|';i++)
p1[j++]=gr[i];
p1[j]='\0';
j=0;
for(i=i+1;gr[i]!='\0';i++)
p2[j++]=gr[i];
p2[j]='\0';
l=strlen(p2);
for(i=0;p2[i]!='\0';i++)
if(p2[i]=='|')
break;
if(i<l)
{
printf("Gamma part is there\n");
j=0;
for(m=0;m<i;m++)
p2[j++]=p2[m];
p2[j]='\0';
j=0;
for(m=i+1;m<l;m++)
gam[j++]=p2[m];
gam[j]='\0';
printf("Gamma part is %s\n",gam);
}
else
printf("Gamma part is not there\n");
while(p1[k]==p2[k])
k++;
j=0;
for(i=0;i<k;i++)
a[j++]=p2[i];
a[j]='\0';
j=0;
for(i=k;p1[i]!='\0';i++)
b[j++]=p1[i];
b[j]='\0';
j=0;
for(i=k;p2[i]!='\0';i++)
g[j++]=p2[i];
g[j]='\0';
}
int main()
{
int len;
printf("\nEnter the grammar with almost three productions where only the first two productions have a common prefix: \n");
scanf("%s",gr);
left();
len=strlen(gam);
printf("left factored grammar is: \n");
if(len)
printf("%c->%sX|%s\n",gr[0],a,gam);
else
printf("%c->%sX\n",gr[0],a);
printf("X->%s|%s\n",b,g);
return 0;
}
