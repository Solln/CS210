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

float cycleTimeOnX = 250, cycleTimeOnY = 500;

float cpiOnX = 2, cpiOnY = 1.2;

printf(VERSION);	

printf("%.1fs on X, %.1fs on Y. So X is %.1fs times faster than Y\n\n", executeTimeOnX, executeTimeOnY, (executeTimeOnY/executeTimeOnX));

printf("X: %.1fGHz clock, %.1fs CPU time; Y: ?GHz clock, %.1fs CPU time. \n    Therefore clock rate of Y needs to be %.1fGHz\n\n", clockSpeedOnX, cpuTimeOnX, cpuTimeOnY, clockSpeedOnY);

printf("X: Cycle time=%.1fps, CPI=%.1f; Y: Cycle time=%.1fps, CPI=%.1f \n    So, CPU Time_X is IC x CPI_X x Cycle Time_X => IC x %.1fps \n", cycleTimeOnX, cpiOnX, cycleTimeOnY, cpiOnY, (cycleTimeOnX*cpiOnX));
printf("    So, CPU Time_Y is IC x CPI_Y x Cycle Time_Y => IC x %.1f \n        Therefore X is %.1f times faster than Y\n\n", (cycleTimeOnY*cpiOnY), (cycleTimeOnY*cpiOnY)/(cycleTimeOnX*cpiOnX));

	
	return 0;
}
