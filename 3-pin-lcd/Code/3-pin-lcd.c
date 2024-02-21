
#include <stdlib.h>
#include <mega32.h>
#include "3plcd.h"
// Declare your global variables here

void main(void)
{
unsigned char *string="I am Kamyab";
unsigned char str[]="I am not Kamyab";
string=str;
// Declare your local variables here
DDRC=0xff;
PORTC=0x07;
lcd_init();
lcd_blink();
print_string(string);

while (1)
      {
      // Place your code here

      }
}
