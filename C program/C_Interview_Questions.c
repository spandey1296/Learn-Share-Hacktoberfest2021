Frequently /commonly asked C Interview Questions
1) What is modular programming?

Modular programming is a program design technique in which a large program is divided into sub programs/ functions that are called modules, it improve maintainability of a program. It makes software development, debug, modify, update faster and easy.

2) How many keywords & operators are used in c Language?

There are 32 keywords & 45 operators that are used in c programming language.

3) What is variable?

Variable is a named location with unique name, used to stored data according to the requirement.

4) What is the return type of printf() function, and what it returns ?

printf() is a library function, the prototype of printf() is available in <stdio.h>, It returns a interger value, that describe how many charaters are printed on console.

5) What is the return type of scanf() function, and what it returns ?

scanf() is a library function, the prototype of scanf() is availabe in <stdio.h>, It returns a integer value, that describe successful input from console in variable.

6) What is full form of AT & T lab ?

Americal Telegraph and Telecommunication.

7) What is the full form of ANSI?

American National Standard Institute.

8) What is full form of ARM ?

Advance RISC(Reduced Instruction Set Computer) Machine.

9) Whenever a condition is evaluated in C language, How can we understand It is TRUE or FALSE?

Every condition returns 1 when it is TRUE, and return 0 when it is FALSE.

10) What is the difference between #include < > and #include " "?

#include< >: compiler searches header files in standard directory.

    /***header files***/
    #include < stdio.h >
    #include < math.h >
#include" ": compiler searches header files in current directory first then searches in standard directory, basically this type of inclusion used for user defined header files.

    /***header files***/
    #include "stdio.h"
    #include "math.h"
    #include "inc/cam.h"
    
11) What is a main() and difference b/w void main() and int main()?

mian() is an entry point ( main function) which is in most programming languages, When compiler begins compile the program, It looks for an entry point, and main() acts as an entry point in C program, or we can say main is a thread/ process/ function that invokes automatically by the compiler when program is being executed.

Every function returns a value to the calling function, at that time main will be a called function for compiler/OS and it will return some value to the compiler before exit, here void and int defines that main will return a void ( nothing) and int will return an integer values to the compiler.

void main() syntax

#include <stdio.h>
void main()
{
	statements;
	....;
	statements;
}
int main() syntax

#include <stdio.h>
int main()
{
    statements;
    ....;
    statements;
    return 0; /*return any integer value*/
}
ADVERTISEMENT

 
12) What is an lvalue?

An lvalue is a variable to which value can be assigned by assignment operator, this is located on the left side of assignment (=) operator, whereas rvalue is located on the right side of the assignment operator, and lvalue can not be a constant.

13) What is the difference between printf() and puts() ?

The function printf() writes the data on standard output device with the ability of formatted string using %c, %d, %s, %20s .. etc and printf does not add new line after displaying text.

 int printf(const char *format, ...);
puts() writes the string on standard output device and add new line after displaying text.

 int puts(const char *s);
14) In the case of character array what is the difference b/w strlen() and sizeof() ?

In character array strlen() returns the number of characters, while sizeof() returns the number of occupied bytes by character array.

Example

#include <stdio.h>
#include <string.h>

int main()
{
	char text[100]= "Sample test";
	printf("%d,%d", strlen(text), sizeof(text));
	return 0;
}
In this example strlen(text) will return 11 because total number of characters are 11 and sizeof(text) will return 100, because text variable will take 100 bytes in memory.

ADVERTISEMENT

 
15) When is a switch statement can be better than an if statement?

If you have more than one condition to check on single variable or a single expression, then switch is better than if. In switch statement, program’s execution jumps to the matching value if found. If you use if condition, it checks one by one condition. So it is highly recommended to use switch, if you have to check a variable/condition/expression with multiple values.

Example

if( errorCode == 0)
	printf("Error code is 0: reading failed error.\n");
if( errorCode == 1)
	printf ("Error code is 1: writing failed error.\n");
if( errorCode == 2)
	printf("Error code is 2: opening failed error.\n");
if( errorCode == 3)
	printf("Error code is 3: write protected.\n");
Here, errorCode variable is checking with values 0,1,2 and 3. In such case you can use switch.

switch(errorCode)
{
	case 0:
		printf("Error code is 0: reading failed error.\n");
		break;

	case 1:
		printf ("Error code is 1: writing failed error.\n");
		break;

	case 2:
		printf("Error code is 2: opening failed error.\n");
		break;

	case 3:
		printf("Error code is 3: write protected.\n");
		break;
