Un programa en C
"A C program, whatever its size, consists of functions and variables. A
function contains statements that specify the computing operations to be done,
and variables store values used during the computation. "

This means that every program must have a main somewhere.

A sequence of characters in double quotes, like "hello, world\n", is called a
character string

The sequence \n in the string is C notation for the newline character, which
when printed advances the output to the left margin on the next line.

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

printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
This last change is an instance of a general rule - in any context where it is permissible to use
the value of some type, you can use a more complicated expression of that type. Since the
third argument of printf must be a floating-point value to match the %6.1f, any floating-
point expression can occur here.

The for is usually appropriate for loops in which the initialization and
increment are single statements and logically related, since it is more compact
than while and it keeps the loop control statements together in one place.

#define LOWER 0 /* lower limit of table */
The quantities LOWER, UPPER and STEP are symbolic constants, not variables, so they do not
appear in declarations. Symbolic constant names are conventionally written in upper case so
they can ber readily distinguished from lower case variable names. Notice that there is no
semicolon at the end of a #define line.

Text input or output, regardless of where it originates or where it goes to, is
dealt with as streams of characters. A text stream is a sequence of characters
divided into lines; each line consists of zero or more characters followed by a
newline character. 

The parentheses around the assignment, within the condition are necessary. The precedence
of != is higher than that of =, which means that in the absence of parentheses the relational
test != would be done before the assignment =. So the statement
    c = getchar() != EOF
is equivalent to
    c = (getchar() != EOF)
This has the undesired effect of setting c to 0 or 1, depending on whether or not the call of
getchar returned end of file. (More on this in Chapter 2.)

A character written between single quotes represents an integer value equal to the numerical
value of the character in the machine's character set. This is called a character constant,
although it is just another way to write a small integer. 

