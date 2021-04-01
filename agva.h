#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define duty_cycle 20000                                                //define duty cycle
#define period 50000                                                    //define default period 20KHz
#define PIP 20000       
#define PEEP 10000
#define loop_time_ms 10000                                              //set time for how long you want to run loop


char duty_cycle_loc[] = "/sys/class/pwm/pwm-7:1/duty_cycle";            //duty cycle file location
char period_loc[] = "/sys/class/pwm/pwm-7:1/period";                    // period file location
char enable_loc[] = "/sys/class/pwm/pwm-7:1/enable";                    // enable file location

//function definiations 
int init_motor(void);
int file_write(char file_name[], int value);
void delay_ms(int ms);
