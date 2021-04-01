#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// REMEMBER Period should alyways be equal or less than duty cycle
#define duty_cycle 20000						//define duty cycle
#define period 50000							//define period
#define PIP 40000	
#define PEEP 10000
#define loop_time_ms 4000						//set time for how long you want to run loop					

char duty_cycle_loc[] = "/sys/class/pwm/pwm-7:1/duty_cycle";	//duty cycle file location
char period_loc[] = "/sys/class/pwm/pwm-7:1/period";		// period file location
char enable_loc[] = "/sys/class/pwm/pwm-7:1/enable";		// enable file location


void delay_ms(int ms){						//delay function takes argument in milli-seconds
clock_t start_time = clock();
int clocks_per_ms = CLOCKS_PER_SEC / 1000;
int clocks_required = clocks_per_ms * ms;
while((clock() - start_time) < clocks_required)
;
}

//Returns 0 if success
int file_write(char file_name[], int value){ 			// function to write in file
FILE *fptr;							//file pointer declaration
fptr = fopen(file_name,"w");
if(fptr == NULL)						//checking for NULL condition
   {
      printf("Error! Writing to file");   
      return 1;             
   }
fprintf(fptr, "%d", value);
fclose(fptr);
return 0;			
}								// end of function



int main(void){							// main starts
file_write(duty_cycle_loc, 0);
file_write(period_loc, period);
file_write(enable_loc, 1);
clock_t start_time = clock();
int clocks_per_ms = CLOCKS_PER_SEC / 1000;
int clocks_required = clocks_per_ms * loop_time_ms;
while((clock() - start_time) < clocks_required){
file_write(duty_cycle_loc, PIP);
delay_ms(300);
file_write(duty_cycle_loc, PEEP);
delay_ms(300);
}
file_write(enable_loc, 0);
return 0;
}
