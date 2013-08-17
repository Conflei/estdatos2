bison -y -d calc1.y && flex calc1.l && gcc -c y.tab.c lex.yy.c && gcc y.tab.o lex.yy.o && ./a.out

rm a.out && rm lex.yy.o y.tab.o && rm lex.yy.c y.tab.c && rm y.tab.h
