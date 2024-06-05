void main()
{
  //OUTPUT
  TRISD = 0x00;
  PORTD = 0X00;
  TRISC = 0x00;
  PORTC = 0x00;
  //INPUT
  TRISB = 0b00001111;
//S1=door open clockWise
//S2=door stop for 30 seconds
//S3=door close counterClockWise
//S4=stop motor from rotating

while(1){
if (PORTB.F3==1){
   while(PORTB.F3==1){
   //dc motor off
   PORTD.F2=0;
   PORTD.F1=0;
   //buzzer off
   PORTC.F0=0;
   }
}  else{
if(PORTB.F0==1 && PORTB.F1==0 && PORTB.F2==0){
 //S1=door open clockWise
   PORTD.F2=1;
   PORTD.F1=1;
 //buzzer is on
   PORTC.F0=1;

   //delay_ms(1000);
 }else if (PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==0){
 //S2 door stop
   PORTD.F2=0;
   PORTD.F1=0;
 // buzzer off
   PORTC.F0=0;

 }else if (PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==1){
  //S1=door open counterClockWise
 PORTD.F2=1;
 PORTD.F1=0;
 //buzzer on
 PORTC.F0=1;


 }
}
}
}