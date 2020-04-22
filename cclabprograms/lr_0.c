#include<stdio.h>
#include<string.h>
main()
{
char A[10][10],items[20][20]={},ll[20][20],inputs[20][20];

int i,j,k,l=0,m=0,p=3,n=0,ilen[10],numi;
int B[10][10];
char c,ch;
int flag=0,numprods,temp,temp1,q;
printf("Enter the no of productions\n");
scanf("%d",&numprods);
printf("Enter productions: \n");
for(i=0;i<=numprods;i++)
{
gets(A[i]);
}
for(i=0;i<=numprods;i++)
{
n=strlen(A[i]);
for(j=0;j<(n-2);j++)
{
for(k=0;k<=strlen(A[i]);k++)
{
if(p==k)
{
items[l][m]='.';
m++;
items[l][m]=A[i][k];
m++;
}
else
{
items[l][m++]=A[i][k];
}
}
l++;
p++;
m=0;
}
p=3;
}
i=0;
printf("items are: \n");
while(l!=i)
{
printf("%d)",i);
puts(items[i]);
printf("\n");
i++;
}
}
