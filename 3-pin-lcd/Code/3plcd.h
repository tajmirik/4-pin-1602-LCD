#include <delay.h>
#define port PORTC
#define ddr  DDRC
#define clock PORTC.0
#define ds PORTC.1
#define en PORTC.2
#define dly 0
#define lcd_clear() command(0x01)

#pragma used+
void command (unsigned char data0)//data=0b 0010 1100
{
    unsigned char data1,data2,counter;
//---------------------------------------------------------------------------------------

    data2=(0x40)|(data0>>4); //data2=0100 0010
    en=0;
    clock=0;
        for (counter=3;;counter--)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
    en=1;//enables the pinout
    delay_ms(dly);
    en=0;
    data2=(data0>>4);//0000 0010
    clock=0;
            for (counter=3;;counter--)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }

    en=1;//enables the pinout
    delay_ms(dly);
////----------------------------------------------------------------------------------------
    clock=0;
    en=0;
    data1=(data0)&(0x0f);     //data1=0000 1100
    data1|=0x40;              //data1=0100 1100
           for (counter=3;;counter--)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
    en=1;
   delay_ms(dly);
    en=0;
    data1=(data0)&(0x0f);
              for (counter=3;;counter--)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }

    en=1;
    delay_ms(dly);


}

void lcd_init()
{
delay_ms(25);
command(0x33);
command(0x32);
command(0x28);
command(0x0c);
command(0x06);
command(0x01);
}

void lcd_blink()
{
    command(0x0f);
}

void data (unsigned char data0)
{
unsigned char data1,data2,counter;
//---------------------------------------------------------------------------------------

    data2=(0xc0)|(data0>>4); //data2=0100 0010
    en=0;
    clock=0;
        for (counter=3;;counter--)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
    en=1;//enables the pinout
    delay_ms(dly);
    en=0;
    data2=(data0 >> 4)|(0x80);//0000 0010
    clock=0;
            for (counter=3;;counter--)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data2>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }

    en=1;//enables the pinout
    delay_ms(dly);
////----------------------------------------------------------------------------------------
    clock=0;
    en=0;
    data1=(data0)&(0x0f);     //data1=0000 1100
    data1|=0xc0;              //data1=1010 1100
           for (counter=3;;counter--)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
    en=1;
   delay_ms(dly);
    en=0;
    data1=(data0)&(0x0f);
    data1=(data1)|(0x80);
              for (counter=3;;counter--)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }
        for (counter=4;counter<8;counter++)
    {
        ds=((data1>>counter)&(0x01));//pinout shift register=(0 1 0 0 0 0 1 0 )
        clock=1;
        clock=0;
        if (counter==0)break;
    }

    en=1;
    delay_ms(dly);
}

void print_string(unsigned char *string)
{
unsigned char counter=0;
    while (*(string+counter)!='\0')
    {
        data(*(string+counter));
        counter++;
    }
}

#pragma used-
