#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 1000 

DigitalOut red(TRAF_RED1_PIN,0);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

//Object for controlling the LCD
LCD_16X2_DISPLAY lcd;


int main()
{   
    red = 1;
    lcd.puts("RED");
    wait_us(10000 * WAIT_TIME_MS);
    
    amber = 1;
    lcd.cls();
    lcd.puts("Red + Amber");
    wait_us(2000 * WAIT_TIME_MS);
    red = 0;
    amber = 0;

    green = 1;
    lcd.cls();
    lcd.puts("Green");    
    wait_us(10000 * WAIT_TIME_MS);
    green = 0;
    
    lcd.cls();
    lcd.puts("Amber");
    int count = 0;
    while(count < 4)
    {
        amber = 1; 
        wait_us(500 * WAIT_TIME_MS);
        amber = 0; 
        wait_us(500 * WAIT_TIME_MS);
        count = count + 1;
    }

    lcd.cls();
    lcd.puts("TASK-104");

    /*while (true)
    {
        red = !red;
    amber = !amber;
        green = !green;
        wait_us(WAIT_TIME_MS * 1000);
    }*/
}
