#include <SoftwareSerial.h>
#include <SDS011-select-serial.h>

float p10_1, p25_1, p10_2, p25_2,p10_3, p25_3,p10_4, p25_4;
static float sp10_1, sp25_1, sp10_2, sp25_2,sp10_3, sp25_3,sp10_4, sp25_4 =0;
int error1,error2,error3,error4;
static int start =0;

SoftwareSerial mySerial1(2, 3); // RX, TX
SoftwareSerial mySerial2(4, 5); // RX, TX
SoftwareSerial mySerial3(8, 9); // RX, TX
SoftwareSerial mySerial4(10, 11); // RX, TX
SDS011 my_sds1(mySerial1),my_sds2(mySerial2),my_sds3(mySerial3),my_sds4(mySerial4);

void setup() {
  // initialize normal Serial port
  Serial.begin(9600);
  // initalize SDS Serial Port
  mySerial1.begin(9600);
  mySerial2.begin(9600);
  mySerial3.begin(9600);
  mySerial4.begin(9600);
}

void loop() {
  if(start==0){
    mySerial1.listen();
    while(mySerial1.available()){
      error1 = my_sds1.read(&p25_1,&p10_1);
      if (! error1) {
        //Serial.println("P2.5_1: "+String(p25_1) + " P10_1:  "+String(p10_1));
        sp10_1 = p10_1;
        sp25_1 = p25_1;
        delay(100);
        start=1;
      }
    }
  }
 else if(start==1){
    mySerial2.listen();
    while(mySerial2.available()){
      error2 = my_sds2.read(&p25_2,&p10_2);
      if (! error2) {
       //Serial.println("P2.5_2: "+String(p25_2) + " P10_2: "+String(p10_2));
       sp10_2 = p10_2;
       sp25_2 = p25_2;
       delay(100);
        start=2;
      }
    }
  }
  else if(start==2){
    mySerial3.listen();
    while(mySerial3.available()){
      error3 = my_sds3.read(&p25_3,&p10_3);
      if (! error3) {
       //Serial.println("P2.5_3: "+String(p25_3) + " P10_3: "+String(p10_3));
       sp10_3 = p10_3;
       sp25_3 = p25_3;
       delay(100);
        start=3;
      }
    }
  }
  else if(start==3){
    mySerial4.listen();
    while(mySerial4.available()){
      error4 = my_sds4.read(&p25_4,&p10_4);
      if (! error4) {
       //Serial.println("P2.5_4: "+String(p25_4) + " P10_4: "+String(p10_4));
       sp10_4 = p10_4;
       sp25_4 = p25_4;
       delay(100);
        start=4;
      }
    }
  }
  else if(start==4){
    Serial.println("P10_1: "+String(sp10_1) + "  P10_2: "+String(sp10_2) + "  P10_3: "+String(sp10_3)+ "  P10_4: "+String(sp10_4));
  delay(100);
  start=0;
  }
}
  
