# Compiladores

Son traductores o interpretes, que producen un resultado.

El alfabeto es un conjunto de glifos, separado por delimitadores y  agrupados
en *tokens*.

token    tkn    tk
|int| -> |x| -> |;|
tipo     nmbr   ;

Pasos del compilador
0) Pre-procesador: funciona a nivel de texto.
1) Analisis lexico o scanner, genera una lista de tokens.
2) Analizador sintactico o parser, genera un arbol sintactico.
3) Analisis semantico, genera un arbol sintactico anotado.
4) Generar codigo destino.
n) Optimizador de codigo, genera codigo optimizado.

"literal"

c = a + b;

______________
|     =       |
|  c     +    |
|      a   b  |
_______________

Involucrados en el proceso
- Tabla de simbolos
- Tabla de literales
- Generador de Errores
- Gramatica del lenguaje

