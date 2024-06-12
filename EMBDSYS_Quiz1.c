void main()
{
  //OUTPUT
  TRISD = 0x00;
  PORTD = 0X00;
  TRISC = 0x00;
  PORTC = 0x00;
  //INPUT
  TRISB = 0b00001111;
//S1=door open clockWise, on buzzer, and onnly on led at C0
//S2=door stop DC motor, off buzzer, and only on led at C1
//S3=door close counterClockWise, on buzzer, and only on led at C2
//S4=stop motor from rotating, off buzzer, and only on led at C3

while(1){
if (PORTB.F3==1){//S1
   //dc motor off
   PORTD.F2=0;
   PORTD.F1=0;
   //buzzer off
   PORTC.F0=0;
   //LED
   PORTC.F4=1;
   PORTC.F1=0;
   PORTC.F2=0;
   PORTC.F3=0;
}  else{
if(PORTB.F0==1 && PORTB.F1==0 && PORTB.F2==0){//S2
 //S1=door open clockWise
   PORTD.F2=1;
   PORTD.F1=1;
 //buzzer is on
   PORTC.F0=1;
  //LED
   PORTC.F4=0;
   PORTC.F1=1;
   PORTC.F2=0;
   PORTC.F3=0;
   //delay_ms(1000);
 }else if (PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==0){ //S3
 //S2 door stop
   PORTD.F2=0;
   PORTD.F1=0;
 // buzzer off
   PORTC.F0=0;
  //LED
   PORTC.F4=0;
   PORTC.F1=0;
   PORTC.F2=1;
   PORTC.F3=0;
 }else if (PORTB.F0==1 && PORTB.F1==1 && PORTB.F2==1){ //S4
  //S1=door open counterClockWise
 PORTD.F2=1;
 PORTD.F1=0;
 //buzzer on
 PORTC.F0=1;
 //LED
 PORTC.F4=0;
 PORTC.F1=0;
 PORTC.F2=0;
 PORTC.F3=1;

 }
}
}
}