opr [*+-/=]
%%
[\t]. {}
[a-zA-Z]* {sscanf(yytext,"%c",&yylval);return id;}
[\n] {return(yytext[0]);}
{opr} {return(yytext[0]);}
%%
yywrap()
{
return 1;
}
