/**************************************************************************
 *
 * Filename: P1v1.c
 *
 * Synopsis: Practical 1
 * 
 * Author:
 *      Darren Lowe, Reg no: 201519214
 *
 * Group:
 *      Thursday, 3-5
 *
 * Promise: I confirm that this submission is all my own work.
 *
 *          (Signed)_____________________________________(Darren Lowe)
 *
 * Version: See VERSION below
 *
 **************************************************************************/


#define VERSION "p1 v1.0 by Darren Lowe. Last update: 10/10/2015\n\n"

#include <stdio.h>

int main() {
/* Add suitable variables here as part of Practial 1 */


float executeTimeOnX = 10, executeTimeOnY = 15;

float cpuTimeOnX = 10, cpuTimeOnY = 6;

float clockSpeedOnX = 2.00, clockSpeedOnY = ((1.2*clockSpeedOnX)*10)/cpuTimeOnY;

	printf(VERSION);	

printf("%fs on X, %fs on Y. So X is %f times faster than Y\n\n", executeTimeOnX, executeTimeOnY, (executeTimeOnY/executeTimeOnX));

printf("X: %fGHz clock, %fs CPU time; Y: ?GHz clock, %fs CPU time. \n\nTherefore clock rate of Y needs to be %fGHz\n\n", clockSpeedOnX, cpuTimeOnX, cpuTimeOnY, clockSpeedOnY);

/* The following code is just a very simple template.
   For Practical 1, the hard-wired constants in the printf()s will need to
   be replaced by variables & (the results of) the performance calculations.
   See [CS210_01_hw/18,21-24] for the equations.
 */

	
	return 0;
}
