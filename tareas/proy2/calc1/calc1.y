%{
    #include <stdio.h>
    #include <math.h>
    int yylex(void);
    void yyerror(char *);
%}

%token ENTERO
%token SUMATORIA

%%

program:
        program expr '\n'         { printf("%d\n", $2); }
        | 
        ;

expr:
        ENTERO
        | expr '+' expr           { $$ = $1 + $3; }
        | expr '-' expr           { $$ = $1 - $3; }
        | expr SUMATORIA expr     { $$ = $1 + $3; }
        | expr 'por' expr         { $$ = $1 * $3; }
        | expr 'a la' expr        { $$ = pow($1, $3); }
        | 'raiz de' expr          { $$ = sqrt($2); }
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
