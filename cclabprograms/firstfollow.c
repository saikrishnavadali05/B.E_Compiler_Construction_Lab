#include<stdio.h>
#include<string.h>
char S[4][4]={"Aad","Bdb","Z"};
char A[3][3]={"aAb","BBa","Z"};
char B[3][3]={"c","b","Z"};
int len=3;
int p,q,r,s;
char St[5],Sf[5];
char At[5],Af[5];
char Bt[5],Bf[5];
int z;
void disp()
{
printf("\nS->Aad|Bdb\n");
printf("A->aAb|BBa\n");
printf("B->c|b\n");
}
int term_not(char p)
{
if(p=='a'||p=='b'||p=='c'||p=='d')
return 1;
else
return 0;
}
void first(char v,char* arr)
{
int ans;
char ch;
int y;
int flag=0;
static int i,j,k;
ans=term_not(v);
if(ans==1)
{
for(y=0;y<4;y++)
{
if(arr[y]==v)
{
flag=1;
break;
}
}
if(flag!=1)
{
arr[z]=v;
z++;
}
}
else
{
ch=v;
switch(ch)
{
case 'S':
i=0;
while(strcmp(S[i],"Z")!=0)
{
first(S[i][0],arr);
i++;
}
i=0;
break;
case 'A':
j=0;
while(strcmp(A[j],"Z")!=0)
{
first(A[j][0],arr);
j++;
}
break;
case 'B':
k=0;
if(v=='B')
while(strcmp(B[k],"Z")!=0)
{
first(B[k][0],arr);
k++;
}
break;
}
}
}
void follow(char syn,char *arr)
{
if(syn=='S')
printf("$");
p=0;
while(strcmp(S[p],"Z")!=0)
{
for(q=0;q<len;q++)
{
if(S[p][q]==syn)
first(S[p][q+1],arr);
}
p++;
}
s=0;
while(strcmp(A[s],"Z")!=0)
{
for(q=0;q<len;q++)
{
if(A[s][q]==syn)
first(A[s][q+1],arr);
}
s++;
}
r=0;
while(strcmp(B[r],"Z")!=0)
{
for(q=0;q<len;q++)
{
if(B[r][q]==syn)
first(B[r][q+1],arr);
}
r++;
}
}
void first_call()
{
printf("Firsts are: \n\n");
int p;
z=0;
printf("\n");
printf("First(S): ");
first('S',St);
for(p=0;p<4;p++)
printf("%c",St[p]);
printf("\n");
printf("First(A): ");
z=0;
first('A',At);
for(p=0;p<4;p++)
printf("%c",At[p]);
printf("\n");
printf("First(B): ");
z=0;
first('B',Bt);
for(p=0;p<4;p++) 
printf("%c",Bt[p]);
printf("\n\n");
}
void follow_call()
{
printf("Follows are: \n\n");
z=0;
printf("Follow(S): ");
follow('S',Sf);
for(p=0;p<4;p++)
printf("%c",Sf[p]);
printf("\n");
z=0;
printf("\nFollow(A): ");
follow('A',Af);
for(p=0;p<4;p++)
printf("%c",Af[p]);
printf("\nFollow(b): ");
z=0;
follow('B',Bf);
for(p=0;p<4;p++)
printf("%c",Bf[p]);
printf("\n\n");
}
int main()
{
int choice;
disp();
printf("Select an option:\n 1.Firsts\n 2.Follow\n 3.exit\n");
scanf("%d",&choice);
while(choice<3)
{
if(choice==1)
first_call();
else
follow_call();
printf("Select an option:\n1.Firsts\n2.Follow\n3.exit\n");
scanf("%d",&choice);
}
}




