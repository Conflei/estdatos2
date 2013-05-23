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

En su CORE, C no tiene valores booleanos.

By definition, chars are just small integers, so char variables and constants are identical to
ints in arithmetic expressions. 

You may have noticed that there is a return statement at the end of main. Since main is a
function like any other, it may return a value to its caller, which is in effect the environment in
which the program was executed. Typically, a return value of zero implies normal
termination; non-zero values signal unusual or erroneous termination conditions.

This declaration, which is called a function prototype, has to agree with the definition
and uses of power. It is an error if the definition of a function or any uses of it do not agree
with its prototype.

Los valores en C se pasan por valor excepto los arrays:
The story is different for arrays. When the name of an array is used as an argument, the value
passed to the function is the location or address of the beginning of the array - there is no
copying of array elements. By subscripting this value, the function can access and alter any
argument of the array. This is the topic of the next section.

An external variable must be defined, exactly once, outside of any function; this sets aside
storage for it. The variable must also be declared in each function that wants to access it; this
states the type of the variable. The declaration may be an explicit extern statement or may be
implicit from context.

You should note that we are using the words definition and declaration carefully when we
refer to external variables in this section.**Definition** refers to the place where the variable is
created or assigned storage; **declaration** refers to places where the nature of the variable is
stated but no storage is allocated.

