Un programa en C
"A C program, whatever its size, consists of functions and variables. A
function contains statements that specify the computing operations to be done,
and variables store values used during the computation. "

This means that every program must have a main somewhere.

A sequence of characters in double quotes, like "hello, world\n", is called a character
string

The sequence \n in the string is C notation for the newline character, which when printed
advances the output to the left margin on the next line.

In C, all variables must be declared before they are used.

Tipos de datos numericos en C:
- int
- float: decimales
- char: 1 byte
- short: int pequenyo
- long: int grande
- double: ??

The reason for multiplying by 5 and dividing by 9 instead of just multiplying by 5/9 is that in
C, as in many other languages, integer division truncates: any fractional part is discarded.
Since 5 and 9 are integers. 5/9 would be truncated to zero and so all the Celsius temperatures
would be reported as zero.

If an arithmetic operator has integer operands, an integer operation is performed. If an
arithmetic operator has one floating-point operand and one integer operand, however, the
integer will be converted to floating point before the operation is done. 

