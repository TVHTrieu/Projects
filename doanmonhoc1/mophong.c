#include<REGX51.H>

sbit pwm_out=P3^0;
unsigned char pwm_duty;
unsigned char count_int;
sbit LCD_RS=P2^0;
sbit LCD_RW=P2^1;
sbit LCD_EN=P2^2;
sbit LCD_D4=P2^4;
sbit LCD_D5=P2^5;
sbit LCD_D6=P2^6;
sbit LCD_D7=P2^7;
unsigned int count=0,a=0,b=0,f=0,t=0,x=0;

void delay_us(unsigned int t){
             unsigned int i;
			 for(i=0;i<t;i++);
}

void delay_ms(unsigned int t){
             unsigned int i,j;
			 for(i=0;i<t;i++)
			 for(j=0;j<125;j++);}

void LCD_Enable(void){
         LCD_EN=1;
		 delay_us(3);
		 LCD_EN=0;
		 delay_us(50);
}

void LCD_Send4Bit(unsigned char Data){
         LCD_D4=Data & 0x01;
		 LCD_D5=(Data>>1)&1;
		 LCD_D6=(Data>>2)&1;
		 LCD_D7=(Data>>3)&1;
}

void LCD_SendCommand(unsigned char command){
         LCD_Send4Bit(command>>4);
		 LCD_Enable();
		 LCD_Send4Bit(command);
		 LCD_Enable();
}

void LCD_Clear(){
         LCD_SendCommand(0x01);
		 delay_us(10);
}

void LCD_Init(){
         LCD_Send4Bit(0x00);
		 delay_ms(20);
		 LCD_RS=0;
		 LCD_RW=0;
		 LCD_Send4Bit(0x03);
		 LCD_Enable();
		 delay_ms(5);
		 LCD_Enable();
		 delay_us(100);
		 LCD_Enable();
		 LCD_Send4Bit(0x02);	 //di chuyen con tro ve dau man hinh
		 LCD_Enable();
		 LCD_SendCommand(0x28);	  //giao tiep 4 bit
		 LCD_SendCommand(0x0c);	  //bat hien thi va tat con tro
		 LCD_SendCommand(0x06);	  //Tu dong di chuyen con tro sang vi tri ke tiep khi xuat ra LCD 1 ky tu
		 LCD_SendCommand(0x01);	  //Xoa man hinh
}

void LCD_Gotoxy(unsigned char x, unsigned char y){
         unsigned char address;
		 if(!y)address=(0x80+x);
		 else address=(0xc0+x);
		 delay_us(1000);
		 LCD_SendCommand(address);
		 delay_us(50);
}

void LCD_PutChar(unsigned char Data){
         LCD_RS=1;
		 LCD_SendCommand(Data);
		 LCD_RS=0;
}

void LCD_Puts(char *s){
         while(*s){
		     LCD_PutChar(*s);
			 s++;
			      }
}

void LCD_Number(unsigned long number, unsigned char leng){
unsigned char i;
char CacKyTu[20];
unsigned char temp;
        
		for(i=0;i<leng;i++)
		{
		 temp=number%10;
		 number=number/10;
		 CacKyTu[i]=temp;
		}
		for(i=0;i<leng;i++)
		{
		 LCD_RS=1;
		 LCD_SendCommand(CacKyTu[leng-1-i] + 48);
		 LCD_RS=0;
		}
		 
}

void phai()
{
      if(P1_0==0)
	  {
	   while(P1_0==0);
	   P3_4=1;
	   P3_5=1;
	   P3_6=0;
	   P3_7=0;
	   TR0=1;
	   LCD_Gotoxy(0,0);
	   LCD_Puts("Phai");
	  }
}

void trai()
{
      if(P1_1==0)
	  {
	   while(P1_1==0);
	   P3_6=1;
	   P3_7=1;
	   P3_4=0;
	   P3_5=0;
	   TR0=1;
	   LCD_Gotoxy(0,0);
	   LCD_Puts("Trai");
	  }
}

void dung()
{
     if(P1_2==0)
	 {
	  while(P1_2==0);
	  TR0=0;
	  P3_4=0;
	  P3_5=0;
	  P3_6=0;
	  P3_7=0;
	  LCD_Gotoxy(0,0);
	  LCD_Puts("Stop");
	 }
}

void nhanh()
{
     if(P1_3==0)
	 {
	  while(P1_3==0);
	  if(pwm_duty<100)
	   pwm_duty++;
	  else
	   pwm_duty=100;
	 }
}

void cham()
{
     if(P1_4==0)
	 {
	  while(P1_4==0);
	  if(pwm_duty>1)
	   pwm_duty--;
	  else
	   pwm_duty=1;
     }
}

void cap1()
{
     if(P1_5==0)
	 {
	  while(P1_5==0);
	  pwm_duty=10;
	 }
}

void cap2()
{
     if(P1_6==0)
	 {
	  while(P1_6==0);
	  pwm_duty=100;
	 }
}

void main(){
        P3_4=0;
	    P3_5=0;
	    P3_6=0;
	    P3_7=0;
        TMOD=0x12;
		TH0=-100;
		ET1=1;
		ET0=1;
		EX0=1;
		IT0=1;
		TR0=1;
		TR1=1;
		EA=1;
		pwm_duty=50;
		LCD_Init();
		LCD_Gotoxy(0,0);
		LCD_Puts("Stop");
	    while(1){
		        phai();
				trai();
				dung();
				nhanh();
				cham();
				cap1();
				cap2();
		        LCD_Gotoxy(0,1);
				LCD_Puts("Toc do:");
				LCD_Gotoxy(5,0);
				LCD_Puts(" %PWM");
				LCD_Gotoxy(11,0);
				LCD_Number(pwm_duty,3);
		        LCD_Gotoxy(7,1);
				LCD_Number(f,4);
				LCD_Gotoxy(11,1);
				LCD_Puts("v/p");
			    }
}

void timer0(void) interrupt 1
{
      count_int++;
	  if(count_int==100)
	  count_int=0;
	  if(count_int<pwm_duty)
	  pwm_out=1;
	  else
	  pwm_out=0;
}

void demxung(void) interrupt 0 
{
       count++;
}

void timer1(void) interrupt 3 
{
	   t++;
       TH1=0xfc;
	   TL1=0x18;
	   TR1=1;
	   if(t==1000)
	   {
	    x=count;
		count=0;
		t=0;
		a=x*2.4247;
		f=(a+b)/2.035;
		b=a;
       }
}




	
			 			


