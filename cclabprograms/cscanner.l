%{
#include<stdio.h>
int lineno=1;
%}
letter [a-zA-z]
digit [0-9]
id {letter}({letter}|{digit})*
num {digit}+
kw "int"|"char"|"float"|"printf"|"main"|"if"|"elseif"|"then"|"void"
rop ">"|"<="|">="|"<"
aop "+"|"-"|"*"|"/"
arr ({id}"["{num}"]")
pre "#include"|"#define"
par "["|"]"|"("|")"|"{"|"}"
com ("/*"({id}|"\n")*"*/")
ws [.,;"]
%%
[\n] {lineno++;}
{ws} {printf("\nspecial symbols=%s\t\tlineno=%d",yytext,lineno);}
{rop} {printf("\nrelational operator=%s\t\tlineno=%d",yytext,lineno);}
"=" {printf("\nassignment operator=%s\t\tlineno=%d",yytext,lineno);}
{aop} {printf("arithmetic operator+%s\t\tlineno=%d",yytext,lineno);}
{par} {printf("\nparanthesis=%s\t\tlineno=%d",yytext,lineno);}
{pre} {printf("\npreprocessor=%s\t\tlineno=%d",yytext,lineno);}
{kw} {printf("\nkeyword=%s\t\tlineno=%d",yytext,lineno);}
{arr} {printf("\narrays=%s\t\tlineno=%d",yytext,lineno);}
{id} {printf("\nidentifier=%s\t\tlineno=%d",yytext,lineno);}
{num} {printf("\nnumber=%s\t\tlineno=%d",yytext,lineno);}
\"[^\"\n]*\" {printf("\ncontrol string=%s\t\tlineno=%d",yytext,lineno);}
%%
int main(int argc,char* argv[])
{
if(argc>1)
yyin=fopen(argv[1],"r");
else
yyin=stdin;
yylex();
}
yywrap()
{
printf("\n");
exit(0);
}

