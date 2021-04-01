int init_motor(void){							//motor init functon return 0 if sucess
	if(file_write(enable_loc, 0))					//disabling the motor
		return 1;
	if(file_write(duty_cycle_loc, 0))				//setting duty cycle to 0 for init
		return 1;
	if(file_write(period_loc, period))				// setting the period to default 20KHz
		return 1;
	return 0;
}

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
}	
