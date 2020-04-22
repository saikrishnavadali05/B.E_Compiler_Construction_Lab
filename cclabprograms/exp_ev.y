%{
#include<stdio.h>
#include<ctype.h>
#define YYSTYPE double
%}
%token NUM
%left '+''-'
%left '*''/'
%right UMINUS
%%
lines:lines expr'\n' {printf("%g\n",$2);}
|lines'\n'
|/*empty*/
;
expr:expr'+'expr {$$=$1+$3;}
|expr'-'expr {$$=$1-$3;}
|expr'*'expr {$$=$1*$3;}
|expr'/'expr {$$=$1/$3;}
|'('expr')' {$$=$2;}
|'-'expr %prec UMINUS {$$=-$2;}
|NUM
;
%%
main()
{
yyparse();
}
void yyerror(char *s)
{
printf("\nerror\n");
}
yylex()
{
char c;
while((c=getchar())==' ');
if((c=='.')||(isdigit(c)))
{
ungetc(c,stdin);
scanf("%lf",&yylval);
return NUM;
}
return c;
}
