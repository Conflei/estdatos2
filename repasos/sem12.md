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
