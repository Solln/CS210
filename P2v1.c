/**************************************************************************
 *
 * Filename: P2v1.c
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
 * Version: See History below
 *
Author: Darren Lowe
Date:   Thu Oct 11 00:04:59 2015 +0100

    Final Changes


Author: Darren Lowe
Date:   Thu Oct 11 00:01:38 2015 +0100

    More_Formatting


Author: Darren Lowe
Date:   Wed Oct 10 23:51:10 2015 +0100

    Formatting


Author: Darren Lowe
Date:   Wed Oct 10 23:45:39 2015 +0100

    Finished_Calculations


Author: Darren Lowe
Date:   Wed Oct 10 20:46:44 2015 +0100

    Add_Variables_And_Calcs


Author: Darren Lowe
Date:   Wed Oct 10 18:43:00 2015 +0100

    ChangesToComments


Author: Darren Lowe
Date:   Wed Oct 10 18:38:42 2015 +0100

    SubmitOriginalP0v1
 
**************************************************************************/


#define VERSION "p2 v1.0 by Darren Lowe. Last update: 10/10/2015\n\n"

#include <stdio.h>

int main() {

float executeTimeOnX, executeTimeOnY, cpuTimeOnX, cpuTimeOnY;
float clockSpeedOnX, clockSpeedOnY;
float cycleTimeOnX, cycleTimeOnY, cpiOnX, cpiOnY;


printf(VERSION);	

printf("What is the execution time for machine X?");
    scanf("%f", &executeTimeOnX);
    
printf("What is the execution time for machine Y?");
    scanf("%f", &executeTimeOnY);
    
printf("%.1fs on X, %.1fs on Y. So X is %.1fs times faster than Y\n\n", 
executeTimeOnX, executeTimeOnY, (executeTimeOnY/executeTimeOnX));


    
    printf("What is the execution time of machine X?");
    	scanf("%f", &cpuTimeOnX);
    
    printf("What is the clock rate (in GHz) of machine X?");
    	scanf("%f", &clockSpeedOnX);
    
    printf("What is the execution time of machine Y?");
    	scanf("%f", &cpuTimeOnY);
    
    clockSpeedOnY = ((1.2*clockSpeedOnX)*10)/cpuTimeOnY;

	printf("X: %.1fGHz clock, %.1fs CPU time; Y: ?GHz clock, %.1fs CPU time. \n",
	clockSpeedOnX, cpuTimeOnX, cpuTimeOnY);

	printf("    Therefore clock rate of Y needs to be %.1fGHz\n\n", 
	clockSpeedOnY);



printf("What is the CPI of machine X?");
    scanf("%f", &cpiOnX);
    
printf("What is the CPI of machine Y?");
    scanf("%f", &cpiOnY);
    
printf("What is the cycle time of machine X?");
    scanf("%f", &cycleTimeOnX);
    
printf("What is the cycle time of machine Y?");
    scanf("%f", &cycleTimeOnY);

printf("X: Cycle time=%.1fps, CPI=%.1f; Y: Cycle time=%.1fps, CPI=%.1f \n",
cycleTimeOnX, cpiOnX, cycleTimeOnY, cpiOnY);

printf("    So, CPU Time_X is IC x CPI_X x Cycle Time_X => IC x %.1fps \n", 
(cycleTimeOnX*cpiOnX));

printf("    So, CPU Time_Y is IC x CPI_Y x Cycle Time_Y => IC x %.1f \n",
(cycleTimeOnY*cpiOnY));

printf("        Therefore X is %.1f times faster than Y\n\n", 
(cycleTimeOnY*cpiOnY)/(cycleTimeOnX*cpiOnX));

	
	return 0;
}



