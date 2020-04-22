%{
#include<stdio.h>
%}
%%
[\n\t];
[+-]?([0-9]+|([0-9]*\.[0-9]+)([eE][+-]?[0-9]+)?) { printf("number\n"); }
. {printf("not a number\n");}
%%
main()
{
yylex();
}
