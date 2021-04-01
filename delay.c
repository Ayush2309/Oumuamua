
void delay_ms(int ms){                                                  //delay function takes argument in milli-seconds
        clock_t start_time = clock();                                   //getting the time
        int clocks_per_ms = CLOCKS_PER_SEC / 1000;                      //calcullating ticks per ms
        int clocks_required = clocks_per_ms * ms;                       //required ticks
        while((clock() - start_time) < clocks_required)                 //loop
                ;
}


