#include "mbed.h"


DigitalOut red(PC_2,1);         //Note the initial state
DigitalOut amber(PC_3,1);
DigitalOut green(PC_6,1);


int main()
{
    red = 0;
    amber = 0;
    green = 0;
    
    // Red light
    red = 1;
    wait_us(2000000);

    // Red and Yellow Light
    amber = 1;
    wait_us(2000000);
    red = 0;
    amber = 0;

    //Green light
    green = 1;   
    wait_us(2000000);
    green = 0;

    //Yellow flashing light
    int count = 0;
    while(count < 4)
    {
        amber = 1;
        wait_us(250000);
        amber = 0;
        wait_us(250000);
        count++;
    }
}
