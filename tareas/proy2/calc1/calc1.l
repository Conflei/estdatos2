/* calculator #1 */
%{
    #include "y.tab.h"
    #include <stdlib.h>
    extern int yylval;
    void yyerror(char *);
%}

%%

[0-9]+      {
                yylval = atoi(yytext);
                return ENTERO;
            }

[-+\n]        { return *yytext; }

"mas"         { return SUMATORIA; }

"por"         { return *yytext; }

"a la"        { return *yytext; }

"raiz de"     { return *yytext; }

"al cuadrado" {return *yytext; }

"al cubo"     {return *yytext; }

[ \t]       ;       /* skip whitespace */

.           yyerror("Error de sintaxis.");

%%

int yywrap(void) {
    return 1;
}
