#include<stdio.h>
#include<string.h>
char alpha[20]={0};
char beta[20]={0};
char gram[30]={0};
int i=0,j=0,k=0;
void addToBeta(char);
void addToAlpha(char);
void ELR()
{
for(i=0;gram[i]!='\0';i++)
if(gram[i]=='>')
break;
for(i=i+1;gram[i]!='\0';i++)
{
if(gram[i]==gram[0])
{
for(i=i+1;gram[i]!='\0'&&gram[i]!='|';i++)
addToAlpha(gram[i]);
addToAlpha(';');
}
else
{
for(;gram[i]!='\0'&&gram[i]!='|';i++)
addToBeta(gram[i]);
addToBeta(';');
}
}
alpha[j]='\0';
beta[j]='\0';
}
void addToAlpha(char ch)
{
alpha[j]=ch;
j++;
}
void addToBeta(char ch)
{
beta[k]=ch;
k++;
}
int main()
{
printf("\n enter the grammer:\n");
scanf("%s",gram);
ELR();
if(strlen(alpha)==0)
{
printf("\nThe grammer is not left recursive");
return 0;
}
else
{
printf("\nThe grammer after eliminating left recursion is:\n");
printf("\n%c->",gram[0]);
for(i=0;beta[i+1]!='\0';i++)
{
if(beta[i]==';')
printf("X|");
else 
printf("%c",beta[i]);
}
printf("X");
printf("\nX->");
for(i=0;alpha[i+1]!='\0';i++)
{
if(alpha[i]==';')
printf("X|");
else
printf("%c",alpha[i]);
}
printf("X|%c",238); 
return 0;
}
}
