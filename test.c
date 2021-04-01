#include "agva.h"
#include "delay.c"
#include "agva.c"

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
