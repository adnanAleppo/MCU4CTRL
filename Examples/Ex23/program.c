#include <mega16.h> 
#include <delay.h>
#include <stdlib.h> 
#include <lcd.h>
#asm
.equ __lcd_port=0x1B ; PORTA
#endasm
#define led PORTB.0
char keypad16(void);
char press_f,kp,op;
long n1,n2;
char s[10];
void main(void) {
DDRD=0b00001111;
lcd_init(16);
lcd_puts("0");
led=1;
Loop:
kp=keypad16();
if (kp!=20)
{if (kp<10) n1=n1*10+kp;
if (kp=='c') n1=0;    
if (kp=='=')
{switch  (op) {
case '+': n1=n2+n1; break;
case '-': n1=n2-n1; break;
case '*': n1=n2*n1; break;
case '/': n1=n2/n1; break;}}
lcd_clear(); 
ltoa(n1,s);
lcd_puts(s);
if (kp=='+' || kp=='-' || kp=='*'|| kp=='/') 
{op=kp ;
  n2=n1;n1=0;
}}goto Loop;}

char keypad16(void)
{char key=20;
PORTD=0B00000001;delay_ms(1);
if (PIND.4==1 && press_f==0)
{key=7;press_f=1;}
if (PIND.5==1 && press_f==0)
{key=8;press_f=1;}
if (PIND.6==1 && press_f==0)
{key=9;press_f=1;}
if (PIND.7==1 && press_f==0)
{key='/';press_f=1;}
PORTD=0B00000010;delay_ms(1);
if (PIND.4==1 && press_f==0)
{key=4;press_f=1;}
if (PIND.5==1 && press_f==0)
{key=5;press_f=1;}
if (PIND.6==1 && press_f==0)
{key=6;press_f=1;}
if (PIND.7==1 && press_f==0)
{key='*';press_f=1;}
PORTD=0B00000100;delay_ms(1);
if (PIND.4==1 && press_f==0)
{key=1;press_f=1;}
if (PIND.5==1 && press_f==0)
{key=2;press_f=1;}
if (PIND.6==1 && press_f==0)
{key=3;press_f=1;}
if (PIND.7==1 && press_f==0)
{key='-';press_f=1;}
PORTD=0B00001000;delay_ms(1);
if (PIND.4==1 && press_f==0)
{key='c';press_f=1;}
if (PIND.5==1 && press_f==0)
{key=0;press_f=1;}
if (PIND.6==1 && press_f==0)
{key='=';press_f=1;}
if (PIND.7==1 && press_f==0)
{key='+';press_f=1;}
PORTD=0B00001111;delay_ms(1);
if (PIND==0B00001111 && press_f==1)
{press_f=0;}    
return key;}
