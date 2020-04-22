#include<stdio.h>
#include<string.h>
void main()
{
char str[25][50],op[25][50],forloopparam[90],righthandparam[10][40],lefthandparam[90];
int i=0,k=0,j=0,m=0,n=0,q=0,s=0,l=0;
int flag[10]={0},count[10]={0};
printf("\n input the loop to be optimised:\n");
gets(str[0]);
while(str[k][i++]!=';');
while(str[k][i++]!=';');
while(str[k][i]!=')')
{
if(isalpha(str[k][i]))
forloopparam[j++]=str[k][i];
i++;
}
i=0;
strcpy(op[l++],str[0]);
gets(str[0]);
while(str[0][i++]!='{')
strcpy(op[l++],str[0]);
k=0;
while(gets(str[k])&&str[k][0]!='}')
{
while(str[k][i++]!='=');
lefthandparam[n++]=str[k][i-2];
k++;
i=0;
}
for(m=0,i=0;m<k;m++)
{
while(str[m][i++]!='=');
while(str[m][i]!=';')
{
if(isalpha(str[m][i]))
righthandparam[m][count[m]++]=str[m][i];
i++;
}
i=0;
}
for(m=0;m<k;m++)
for(s=0;s<count[m];s++)
for(i=0;i<n;i++)
{
if(righthandparam[m][s]==forloopparam[i])
flag[m]=1;
}
printf("\n\optimised loop is\n");
for(i=0;i<1;i++)
puts(op[i]);
for(i=0;i<k;i++)
if(flag[i]==1)
puts(str[i]);
puts(str[k]);
for(i=0;i<k;i++)
if(flag[i]==0)
printf("%s\t\n",str[i]);
}


