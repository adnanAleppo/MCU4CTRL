#include <mega16.h>
#include <delay.h>
unsigned char v=1;
interrupt [2] void ext_int0_isr(void)
{
if (v<254)
{v++;
OCR0=v ;
}
}

interrupt [3] void ext_int1_isr(void)
{
if(v>1)
{  v--;
OCR0=v;
}
}
void main(void)
{
DDRB.3=1;
PORTD=0B00001100;
MCUCR=0B00001111; 
GICR=0B11000000; 
//prescaler=1, enable correct pwm , clear oco on compare
TCCR0=0B01010001;
OCR0=1;
#asm("sei")
while (1)
{}      
}
