/* calculator #1 */
%{
    #include <stdlib.h>
    #include "y.tab.h"
    extern int yylval;
    void yyerror(char *);
%}

%%

[0-9]+        {
                yylval = atoi(yytext);
                return ENTERO;
              }

[-+\n]        { return *yytext; }

"por"         { return *yytext; }

"raiz de"     { return *yytext; }

"a la"        { return POTENCIA; }


[ \t]       ;       /* skip whitespace */

.           yyerror("Error de sintaxis.");

%%

int yywrap(void) {
    return 1;
}
