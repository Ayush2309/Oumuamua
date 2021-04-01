#include "agva.h"
#include "delay.c"

int file_write(char file_name[], int value);

int init_motor(void){							//motor init functon return 0 if sucess
	if(file_write(enable_loc, 0))					//disabling the motor
		return 1;
	if(file_write(duty_cycle_loc, 0))				//setting duty cycle to 0 for init
		return 1;
	if(file_write(period_loc, period))				// setting the period to default 20KHz
		return 1;
	return 0;
}


//Returns 0 if success
int file_write(char file_name[], int value){ 				// function to write in file
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
}									// end of function



int main(void){								// main starts
	if(init_motor())
		return 1;
	file_write(enable_loc, 1);					//enabling the motor
	clock_t start_time = clock();					//getting the start time
	int clocks_per_ms = CLOCKS_PER_SEC / 1000;			//calculating ticks per ms
	int clocks_required = clocks_per_ms * loop_time_ms;		//required ticks
	while((clock() - start_time) < clocks_required){
		file_write(duty_cycle_loc, PIP);		
		delay_ms(200);						//delay
		file_write(duty_cycle_loc, PEEP);
		delay_ms(300);						//delay
	}
	file_write(enable_loc, 0);
	return 0;
}
