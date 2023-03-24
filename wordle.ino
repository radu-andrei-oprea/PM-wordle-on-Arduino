#include <SPI.h>
#include "Ucglib.h"


int buzzPin= 3; // I/O-pin from buzzer connects here 
const int wpm = 20; // Morse speed in WPM
const int dotL = 1200/wpm; // Calculated dot-length
const int dashL = 3*dotL; // Dash = 3 x dot
const int sPause = dotL; // Symbol pause = 1 dot
const int lPause = dashL; // Letter pause = 3 dots
const int wPause = 7*dotL; // Word pause = 7 dots

Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);



int check = 0;

//letters of the word
char L1;
char L2;
char L3;
char L4;
char L5;

//status for each letter
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;

// word
int W;



//lifes, duh =]]
int lifes = 5;


void setup() {
  
//set buzzer-pin as output
pinMode(buzzPin,OUTPUT);

//set up the LCD font and clear the screen
ucg.begin(UCG_FONT_MODE_SOLID);
ucg.clearScreen();

randomSeed(analogRead(500));

//for input from keyboard

}

void loop() {

  Serial.begin(9600);
  W = random(1,5);
  
  while(1){
    // a word is randomly picked
    if (W == 1){
    L1 = 'M';
    L2 = 'A';
    L3 = 'P';
    L4 = 'L';
    L5 = 'E';
    }
    else if (W == 2){
    L1 = 'A';
    L2 = 'N';
    L3 = 'K';
    L4 = 'L';
    L5 = 'E';
    }
    else if (W == 3){
    L1 = 'P';
    L2 = 'U';
    L3 = 'R';
    L4 = 'S';
    L5 = 'E';
    }
    else if (W == 4){
    L1 = 'C';
    L2 = 'L';
    L3 = 'A';
    L4 = 'I';
    L5 = 'M';
    }
    else if (W == 5){
    L1 = 'B';
    L2 = 'L';
    L3 = 'O';
    L4 = 'O';
    L5 = 'M';
    }
  
  
  
    
    dot();
    ucg.setFont(ucg_font_inb27_mr);
    ucg.setColor(255, 255, 255);
  
    ucg.setPrintPos(0,30);
    ucg.print("WORDLE");
    
    
    //display spaces or letters, in case the player has found any
    ucg.setPrintPos(0,65);
    
    if(s1 == 1){
      ucg.print(L1);
    }
    else ucg.print("_");
    
    ucg.setPrintPos(45,65);
    
    if(s2 == 1){
      ucg.print(L2);
    }
    else ucg.print("_");
    
    ucg.setPrintPos(90,65);
    
    if(s3 == 1){
      ucg.print(L3);
    }
    else ucg.print("_");
    
    ucg.setPrintPos(135,65);
    
    if(s4 == 1){
      ucg.print(L4);
    }
    else ucg.print("_");
    
    ucg.setPrintPos(180,65);
    
    if(s5 == 1){
      ucg.print(L5);
    }
    else ucg.print("_");
    
    
    
    
    ucg.setPrintPos(0,120);
  
  //FIRST LETTER
    if (Serial.available() > 0){
      char inChar = toUpperCase(Serial.read());
      ucg.print(inChar);
  
      if (inChar == L1){
        s1 = 1;
      }
      else if (inChar == L2){
        if(s2 == 0){
          s2 = 2;
        }
      }
      else if (inChar == L3){
        if(s3 == 0){
          s3 = 2;
        }
      }
      else if (inChar == L4){
        if(s4 == 0){
          s4 = 2;  
        }
      }
      else if (inChar == L5){
        if(s5 == 0){
          s5 = 2;
        }
      }
      
       
      ucg.setPrintPos(45,120);
    }
    
  //SECOND LETTER
    if (Serial.available() > 0){
      char inChar = toUpperCase(Serial.read());
      ucg.print(inChar);
  
      if (inChar == L1){
        if(s1 == 0){
          s1 = 2;
        }
      }
      else if (inChar == L2){
        s2 = 1;
      }
      else if (inChar == L3){
        if(s3 == 0){
          s3 = 2;
        }
      }
      else if (inChar == L4){
        if(s4 == 0){
          s4 = 2;  
        }
      }
      else if (inChar == L5){
        if(s5 == 0){
          s5 = 2;
        }
      }
      
      ucg.setPrintPos(90,120);
    }
    
  //THIRD LETTER
    if (Serial.available() > 0){
      char inChar = toUpperCase(Serial.read());
      ucg.print(inChar);
  
      if (inChar == L1){
        if(s1 == 0){
          s1 = 2;
        }
      }
      else if (inChar == L2){
        if(s2 == 0){
          s2 = 2;
        }
      }
      else if (inChar == L3){
        s3 = 1;
      }
      else if (inChar == L4){
        if(s4 == 0){
          s4 = 2;  
        }
      }
      else if (inChar == L5){
        if(s5 == 0){
          s5 = 2;
        }
      }
  
      
      ucg.setPrintPos(135,120);
    }
    
  //FOURTH LETTER
    if (Serial.available() > 0){
      char inChar = toUpperCase(Serial.read());
      ucg.print(inChar);
  
      if (inChar == L1){
        if(s1 == 0){
          s1 = 2;
        }
      }
      else if (inChar == L2){
        if(s2 == 0){
          s2 = 2;
        }
      }
      else if (inChar == L3){
        if(s3 == 0){
          s3 = 2;  
        }
      }
      else if (inChar == L4){
        s4 = 1;
      }
      else if (inChar == L5){
        if(s5 == 0){
          s5 = 2;
        }
      }
  
      
      ucg.setPrintPos(180,120);
    }
    
  //FIFTH LETTER  
    if (Serial.available() > 0){
      char inChar = toUpperCase(Serial.read());
      ucg.print(inChar);
  
      if (inChar == L1){
        if(s1 == 0){
          s1 = 2;
        }
      }
      else if (inChar == L2){
        if(s2 == 0){
          s2 = 2;
        }
      }
      else if (inChar == L3){
        if(s3 == 0){
          s3 = 2;  
        }
      }
      else if (inChar == L4){
        if(s4 == 0){
          s4 = 2;
        }
      }
      else if (inChar == L5){
        s5 = 1;
      }
  
      ucg.setPrintPos(225,120);
  
      check = 1;
    }
  
    delay(1000);
    ucg.setPrintPos(0,120);
    
    ucg.print(" ");
    ucg.setPrintPos(45,120);
    
      ucg.print(" ");
    ucg.setPrintPos(90,120);
    
      ucg.print(" ");
    ucg.setPrintPos(135,120);
    
      ucg.print(" ");
    ucg.setPrintPos(180,120);
    
      ucg.print(" ");
    ucg.setPrintPos(225,120);
  
  
    
    ucg.setPrintPos(0,180);
    ucg.print("in word:");
    ucg.setPrintPos(0,225);
  
    if(s1 == 2){
      ucg.print(L1);
      ucg.setPrintPos(45,225);
    }
    if(s2 == 2){
      ucg.print(L2);
      ucg.setPrintPos(90,225);
    }
    if(s3 == 2){
      ucg.print(L3);
      ucg.setPrintPos(135,225);
    }
    if(s4 == 2){
      ucg.print(L4);
      ucg.setPrintPos(180,225);
    }
    if(s5 == 2)
      ucg.print(L5);
    
    
    // display lifes
    ucg.setPrintPos(0,290);
    ucg.print("lifes:");
    ucg.setPrintPos(180,290);
    ucg.print(lifes);
    
    
    if (check == 1){
       if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1){
          victory();  
        }
    
       else{
        lifes --;
        if(lifes == 0){
          fail();
        }
          
        check = 0;
       }
    }
  }
//  victory();

//  ucg.clearScreen();
}

void dot(){
digitalWrite(buzzPin, LOW); // Tone ON
delay(dotL); // Tone length
digitalWrite(buzzPin, HIGH); // Tone OFF
delay(sPause); // Symbol pause
return;
}

void dash(){
digitalWrite(buzzPin, LOW); // Tone ON
delay(dashL * 10); // Tone length
digitalWrite(buzzPin, HIGH); // Tone OFF
//delay(sPause); // Symbol pause
return;
}


void fail(){
  ucg.clearScreen();
  ucg.setColor(255, 0, 0);
  ucg.setPrintPos(10,150);

  ucg.print("YOU FAILED");
  dot();
  delay(wPause-lPause);
  dot();
  delay(wPause-lPause);
  dash();
  delay(wPause);

  while(1);
}

void victory(){
  ucg.clearScreen();
  ucg.setColor(255, 255, 0);
  ucg.setPrintPos(50,150);

  ucg.print("VICTORY");


  while(1){
    dot();
    delay(lPause-sPause);
    dot();
    delay(lPause-sPause);
    dot();
  
    delay(wPause-lPause);
    dot();
    delay(lPause-sPause);
    dot();
    delay(lPause-sPause);
    dot();
    delay(lPause-sPause);
    dot();
    delay(lPause-sPause);
    dot();
    delay(wPause-lPause);
    delay(wPause-lPause);
    delay(wPause-lPause);
  }
}
