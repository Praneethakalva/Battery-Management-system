#include <16F72.h>

#use        delay  (clock=20000000)

#include <lcd.c>


void main()
{
   double vol_read1;

   double vol_read2;

   double vol_read3;

   lcd_init();

   setup_adc_ports(ALL_ANALOG);

   setup_adc(ADC_CLOCK_INTERNAL);



   lcd_putc('\f');         //Clear LCD

   lcd_gotoxy(1,1);

   printf(lcd_putc," Welcome To");

   lcd_gotoxy(1,2);

   printf(lcd_putc," B   M   S");

   output_high(PIN_C5);
   output_high(PIN_C4);
   output_high(PIN_C6);

   delay_ms(700);
   output_low(PIN_C5);
   output_low(PIN_C4);
   output_low(PIN_C6);

   delay_ms(700);
   output_high(PIN_C5);
   output_high(PIN_C4);
   output_high(PIN_C6);

   delay_ms(700);
   output_low(PIN_C5);
   output_low(PIN_C4);
   output_low(PIN_C6);



  while(1)
  {

     vol_read1 = read_battery_voltage(0); //first battery
     vol_read2 = read_battery_voltage(1); //first battery
     vol_read3 = read_battery_voltage(2); //first battery

     temp_read = read_temperature();

     lcd_putc('\f');         //Clear LCD
     lcd_gotoxy(1,1);
     printf(lcd_putc,"B-P1 V:%2.2f V",vol_read1);
     lcd_gotoxy(1,2);
     printf(lcd_putc,"B-P2 V:%2.2f V",vol_read2);
     delay_ms(720);

     lcd_putc('\f');         //Clear LCD
     lcd_gotoxy(1,1);
     printf(lcd_putc,"Temp = %Lu DegC",temp_read);
     lcd_gotoxy(1,2);
     printf(lcd_putc,"B-P3 V:%2.2f V",vol_read3);
     delay_ms(720);


      output_low(PIN_C5);
      output_low(PIN_C4);
      output_low(PIN_C6);
      output_low(PIN_C7);

     delay_ms(70);


     if(temp_read > 50.0)
     {
         output_high(PIN_C7);
         lcd_gotoxy(1,2);
         printf(lcd_putc,"High Temperature");
         delay_ms(400);
     }

     if(vol_read1 < 10.0)
     {
         output_high(PIN_C4);
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Low B-P1 Voltage   ");
         delay_ms(400);
     }

     if(vol_read2 < 10.0)
     {
         output_high(PIN_C5);
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Low B-P2 Voltage   ");
         delay_ms(400);
     }

     if(vol_read3 < 10.0)
     {
         output_high(PIN_C6);
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Low B-P3 Voltage   ");
         delay_ms(400);
     }



  }
}