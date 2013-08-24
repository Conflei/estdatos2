# Compiladores
A compiler translates (or compiles) a program written in a high-level
programming language that is suitable for human programmers into the low-level
machine language that is required by computers. 

 Conceptually, these phases operate in sequence (though in practice, they are
often interleaved), each phase (except the first) taking the output from the
previous phase as its input. 

- Lexical analysis: the text is read and divided into tokens, each of which
  corresponds to a symbol in the programming language.
- Syntax analysis: This phase takes the list of tokens produced by the lexical
  analysis and arranges these in a tree-structure.
- Type checking: This phase analyses the syntax tree to determine if the
  program violates certain consistency requirements.
- Intermediate code generation
- Register allocation
- Machine code generation: The intermediate language is translated to assembly
  language.
- Assembly and linking

Each phase, through checking and transformation, establishes stronger
invariants on the things it passes on to the next.

## Interpretes
Instead of generating code from the syntax tree, the syntax tree is processed
directly to evaluate expressions and execute statements, and so on.
Compiled code tends to be bigger than intermediate code, which tend to be
bigger than syntax, but each step of translation improves running speed.

## Jerarquia de lenguajes
Los lenguajes se pueden clasificar según su grado de independencia de la
máquina en que se ejecutan en cinco grupos:
§ Lenguaje máquina: 1010101
§ Lenguaje ensamblador (en inglés assembly): ADD, MUL.
§ Lenguajes de medio nivel: goodies de ensamblador con mezcla de alto nivel, C.
§ Lenguajes de alto nivel o lenguajes orientados a usuarios: JAVA, C++.
§ Lenguajes orientados a problemas concretos: SQL, etc.


# Lenguajes
Lenguajes Formales
• Símbolo: unidad mínima de información en el contexto.
• Alfabeto: conjunto finito de símbolos, denotado comúnmente por ∑.
• Hilera sobre ∑: secuencia finita de símbolos tomados de ∑.
• Longitud de la hilera z: cantidad de símbolos que componen z.
• Hilera vacía: ε
• Lenguaje sobre ∑: conjunto de hileras sobre ∑.

## regex
Representan patrones de tiras de caracteres.

## automatas
Autómatas de Estados Finitos (DFAs):
Un DFA es un grafo dirigido. Contiene estados y
transiciones (etiquetadas) entre los estados.

Un DFA es un quinteto (∑,S,T,S0,A)
• Componentes:
– ∑: un alfabeto.
– S: un conjunto de estados.
– T: una función de transición T:S x ∑ → S. – S0: un estado inicial.
– A: un conjunto de estados de aceptación.

## Jerarquía de Chomsky.
Lenguajes Recursivamente Enumerables
  Lenguajes Sensibles al Contexto
    Lenguajes Libres de Contexto
      Lenguajes Regulares

Gramática Libre de Contexto
• Es un cuádruple (V,Σ,R,S):
– V: conjunto de no-terminales, variables.
– Σ: conjunto de terminales.
– R: conjunto de reglas o producciones.
– S: símbolo inicial
￼
## Criptografia
Los criptosistemas permiten establecer cuatro aspectos fundamentales de la
seguridad informática:
- Confidencialidad,
- Integridad,
- Autenticación y
- No repudio de emisor y receptor.
