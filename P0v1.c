/* This is a very simple template to form the basis of Practical 0.
   Note: Students should replace the text of this comment by the documentation
   requirements as set out in the Practical Guidelines to be found at:
   http://classes.myplace.strath.ac.uk/mod/page/view.php?id=632583
   Compilation:
     To produce an executable file named p0v1_0 use:
   gcc p0v1_0 -o p0v1_0
     If you want to make sure your code is squeaky clean use
     the compile time switches '-Wall -pedantic' as follows:
   gcc p0v1_0.c -Wall -pedantic -o p0v1_0
 */

#define VERSION "p0 v1.0 by Duncan. Last update: 05/10/2014\n\n"

#include <stdio.h>	/* Include standard library functions for I/O */

int main() {
/* Add suitable variables here as part of Practial 1 */
	printf(VERSION);	/* Might as well know who wrote this thing! */

/* The following code is just a very simple template.
   For Practical 1, the hard-wired constants in the printf()s will need to
   be replaced by variables & (the results of) the performance calculations.
   See [CS210_01_hw/18,21-24] for the equations.
 */
	/* Example from CS210_01_hw/18 */
	printf("10s on A, 15s on B. So A is 1.5 times faster than B\n\n");
	/* Example from CS210_01_hw/22 */
	printf("A: 2GHz clock, 10s CPU time; B: ?GHz clock, 6s CPU time\n");
	printf("\tTherefore clock rate of B needs to be 4GHz\n\n");
	/* Example from CS210_01_hw/24 */
	printf("A: Cycle time=250ps, CPI=2.0; B: Cycle time=500ps, CPI=1.2\n");
	printf("\tSo, CPU Time_A is IC x CPI_A x Cycle Time_A => IC x 500ps\n");
	printf("\tSo, CPU Time_B is IC x CPI_B x Cycle Time_B => IC x 600ps\n");
	printf("\t\tTherefore A is 1.2 times faster than B\n");
	
	return 0;
}