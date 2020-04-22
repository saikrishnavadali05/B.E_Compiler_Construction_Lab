%{
#include<stdio.h>
int wc=0,lc=0,cc=0;
%}
word [^\n\t]+
eol \n
%%
{word} {wc++;cc+=yyleng;}
{eol} {lc++;cc++;}
. {cc++;}
%%
main()
{
yylex();
printf("no. of characters:%d\nno. of words:%d\nno. of lines:%d\n",cc,wc,lc);
}
