%{
#include<stdio.h>
int wc=0,lc=0,cc=0;
%}
word [^\n\n]+
eol \n
%%
{word} {wc++;cc+=yyleng;}
{eol} {lc++;cc++;}
. {cc++;}
%%
main(int argc,char**argv)
{
if(argc>1)
{
FILE*file;
file=fopen(argv[1],"r");
if(!file)
{
fprintf(stderr,"could not open%s\n",argv[1]);
exit(1);
}
yyin=file;
}
yylex();
printf("no of characters %d\nno of lines %d\nno of words %d\n",cc,lc,wc);
return 0;
}
