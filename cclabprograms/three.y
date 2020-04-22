%{
#include<stdio.h>
#include<ctype.h>
int i;
%}
%token id
%%
L:id'='E '\n' {printf("%c=%c\n",$1,$3);}
|
;
E:E'+'T {$$='p'; printf("%c=%c+%c\n",$$,$1,$3);}
|E'-'T {$$='r'; printf("%c=%c-%c\n",$$,$1,$3);}
|T
;
T:T'*'F {$$='q'; printf("%c=%c*%c\n",$$,$1,$3);}
|T'/'F {$$='s'; printf("%c=%c/%c\n",$$,$1,$3);}
|F
;
F:'-'G {$$='t'; printf("%c=-%c\n",$$,$2);}
|G
;
G:id{$$=$1;}
;
%%
#include"lex.yy.c"
main()
{
printf("Three Address Code is: \n");
yyparse();
}
void yyerror(char *s)
{
printf("\nerror\n");
}


