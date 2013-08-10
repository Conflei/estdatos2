# Automatas y Lenguajes Formales
- Automatas de estados finitos      - Gramatica regular                     - Lenguajes regulares
- Automata de pila                  - Gramaticas libres de contexto         - Lenguajes libres de contexto
- Maquinas de Turing                - Gramaticas con estructura de frase    - Lenguajes recursivamente enumerables 

# Expresiones regulares
- Vocabulario/Alfabeto: Σ conjunto finito de simbolos. 
- Concatenacion: operacion A.B = AB
- Hilera/Fila: ω mediante la concatenacion de simbolos del vocabulario.
- Lenguaje: L conjunto de todas las hileras definidas sobre el alfabeto.

l1 = { w PERTENCE {0,1}* tq w = w10, con w1 PERTENECE {0,1}* }
dado un alfabeto y K >= 0
Σ = {0,1}, Σ0 = {ε},
Σ1 = {00, 01, 10, 11} 
Σk = { w tq |w|=k  y w esta formado solo por simbolos en Σ }

Clausura de Kleene

Automatas de Estados Finitos
- Uno de los esquemas mas primitivos para computar
- No puede sumar cualquier par de numeros enteros
- Estados:
-- Estado inicial
-- Estado de aceptacion
-- Transiciones

Un automata de estados finitos M es una quintupla.
M = { Q, E, &, q0, F  }

donde Q = conjunto finito de estados
  Q = { q0, q1, q2, ..., qn  }

E = conjunto finito de simbilos (alfabeto de entrada)

& = Q x E -> Q (funcion de transicion)
  (q, a) ~> p
  &(q, a) = p

q0 PERTENCE Q, estado inicial

F: SUBCONJUNTO Q conj. de estados de aceptacion o finales.

Representacion CUADERNO amarillo.


## Expresiones Regulares
- Es una hilera
- Secuencia de simbolos
- Describe un lenguaje
- Es una meta hilera
- es finita
- define hileras infinitas
- obtenemos un patron
- es una notacion
- no es una expresion aritmetica
- es una manera mas de definir un lenguaje

Para un lenguaje descrito con una expresion regular
se puede construir un automata equivalente (determinista o no) y viceversa.


//
Ejercicio 1: Describa los lenguajes representados por:
– 0(0|1)*0: un cero, seguido por una o mas repeticiones de cero o uno y
finaliza con cero.
– ((ε|0)1*)*: un elemento del alfabeto o cero, seguido por una o mas repeticiones
de uno, toda la expresion repetida una o mas veces.
– (0|1)*0(0|1)(0|1): una seguidilla de uno o un cero una o mas veces, seguido
por un cero, seguido por un uno o un cero y luego otro uno u otro cero.
– 0*10*10*10*: un cero uno o mas veces, seguido por un uno, seguido por un cero
una o mas veces, seguido por un uno, seguido por un cero una o mas veces,
seguido por un uno y una ultima seguidilla de un cero una o mas veces.
– (00|11)* ( (01|10) (00|11)* (01|10) (00|11)* )*: ya sea un par de ceros o un par de
unos una o mas veces, seguido por un cero o un uno O un uno o un cero, seguido
por un par de ceros O un par de unos una o mas veces, seguido por un cero uno O
un uno seguido de un cero, seguido por un par de ceros o un par de unos una o
mas veces, toda la expresion una o mas veces.

Ejercicio 2: Diseñe una expresión regular para los
siguientes lenguajes:
– Hileras sobre ∑={0,1} que representen números binarios impares:
(0|1)*1
– Hileras sobre ∑={0,1} que tengan exactamente dos 1's:
0*10*10*
– Hileras sobre ∑={0,1} que no terminen en 00:
(0|1)*1
– Hileras sobre ∑={0,1} que no contengan la subhilera 011:
1*0*
– Hileras sobre ∑={a,b} donde la cantidad de b's sea múltiplo de 3

