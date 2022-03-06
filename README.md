# ft_printf

**** HOW TO USE ****

• Compile using the command "$> make";

• The program name: libftprintf.a;

But, before run the program, you must understand what the project is by reading the folowing lines.


**** THE PROJECT ****

• The project aims to write a library that contains ft_printf(), a function that will mimic the original printf()

• You have to implement the following conversions:
  - %c Prints a single character.
  - %s Prints a string (as defined by the common C convention).
  - %p The void * pointer argument has to be printed in hexadecimal format.
  - %d Prints a decimal (base 10) number.
  - %i Prints an integer in base 10.
  - %u Prints an unsigned decimal (base 10) number.
  - %x Prints a number in hexadecimal (base 16) lowercase format.
  - %X Prints a number in hexadecimal (base 16) uppercase format.
  - %% Prints a percent sig

**** THE RULES ****

• Only these functions can be used::
  - malloc; 
  - free; 
  - write;
  - va_start; 
  - va_arg; 
  - va_copy; 
  - va_end.
