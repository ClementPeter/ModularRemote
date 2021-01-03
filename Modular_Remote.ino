//A Remote Controlled 7 Segment Display that displays exact button Presses on a Single Digit 7 segment Display

/* Feel free too reach out @  https://twitter.com/___carlos___01 */

#include <IRremote.h>
int IRpin = 3;               //Declare Variable for the Infrared Pin
IRrecv IR(IRpin);       //Create an IR object and pin
decode_results cmd;   //Result of infrared code get stored here
String myCom;            //Command for Storing Variables

//7 Segment Pins
int a = 4;       //Definition of digital interface 7 connecting to "A" on the 7 segment digital tube
int b = 5;      // Definition of digital interface 6 connected B segment digital tube
int c = 6;      // Definition of digital interface 5 connected C segment digital tube
int d = 7;     // Definition of digital interface 10 connected D segment digital tube
int e = 8;     // Definition of digital interface 11 connected e segment digital tube
int f = 9;     // Definition of digital interface 8 connected f segment digital tube
int g = 10;    // Definition of digital interface 9 connected g segment digital tube
int dp = 11;  // Definition of digital interface 4 connected DP segment digital tube

int wait = 3000; //Varaible for delay interval
void setup() {
  // put your setup code here, to run once:
  
  //Turn on Serial Monitor
  Serial.begin(9600);
  IR.enableIRIn();

  //Set the pinModes 4-11 as Output
  int i;
  for (i = 4; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
  
  //Signify you that the DISPLAY is Active
  all();

}


void loop() {
  // put your main code here, to run repeatedly:
  while (IR.decode(&cmd) == 0) { }  //AWhile loop that continues looping if the Remote Controller is not Pressed

  //PRINT THE HEXADECIMAL VALUE OF THE BUTTONS
  Serial.print(cmd.value, HEX);
  Serial.print("--");
  delay(100);
  IR.resume();

  //BUTTONS ON THE REMOTE CONTROLLER...
  //Map each Individual Button to the Corresponding HEX Value
  if (cmd.value == 0xFF6897) {
    myCom = "ZERO";
    Serial.println(myCom);
    digital_0();
  }
  if (cmd.value == 0xFF9867) {
    myCom = "100+";
    Serial.println(myCom);
  }
  if (cmd.value == 0xFFB04F) {
    myCom = "200+";
    Serial.println(myCom);
  }
  
  if (cmd.value == 0XFF30CF) {
    myCom = "ONE";
    Serial.println(myCom);
    digital_1();
  }
  if (cmd.value == 0xFF18E7) {
    myCom = "TWO";
    Serial.println(myCom);
    digital_2();
  }
  if (cmd.value == 0XFF7A85) {
    myCom = "THREE";
    Serial.println(myCom);
    digital_3();
  }
  if (cmd.value == 0XFF10EF) {
    myCom = "FOUR";
    Serial.println(myCom);
    digital_4();
  }
  if (cmd.value == 0XFF38C7) {
    myCom = "FIVE";
    Serial.println(myCom);
    digital_5();
  }
  if (cmd.value == 0XFF5AA5) {
    myCom = "SIX";
    Serial.println(myCom);
    digital_6();
  }
  if (cmd.value == 0XFF42BD) {
    myCom = "SEVEN";
    Serial.println(myCom);
    digital_7();
  }

  if (cmd.value == 0XFF4AB5) {
    myCom = "EIGHT";
    Serial.println(myCom);
    digital_8();
  }
  if (cmd.value == 0XFF52AD) {
    myCom = "NINE";
    Serial.println(myCom);
    digital_9();
  }
  if (cmd.value == 0XFFE01F) {
    myCom = "MINUS";
    Serial.println(myCom);
  }
  if (cmd.value == 0XFFA857) {
    myCom = "PLUS";
    Serial.println(myCom);
  }
}

//7 segment Display Functions

//Display number0
void digital_0() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}

////Display number 1
void digital_1() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}
//Display number 2
void digital_2() {
  digitalWrite(g, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(f, LOW);
  digitalWrite(e, HIGH);
}
//Display number 3
void digital_3() {
  digitalWrite(g, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(f, LOW);
  digitalWrite(e, LOW);
}
//Display number 4
void digital_4() {
  digitalWrite(c, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
  digitalWrite(a, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
}
//Digital Display 5
void digital_5() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

//Digital Display 6
void digital_6() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}
//Digital Display 7
void digital_7() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}
//Digital Display 7
void digital_8() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}
//Digital Display 9
void digital_9() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}
//Digital Display dp
void digital_dp() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}
//Display All the LEDS
void all() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
}
