#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
int i,j,k,l,m,x=0;
char* c[10]={"stdio","include","return","void","scanf","printf","else","int","if","break"};
char lit[100],temp[100]={0},str[20],dir[7];
FILE *fp;
fp=fopen("test.c","r");
printf("\n\n\n");
printf("lexeme\tttoken\t\t\t\tline on\n");
printf("---\t\t---\t\t\t---\n");
for(l=1;!feof(fp);l++)
 { 
	fgets(temp,100,fp);
	for(i=0;temp[i]!='\0';)
	{
		if(temp[i]==' ')
		i++;
			if(temp[i]=='#')
			{
				while(x<=6)
				{
					dir[x]=temp[1+i+x];
					x++;
				}
				dir[x]='\0';
				if(strcmp(dir,"include")==0)
				{
					printf("%s\tpreprocessor\t\t%d\n","#include",l);
					i=i+8;
				}
				x=0;
			}
			else
			if(temp[i]=='\n') temp[i]='\0';
			else	if(isalpha(temp[i]))
					{
						j=0;
						while(isalnum(temp[i]))
						{
							str[j]=temp[i];
							j++;
							i++;
						}
						str[j]='\0';
						for(k=0;k<=9;k++)
						{
							if(!strcmp(c[k],str))
							break;
						}
						if(k==5)
						{
							j=0;
							printf("%s\t\tkeyword\t\t%d\n",str,l);
							printf("%c\t\tparanthesis \t\t%d\n",temp[i++],l);
							if(temp[i]=='"')
							{
								lit[j++]=temp[i];
								i++;
								while(temp[i]!='"')
								{
									lit[j]=temp[i];
									i++;j++;
								}
								lit[j++]=temp[i++];
								lit[j]='\0';
								printf("%s\t\tstring \t\t%d\n",lit,l);
							}
						}
						else if(k==10) printf("%s\t\tidentifier\t\t%d\n",str,l);
						else printf("%s\t\tkeyword\t\t\t%d\n",str,l);
					}
					else if(isdigit(temp[i]))
					{
						j=0;
						while(isdigit(temp[i]))
						{
							str[j]=temp[i];
							j++;
							i++;
						}
						str[j]='\0';
						printf("%s\t\tkey constant\t\t%d\n",str,l);
					}
					else
					{
						j=0;
						str[j]=temp[i];
						j++;
						switch(temp[i])
						{
							case'+':
							case'-':
							case'*':
							case'/':
							case'=':
							case'>':
							case'<':
								str[j]='\0';
							printf("%s\t\toperator\t\t%d\n",str,l);
								j=0;
								i++;
								break;
							case'(':
							case')':
							case'{':
							case'}':
									{
										str[j]='\0';
										printf("%s\t\tparanthesis\t\t%d\n",str,l);
										j=0;
										i++;
										break;
									}
							case';':
									{
										str[j]='\0';
										printf("%s\t\tpunct symbol\t\t%d\n",str,l);
										j=0;
										i++;	
										break;
									}
							default:
									{
										str[j]='\0';
										j=0;
										i++;
										printf("%s\t\tspecial symbol\t\t%d\n",str,l);
									}
					    }
							
							
					}
	}
 
 }
	
	return 0;
}



