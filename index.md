# Arduino Game Console
The arduino game console is a console that allows the user to play one of two games: hangman and star chaser. The user uses the buttons on the console to choose between the two games and play them. The game console also includes a pentiometer and a passive buzzer, which produces the sound effects from the games. 

<!-- Replace this text with a brief description (2-3 sentences) of your project. This description should draw the reader in and make them interested in what you’ve built. You can include what the biggest challenges, takeaways, and triumphs from completing the project were. As you complete your portfolio, remember your audience is less familiar than you are with all that your project entails! FIX BIO FORMATTING -->

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Siri K.| Irvington High School | Aerospace Engineering | Rising Junior


![Headstone Image](logo.svg)
# Modification
  For my modification, I chose to add a third game to the game console. Finding one that would match the demensions of my LCD was very challenging, so I settled for games meant for 16x2 LCDs. Originally, I chose to code a two player ping pong game, but since the code had too many issues, I chose flappy bird. I ended up having a similar problem with flappy bird, so I searched for different games until I found space invaders. After changing the code a little, the game worked perfectly. However, the game still hasn't been added to the original code, so I hope to do that next, as well as add more games to the console in the future.
  Some key topics I learned throughout this project include learning how to use wires to recreate PCBs, how to drill, dremel, and cut acrylic, and code and troubleshoot. I learned that bridging helps connect mulitple wires together, and that they have to be secure so that there won't be any loose connections. I also learned that there are many ways to solve a specific issue, and you should keep finding those solutions because they might be easier. I hope to learn more about the different functions of each wiring connection after Bluestamp, as well as how to create more Arduino projects. 
  
# Final Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/7_M6H3smQ3E" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  Since the completion of my second milestone, I have added the code and made sure the games work properly. The conosle is now fully functioning, though I would still like to add another game to the console. As a result of my decision, the bottom of the console is not yet secured.
  One of the biggest challenges for this milestone was getting the code to display on the LCD screen. I later learned that the problem was the display contrast, which I was easily able to fix. The next big challenge was getting the buttons to work. As a result of weak soldering, the 'D' button wouldn't work during one of the games, and the problem was fixed after redoing the soldering. The biggest challenge during the project was getting the LCD to light up and wiring the PCB, since I had to do thos since scratch. My biggest triumph was being able to get the LCD to turn on, since it was a problem I tried to fix for the longest time.

# Second Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/yEASH0IJAb4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  After finishing the PCB, I worked on adding the acrylic pieces to the game console. I ended up cutting and sanding the acrylic by hand so it could easily fit in the console. The acrylic also prevents the wires from going all over the place. I hot glued everything together once I was sure the LCD could turn on without having to hold the wires in a certain way. A big challenge I faced was trying to get the LCD to light up. I was able to get it to light up after realizing that it wasn't working because I didn't solder two wires together. Another challenge I faced was having to adjust the size of the hole the LCD would go in. Since it was too small for the LCD, I had to use a dremel to cut of some of the 3D print, which was challenging because I had to avoid all the wires that were still attached to the console. Next I will be adding the games to the console, which will be my third milestone. 

# First Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/J0KFbBLnFsk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  My project is the Arduino game console, and to build it, I need to first start with assembling the PCB. It consists of mulitple pieces, such as the push buttons, that let the user play the games on the console, the potentiometer, which essentially control the volume, multiple wires which connect all the different parts to the Arduino nano inside, and most importantly, the LCD screen. So far, I have assembled the PCB and connected all the wires so that when connected to a power source, the LCD screen should light up. The biggest challenge I have faced so far was trying to recreate the PCB from scratch and modifying it. The next step would be to finish assembling the rest of the console so I can start adding the games to it.

# Starter Project
<iframe width="560" height="315" src="https://www.youtube.com/embed/60VA6kidIu0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

  For my starter project, I chose to build the useless box. I chose to do this because I always wondered how flipping a switch would cause an arm to move up from the box, flip the switch, and go back inside the box. Through building the useless box, I was able to find the answer to my question: flipping the switch triggers the motor, making it move counter-clockwise. This causes the arm, attached to the motor, to move up and out of the box. Once it moves far enough to flip the switch, the motor moves clockwise, moving the arm back to its original position. 

  Throughout the duration of this starter project, I ran into a couple of problems, mainly getting the motor to work and move the arm to flip the switch. When testing out the arm, the batteries began to overheat and give off smoke, which I later learned was caused by the solder that I applied on one of the two screw terminals. When I was soldering them in place, I accidentally created a “bridge,” which made the energy from the batteries travel through the bridge and back into the batteries, causing them to overheat. I fixed this problem by resoldering the screw terminals and removing the bridge between them.



# Schematics 

# Code

Star Chaser & Hangman Code:

```c++
///SEEMS TO FINALLY ACTUALLY WORK
////

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

byte star1[] = {
  B00100,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};

byte star2[] = {
  B00100,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};

byte star3 [] = {
  B00100,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};

byte starShip[] = {
  B11111,
  B10001,
  B11111,
  B11111,
  B10101,
  B10101,
  B00000,
  B10101
};

int level = 2;
int score;
int wall = 3;
volatile bool started = 0;
byte start_button = 7;
byte arrow_button = 10;
byte hang_button = 12;
volatile byte menu_button = 11;
bool menu = 0;

//*******************//
#define SPEAKERPIN 8
#define NUMWORDS 10

//define notes for buzzer
#define LOWNOTE 100
#define ALOW 440
#define CLOW 261
#define ELOW 329
#define FLOW 349
#define CHIGH 523
#define EHIGH 659
#define GHIGH 784
#define FSHIGH 740
#define AHIGH 880

#define btnRight     0
#define btnUp        1
#define btnDown      2
#define btnLeft      3
#define btnSelect    4
#define btnNone      5
//*******************//

//*******************//
const char* words[] = {"atmosphere", "computer", "postscript", "deadline", "censorship", "shorthand", "monkey", "jack", "dilemma", "interface"};
const char letterVal[] = "abcdefghijklmnopqrstuvwxyz";
char guessLetter;
char guessLast;
char guessed[25];
char* secretWord;
int guessedCount = 1;
int wordSize;
int pick;
int gotOne = 0;
int alreadyGuessed = 0;
int showAsterisk = 0;
int buttonState;
int hangman = 0;
int totalRight = 0;
int sel = 0;
int prevKey = btnNone;
unsigned long lastDebounceTime = 0;


String guessWord = String(10);

// hangman graphic characters
byte topleft[] = { 0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
byte topright[] = { 0x1C, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00 };
byte bottomleft[] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F, 0x1F, 0x1F };
byte bottomright[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
byte head[] = { 0x1C, 0x04, 0x04, 0x0E, 0x0E, 0x00, 0x00, 0x00 };
byte topbody[] = { 0x1C, 0x04, 0x04, 0x0E, 0x0E, 0x04, 0x04, 0x04 };
byte bottombody[] = { 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
byte rightarm[] = { 0x1C, 0x04, 0x04, 0x0E, 0x0E, 0x05, 0x06, 0x04 };
byte leftarm[] = { 0x1C, 0x04, 0x04, 0x0E, 0x0E, 0x15, 0x0E, 0x04 };
byte rightleg[] = { 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00 };
byte leftleg[] = { 0x04, 0x04, 0x0A, 0x0A, 0x11, 0x00, 0x00, 0x00 };
byte leftarrow[] = { 0x10, 0x18, 0x1C, 0x1E, 0x1E, 0x1C, 0x18, 0x10 };
byte rightarrow[] = { 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x07, 0x03, 0x01 };

//*******************//

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin (9600);

  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  pinMode (2, INPUT_PULLUP);
  pinMode (3, INPUT_PULLUP);
  pinMode (10, INPUT_PULLUP);
  pinMode (11, INPUT_PULLUP);
  pinMode (12, INPUT_PULLUP);
  pinMode (start_button, INPUT_PULLUP);
  pinMode (menu_button, INPUT_PULLUP);
  pinMode (8, OUTPUT);

  lcd.createChar(0, star1);
  lcd.createChar(1, star2);
  lcd.createChar(2, star3);
  lcd.createChar(3, starShip);
  lcd.begin(20, 4);
  attachInterrupt(0, buttonin, CHANGE);
  attachInterrupt(1, buttonin2, CHANGE);
  // Enable PCIE2 Bit3 = 1 (Port D)
  PCICR |= B00000100;
  // Enable PCINT18  & PCINT23 (Pins D2 & D7)
  PCMSK2 |= B10000000;
  // Enable PCIE0 Bit0 = 1 (Port b)
  PCICR |= B00000001;
  // Enable PCINT18  & PCINT23 (Pins  D11)
  PCMSK0 |= B00001000;


  randomSeed(analogRead(A6));
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}
int n;
int z = 0;
volatile bool returnFlag = 0;







void loop() {
  returnFlag = 0;

  while (z == 0) {
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("'A' FOR STAR CHASER");
    lcd.setCursor(1, 2);
    lcd.print("'B' FOR HANGMAN");
    z = 1;
  }

  if (digitalRead (arrow_button) == 0) {
    star_game ();
  }

  if (digitalRead (hang_button) == 0) {
    hang_game ();
  }

}

void hang_game() {
  gotOne = 0;
  alreadyGuessed = 0;
  showAsterisk = 0;
  buttonState;
  hangman = 0;
  totalRight = 0;
  sel = 0;
  guessedCount = 1;
  guessLast = 0;
  z = 0;
  if (returnFlag == 1) {
    return;
  }

  start_hang_game ();

  while (returnFlag == 0) {
    if (returnFlag == 1) {
      return;
    }

    // letter selection via potentiometer
    //int potVal = analogRead(POTPIN) / 40;      // 1024 / 26 ~= 39
    int potVal = sel; //Hack to use lcd keypad shield buttons
    guessLetter = letterVal[potVal];

    // if letter is different from last, print to lcd
    // this prevents from printing the same char over and over
    if (guessLetter != guessLast) {
      guessLast = guessLetter;
      showAsterisk = 0;

      // cycle through all guessed letters and determine whether to show * or the letter
      for (int x = 0; x < guessedCount; x++) {

        if (guessLetter == guessed[x]) {
          showAsterisk = 1;
        }
      }
      // print letters to the left of selected letter
      lcd.setCursor(3, 0);
      for (int x = 5; x >= 1 ; x--) {

        if (potVal - x >= 0) {
          lcd.print(letterVal[potVal - x]);
        }
        else {
          lcd.print("|");
        }
      }

      // print left arrow
      lcd.write(4);

      // print the letter
      if (showAsterisk == 0) {
        lcd.setCursor(9, 0);
        lcd.print(guessLetter);
        alreadyGuessed = 0;
      }
      // print a *
      else {
        lcd.setCursor(9, 0);
        lcd.print("*");
        alreadyGuessed = 1;
      }

      // print right arrow
      lcd.write(5);

      // print letters to the right of selected letter
      lcd.setCursor(11, 0);
      for (int x = 1; x <= 5 ; x++) {

        if (potVal + x <= 25) {
          lcd.print(letterVal[potVal + x]);
        }
        else {
          lcd.print("|");
        }
      }
    }
    if (returnFlag == 1) {
      return;
    }
    int k = inkeys();
    if (returnFlag == 1) {
      return;
    }

    // If you've scrolled through the alphabet and pressed the button select
    if ( k == btnSelect ) {
      gotOne = 0;
      if (alreadyGuessed == 0) {
        alreadyGuessed = 1;
        lcd.setCursor(9, 0);
        lcd.print("*");
        char buf[wordSize + 1];
        guessWord.toCharArray(buf, wordSize + 1);
        for (int i = 0; i < wordSize; i++) {

          if (buf[i] == guessLetter) {
            lcd.setCursor(i + 3, 1);
            lcd.print(guessLetter);
            gotOne = 1;
            totalRight = totalRight + 1;
          }
        }

        // add letter to guessed letter array
        guessed[guessedCount] = guessLetter;
        guessedCount++;

        // none of the letters match, draw the next body part on the hangman
        if (gotOne == 0) {
          buzz(LOWNOTE, 500);
          hangman++;
          draw_hangman(hangman);
        }
        else {
          // letter is in word, sound buzzer
          buzz(FSHIGH, 30);
          buzz(AHIGH, 50);
        }

        //all letters have been guessed...WIN!
        if (totalRight == wordSize) {
          gameOver(1);
        }
      }
      // this letter has already been guessed, sound buzzer
    }
    // If the scroll right button is pressed
    else if (k == btnRight) {
      if (sel > 24) {
        sel = 0;
      } else {
        sel++;
      }
    }
    // if the scroll left button is pressed
    else if (k == btnLeft) {
      if (sel <= 0) {
        sel = 25;
      } else {
        sel--;
      }
    }
  }
  return;
}

void start_hang_game () {
  if (returnFlag == 1) {
    return;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(".......HANGMAN......");
  lcd.setCursor(1, 2);
  lcd.print("SCROLL LFT=A  RT=B");
  lcd.setCursor(0, 3);
  lcd.print("...SELECT = START...");

  delay(2500);

  // pick a random word using analog 5 for random data
  //randomSeed(analogRead(5));
  newWord();

  //draw the board
  draw_board();
  return;
}

void newWord() {
  if (returnFlag == 1) {
    return;
  }

  //pick a random word from the list
  int pickNew = random(NUMWORDS);

  //check to ensure last word picked isn't repeated
  if (pickNew == pick) {

    int pickNew = random(NUMWORDS);
  }
  if (pickNew == pick) {

    int pickNew = random(NUMWORDS);
  }

  pick = pickNew;

  const char* pickWord = words[pick];
  Serial.print ("Rnd Num = ");
  Serial.println (pick);
  guessWord = pickWord;
  //secretWord = guessWord.getChars();
  wordSize = guessWord.length();
  Serial.println(guessWord);          // print the word to serial for cheaters like me ;)
}

void draw_board() {
  if (returnFlag == 1) {
    return;
  }

  // define the custom characters
  lcd.createChar(0, topleft);
  lcd.createChar(1, topright);
  lcd.createChar(2, bottomleft);
  lcd.createChar(3, bottomright);
  lcd.createChar(4, leftarrow);
  lcd.createChar(5, rightarrow);

  // draw blank hangman table
  lcd.clear();
  lcd.home();
  lcd.write(byte(0));
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.write(2);
  lcd.write(3);

  // print underlines
  lcd.setCursor(3, 1);
  for (int x = 0; x < wordSize; x++) {
    lcd.print("_");
  }
}


void star_game() {
  z = 0;
  lcd.createChar(0, star1);
  lcd.createChar(1, star2);
  lcd.createChar(2, star3);
  lcd.createChar(3, starShip);
  while (returnFlag == 0) {
    if (returnFlag == 1) {
      return;
    }
    while (started == 0) {
      if (returnFlag == 1) {
        break;
      }
      startScreen();
      if (returnFlag == 1) {
        return;
      }
    }

    while (started == 1) {

      n = 17;
      int rnd;
      int rnd2;
      rnd = random(25, 50);
      rnd2 = random(1, 4);
      while ((n != 1) && (started == 1)) {
        if (returnFlag == 1) {
          return;
        }

        if ((score > 9) && (score < 20)) {
          wall = 4;
        }
        if ((score > 19) && (score < 30)) {
          wall = 5;
        }
        if ((score > 29) && (score < 40)) {
          wall = 6;
        }
        if ((score > 39) && (score < 50)) {
          wall = 7;
        }
        if ((score > 49) && (score < 60)) {
          wall = 8;
        }
        if ((score > 59) && (score < 70)) {
          wall = 9;
        }
        if ((score > 69) && (score < 80)) {
          wall = 10;
        }
        if ((score > 79) && (score < 90)) {
          wall = 11;
        }
        if ((score > 89) && (score < 100)) {
          wall = 12;
        }
        if (score >= 100) {
          wingame();
          continue;
        }
        lcd.clear();
        //delay(10);
        lcd.setCursor(11, 0);
        lcd.print("SCORE:");
        drawman();
        lcd.setCursor(n, rnd2);
        if (n == wall) {
          if (level != rnd2) {

            stopgame();

            continue;
          }
          if (level == rnd2 ) {
            tone(8, 1500, 50);
            score ++;

          }
        }
        lcd.write(byte(0));
        lcd.write(byte(1));
        lcd.write(byte(2));
        lcd.setCursor(18, 0);
        lcd.print(score);
        delay(100 - rnd);
        n--;
        //score++;
        //   if(level==0)
        //     score--;
      }
    }
  }
}

void drawman() {
  lcd.setCursor(wall, level);
  lcd.write(byte(3));
}
int buttonin() {
  if (digitalRead(2) == LOW) {
    level = 1;
    tone(8, 1000, 50);
  }
  else {
    level = 2;
  }
}

int buttonin2() {
  if (digitalRead(3) == LOW) {
    level = 3;
    tone(8, 1000, 50);
  }
  else {
    level = 2;
  }
}

void startScreen() {
  if (returnFlag == 1) {
    return;
  }
  int x = 0;
  while (returnFlag == 0) {
    if (returnFlag == 1) {
      return;
    }
    if ((started == 0) && (x == 0) && (returnFlag == 0)) {
      if (returnFlag == 1) {
        return;
      }

      //Serial.println (started);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("YOU ARE ON A JOURNEY");
      lcd.setCursor(0, 1);
      lcd.print("THROUGH SPACE TO");
      lcd.setCursor(0, 2);
      lcd.print("OBSERVE 100 PLANETS");
      lcd.setCursor(0, 3);
      lcd.print("FLY INTO THE PLANETS");
      x = 1;




      //Serial.println (started);
      //      lcd.clear();
      //      lcd.setCursor(2, 0);
      //      lcd.print("STAR CHASER");
      //      lcd.setCursor(4, 1);
      //      lcd.print("PRESS START");
      //      lcd.setCursor(8, 2);
      //      lcd.print("TO BEGIN!");
      //      x = 1;
    }
    if ((started == 0) && (x == 1) && (returnFlag == 0)) {
      //Serial.println (started);
      tone(8, 523, 1500);
      delay (500);
      tone(8, 392, 500);
      delay (250);
      tone(8, 311, 500);
      delay (250);
      tone(8, 392, 500);
      delay (300);
      tone(8, 261, 1500);
      delay (1000);
      x = 2;
    }
    if ((started == 0) && (x == 2) && (returnFlag == 0)) {

      //Serial.println (started);
      tone(8, 523, 1500);
      delay (500);
      tone(8, 392, 500);
      delay (250);
      tone(8, 311, 500);
      delay (250);
      tone(8, 392, 500);
      delay (300);
      tone(8, 261, 1500);
      delay (1000);
      x = 3;
    }

    if ((started == 0) && (x == 3) && (returnFlag == 0)) {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("STAR CHASER");
      lcd.setCursor(4, 1);
      lcd.print("PRESS START");
      lcd.setCursor(8, 2);
      lcd.print("TO BEGIN!");
      lcd.setCursor(0, 3);
      lcd.print("PRESS   C=UP  D=DOWN");
      //Serial.println (started);
      tone(8, 466, 1500);
      delay (500);
      tone(8, 440, 500);
      delay (250);
      tone(8, 392, 500);
      delay (250);
      tone(8, 440, 500);
      delay (300);
      tone(8, 293, 1500);
      delay (1000);
      x = 4;
    }

    if ((started == 0) && (x == 4) && (returnFlag == 0)) {

      //Serial.println (started);
      tone(8, 523, 1500);
      delay (500);
      tone(8, 392, 500);
      delay (250);
      tone(8, 311, 500);
      delay (250);
      tone(8, 392, 500);
      delay (300);
      tone(8, 261, 1500);
      delay (1000);
      x = 5;

    }

    if ((started) == 0 && (x == 5) && (returnFlag == 0)) {
      //Serial.println (started);
      tone(8, 523, 1500);
      delay (500);
      tone(8, 392, 500);
      delay (250);
      tone(8, 311, 500);
      delay (250);
      tone(8, 392, 500);
      delay (300);
      tone(8, 261, 1500);
      delay (1000);
      x = 6;
    }

    if ((started == 0) && (x == 6) && (returnFlag == 0)) {

      //Serial.println (started);
      tone(8, 466, 1500);
      delay (500);
      tone(8, 440, 500);
      delay (250);
      tone(8, 392, 500);
      delay (250);
      tone(8, 440, 500);
      delay (300);
      tone(8, 293, 1500);
      delay (1000);
      x = 7;
      //    if (started == 1 ) {
      //      return;
      //    }

    }
    //  if (started == 1 ) {
    //    return;
    //  }
    if ((started == 0) && (x == 7) && (returnFlag == 0)) {

      //Serial.println (started);
      tone(8, 523, 1500);
      delay (500);
      tone(8, 392, 500);
      delay (250);
      tone(8, 311, 500);
      delay (250);
      tone(8, 392, 500);
      delay (300);
      tone(8, 261, 2000);
      delay (3000);
      x = 0;
      //    if (started == 1 ) {
      //      return;
      //    }
    }
    return;
  }
}

void stopgame() {
  if (returnFlag == 1) {
    return;
  }
  tone(8, 800, 500);
  delay (200);
  tone(8, 600, 500);
  delay (200);
  tone(8, 400, 1000);
  delay (100);
  lcd.clear();
  lcd.setCursor(6, 2);
  lcd.print("GAME OVER!");
  lcd.setCursor(11, 0);
  lcd.print("SCORE:");
  lcd.setCursor(18, 0);
  lcd.print(score);
  level = 2;
  score = 0;
  n = 15;
  wall = 3;
  started = 0;
  delay(3000);
  return;
}

void wingame() {
  if (returnFlag == 1) {
    return;
  }
  tone(8, 800, 500);
  delay (200);
  tone(8, 600, 500);
  delay (200);
  tone(8, 400, 1000);
  delay (100);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("WELL DONE");
  lcd.setCursor(3, 2);
  lcd.print("MISSION COMPLETE!");
  level = 2;
  score = 0;
  n = 15;
  wall = 3;
  started = 0;
  delay(4000);
  return;
}



void draw_hangman(int var) {
  if (returnFlag == 1) {
    return;
  }

  switch (var) {
    case 1:
      lcd.createChar(1, head);           // head
      break;
    case 2:
      lcd.createChar(1, topbody);        // body
      lcd.createChar(3, bottombody);
      break;
    case 3:
      lcd.createChar(1, rightarm);       // right arm
      break;
    case 4:
      lcd.createChar(1, leftarm);        // left arm
      break;
    case 5:
      lcd.createChar(3, rightleg);       // right leg
      break;
    case 6:
      lcd.createChar(3, leftleg);        // left leg
      break;
    case 7:
      gameOver(0);
    default:
      break;
  }
}

void gameOver(int whatToDo) {
  if (returnFlag == 1) {
    return;
  }

  // decide whether win, lose or restart game
  switch (whatToDo) {
    case 0:  // GAME OVER
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("GAME");
      lcd.setCursor(6, 1);
      lcd.print("OVER");

      //buzzer sound
      buzz(ELOW, 500);                  // GAME OVER!
      buzz(CLOW, 1000);                 // sound buzzer
      break;
    case 1:  // WINNER
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("HANGMAN");
      lcd.setCursor(4, 1);
      lcd.print("MASTER!");

      // buzzer sound
      buzz(ALOW, 150);
      buzz(CHIGH, 150);
      buzz(EHIGH, 150);
      buzz(AHIGH, 150);
      delay(150);
      buzz(GHIGH, 150);
      buzz(AHIGH, 500);
  }
  delay(2000);

}

void buzz (int frequencyInHertz, long timeInMilliseconds) {
  if (returnFlag == 1) {
    return;
  }
  Serial.println(frequencyInHertz);
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  for (int x = 0; x < loopTime; x++) {
    digitalWrite(SPEAKERPIN, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(SPEAKERPIN, LOW);
    delayMicroseconds(delayAmount);
  }
  delay(20);
}


int getKey() {
  if (returnFlag == 1) {
    return;
  }

  if (digitalRead (10) == LOW) return btnRight;
  if (digitalRead (12) == LOW) return btnLeft;
  if (digitalRead (7) == LOW ) return btnSelect;
  else return btnNone;

}


int inkeys() {
  if (returnFlag == 1) {
    return;
  }
  int k = getKey();
  while ((k == btnNone) && (returnFlag == 0)) {
    if (returnFlag == 1) {
      return;
    }
    k = getKey();
    delay(10);
  }
  delay(200); //debounce
  return k;
}

ISR (PCINT2_vect)
{
  // Port D Interrupt occured
  // Check if this was D7
  if (digitalRead(start_button) == LOW) {
    //Pin D7 triggered the ISR on a Falling pulse
    started = 1;
  }
}

ISR (PCINT0_vect)
{
  // Port D Interrupt occured
  // Check if this was D11
  if (digitalRead(menu_button) == LOW) {
    //Pin D7 triggered the ISR on a Falling pulse
    returnFlag = 1;
  }
}

```

Space Invaders Code:

```c++
#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// the pins used by the LCD panel
LiquidCrystal_I2C lcd(0x27, 20, 4);

// define button constants
#define btnRight     0
#define btnUp        1
#define btnDown      2
#define btnLeft      3
#define btnSelect    4
#define btnNone      5

//game field size
#define WIDTH 20
#define HEIGHT 4

//custom sprites
#define SHIP 0
#define BULLET_UP 1
#define BULLET_DOWN 2
#define SHIP_BULLET 3
#define ALIEN1 4
#define ALIEN2 5
#define ALIEN1BULLET 6
#define ALIEN2BULLET 7

#define GAME_STEP 100 //Delay (ms) between game steps
#define ALIENS_NUM 8 //Number of aliens

byte animationStep; //Number of game step
char screenBuffer[HEIGHT/2][WIDTH+1]; //Characters to be displayed on the screen
byte alienStep = 5; //The number of game steps between alien's movements
byte fireProbability = 20; //Probability of alien to shoot
int score1 = 0; //Player's score1
byte level1 = 1; //Game level1
byte aliensLeft = 0; //Number of aliens left on current level1
volatile bool started = 0;
byte start_button = 7;
volatile byte menu_button = 11;
bool menu = 0;

//Define custom characters for game sprites
byte ship_sprite[] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00100,
B01110,
B11011
};

byte ship_bullet_sprite[] = {
B00000,
B00100,
B00100,
B00000,
B00000,
B00100,
B01110,
B11011
};

byte bullet_down_sprite[] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00100,
B00100,
B00000
};

byte bullet_up_sprite[] = {
B00000,
B00100,
B00100,
B00000,
B00000,
B00000,
B00000,
B00000
};

byte alien1_1_sprite[] = {
B01010,
B10101,
B01110,
B10001,
B00000,
B00000,
B00000,
B00000
};

byte alien1_2_sprite[] = {
B01010,
B10101,
B01110,
B01010,
B00000,
B00000,
B00000,
B00000
};

byte alien1_1_bullet_sprite[] = {
B01010,
B10101,
B01110,
B10001,
B00000,
B00100,
B00100,
B00000
};

byte alien1_2_bullet_sprite[] = {
B01010,
B10101,
B01110,
B01010,
B00000,
B00100,
B00100,
B00000
};

//Base class for game objects
class GameObject
{
//Object's coordinates and speed
protected:
  int8_t _x;
  int8_t _y;
  int8_t _speed;
public:
  GameObject():_x(0),_y(0),_speed(0){}
  GameObject(int8_t x, int8_t y): _x(x), _y(y), _speed(0){}
  GameObject(int8_t x, int8_t y, int8_t speed): _x(x), _y(y), _speed(speed){}
//Getters and setters
  int8_t x() const{
    return _x;
  }
  int8_t y() const{
    return _y;
  }
  int8_t speed() const{
    return _speed;
  }
  bool setX(int8_t x){
    if ((x<0)||(x>WIDTH))
      return false;
    _x = x;
    return true;
  }
  bool setY(int8_t y){
    if ((y<0)||(y>HEIGHT))
      return false;
    _y = y;
    return true;
  }
  bool setSpeed(int8_t speed){
    _speed = speed;
    return true;
  }
//Collision detection
  bool collides(const GameObject& o){
    return ((_x==o.x())&&(_y==o.y())) ? true : false;
  }
};

//Bullet class
class Bullet:public GameObject
{
private:
  bool _active;//Bullet is active while it is within game field
public:
  Bullet():GameObject(), _active(false){}

  void setActive(bool active){
    _active = active;
  }

  bool active(){
    return _active;
  }
  
/*Moving bulett. Returns true if successfull*/
  bool move(){
    _y+=_speed;//for bullets speed is always vertical
    if ((_y<0)||(_y>=HEIGHT)){//if bullet leaves the field
      _y-=_speed;
      _active = false;
      return false;
    }
    else return true;
  }
} shipBullet, alienBullets[ALIENS_NUM];//bullet objects for ship and aliens

/*Ship class*/
class Ship:public GameObject
{
public:
//Moving right. Returns true if successfull
  bool moveRight(){
    _x++;
    if (_x>=WIDTH){
      _x--;
      return false;
    }
    else return true;
  }
//Moving left. Returns true if successfull
  bool moveLeft(){
    _x--;
    if (_x<0){
      _x++;
      return false;
    }
    else return true;
  }
} ship;

/*Alien class*/
class Alien: public GameObject
{
private:
  bool _alive;//shows wether alien is alive
  bool _state;//alien's current state for animation purpose
public:
  Alien():GameObject(), _alive(false), _state(false){}

  void setAlive(bool alive){
    _alive = alive;
  }

  bool alive(){
    return _alive;
  }

  void setState(bool state){
    _state = state;
  }

  bool state(){
    return _state;
  }
//Moving alien. Returns true if successfull
  bool move(){
    _x+=_speed;
    _state = !_state;
    if ((_x<0)||(_x>=WIDTH)){
      _x-=_speed;
      return false;
    }
    else return true;
  }
}aliens[8];

// Processing buttons state
byte buttonPressed()
{     // read analogue value
// int adc_key_in = analogRead(0);
//Please adjust these values for your version of LCD shield
if (digitalRead (10) == LOW) return btnRight;
 if (digitalRead (2) == LOW)  return btnUp;
 if (digitalRead (3) == LOW)  return btnDown;
 if (digitalRead (12) == LOW)  return btnLeft;
 if (digitalRead (7) == LOW)  return start_button;
 return btnNone;
}

/*Update LCD screen
First drawing in a character buffer, then print it to the screen to avoid flickering.
Note: we have to draw ship separately since it has char code 0 and lcd.print() processes it like EOL*/
void updateScreen(){
  bool shipDisplayed = false; //shows whether ship have been displayed with SHIP_BULLET sprite
//Clearing the buffer
  for (byte i = 0; i < HEIGHT/2; i++){
    for (byte j = 0; j < WIDTH; j++)
      screenBuffer[i][j] = ' ';
    screenBuffer[i][WIDTH] = '\0';
  }
//Drawing ship's bullet
  if (shipBullet.active()){
    if ((ship.x()==shipBullet.x()) && (shipBullet.y()==2)){
      screenBuffer[shipBullet.y()/2][shipBullet.x()] = SHIP_BULLET;
      shipDisplayed = true;
    }
    else
      screenBuffer[shipBullet.y()/2][shipBullet.x()] = shipBullet.y()%2 ? BULLET_DOWN : BULLET_UP;
  }
//Drawing aliens
  for (byte i = 0; i<ALIENS_NUM; i++){
    if(aliens[i].alive()){
      screenBuffer[aliens[i].y()/2][aliens[i].x()] = aliens[i].state() ? ALIEN1 : ALIEN2;
    }
  }
//Drawing aliens and bullets
  bool bulletDisplayed = false;
  for (byte i = 0; i < ALIENS_NUM; i++){
    if(alienBullets[i].active()){
      bulletDisplayed = false;
      for (int j = 0; j < ALIENS_NUM; j++){
        if ((aliens[j].x()==alienBullets[i].x()) && (alienBullets[i].y()==1) && (aliens[i].alive())){
          screenBuffer[alienBullets[i].y()/2][alienBullets[i].x()] = aliens[i].state() ? ALIEN1BULLET : ALIEN2BULLET;
          bulletDisplayed = true;
        }
      }
      if (!bulletDisplayed){
        if ((ship.x()==alienBullets[i].x()) && (alienBullets[i].y()==2)){
          screenBuffer[alienBullets[i].y()/2][alienBullets[i].x()] = SHIP_BULLET;
          shipDisplayed = true;
        }
        else
          screenBuffer[alienBullets[i].y()/2][alienBullets[i].x()] = alienBullets[i].y()%2 ? BULLET_DOWN : BULLET_UP;
      }
    }
  }
//Sending the buffer to the screen
  for (byte i = 0; i < HEIGHT/2; i++){
    lcd.setCursor(0,i);
    lcd.print(screenBuffer[i]);
  }
//After all, displaying the ship
  if (!shipDisplayed){
    lcd.setCursor(ship.x(), ship.y()/2);
    lcd.write(byte(SHIP));
  }
}

/*Reset all the objects before easch level1*/
void initlevel1(byte l)
{
  level1 = l;
  if (level1>42)//Easter egg: 42 is the ultimate level1 :)
    level1 = 42;
//Reset ship object
  ship.setX(WIDTH/2);
  ship.setY(3);
  shipBullet.setX(WIDTH/2);
  shipBullet.setY(3);
  shipBullet.setActive(false);
//Reset aliens objects
  for (byte i = 0; i<ALIENS_NUM; i++){
     aliens[i].setX(i);
     aliens[i].setY(0);
     aliens[i].setSpeed(1);
     aliens[i].setAlive(true);
     aliens[i].setState(false);
     alienBullets[i].setActive(false);
  }
//Reset the rest of the game variables
  animationStep = 0;
  alienStep = 6-level1/2;//alien's speed depends on a level1
  if (alienStep < 1)
    alienStep = 1;
  fireProbability = 110-level1*10;//alien's shoot probability depends on a level1
  if (fireProbability < 10)
    fireProbability = 10;
  aliensLeft = ALIENS_NUM;
//Displaying a number of level1
  lcd.clear();
  lcd.print("level ");
  lcd.setCursor(8,0);
  lcd.print(level1);
  delay(1000);
  lcd.clear();
}

/*Displaying the final score1*/
void gameOver()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("G a m e  o v e r");
  lcd.setCursor(0,1);
  lcd.print("score:  ");
  lcd.setCursor(8,1);
  lcd.print(score1);
  while(1);
}

/*Init: starting LCD and creating custom characters*/
void setup()
{
 lcd.begin(20, 4);
   Serial.begin (9600);

  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  pinMode (2, INPUT_PULLUP);
  pinMode (3, INPUT_PULLUP);
  pinMode (10, INPUT_PULLUP);
  pinMode (11, INPUT_PULLUP);
  pinMode (12, INPUT_PULLUP);
  pinMode (start_button, INPUT_PULLUP);
  pinMode (menu_button, INPUT_PULLUP);
  pinMode (8, OUTPUT);

 lcd.createChar(SHIP, ship_sprite);
 lcd.createChar(BULLET_UP, bullet_up_sprite);
 lcd.createChar(BULLET_DOWN, bullet_down_sprite);
 lcd.createChar(SHIP_BULLET, ship_bullet_sprite);
 lcd.createChar(ALIEN1, alien1_1_sprite);
 lcd.createChar(ALIEN2, alien1_2_sprite);
 lcd.createChar(ALIEN1BULLET, alien1_1_bullet_sprite);
 lcd.createChar(ALIEN2BULLET, alien1_2_bullet_sprite);
 score1 = 0;
 randomSeed(analogRead(1));
 initlevel1 (1);
}

/*Game loop*/
void loop()
{
//Processing the buttons
  switch(buttonPressed()){
  case btnRight:{
    ship.moveRight();
    break;
  }
  case btnLeft:{
    ship.moveLeft();
    break;
  }
  case btnDown:{//Game pause
    while (buttonPressed()==btnDown);
    while (buttonPressed()!=btnDown);
    while (buttonPressed()==btnDown);
    break;
  }
//Shoot
  case btnSelect:
  case btnUp:{
    if(!shipBullet.active()){
      shipBullet.setX(ship.x());
      shipBullet.setY(ship.y());
      shipBullet.setSpeed(-1);
      shipBullet.setActive(true);
      lcd.print("O");
    }
    break;
  }
  default:
    break;
  }
//Moving all the objects
  if(shipBullet.active()) //Moving the ship bullet
    shipBullet.move();
//Moving the aliens and their bullets
  for (byte i = 0; i<ALIENS_NUM; i++){
      if (alienBullets[i].active()){
        alienBullets[i].move();
        if (alienBullets[i].collides(ship)) //Ship destruction
          gameOver();
      }
      if (!(animationStep%alienStep))
        aliens[i].move();
      if ((aliens[i].collides(shipBullet))&&(shipBullet.active())&&(aliens[i].alive())){ //Alien dies
        aliens[i].setAlive(false);
        score1 += 10*level1;
        aliensLeft--;
      }
      if ((!random(fireProbability))&&(!alienBullets[i].active())&&(aliens[i].alive())){ //Alien shoots
        alienBullets[i].setX(aliens[i].x());
        alienBullets[i].setY(aliens[i].y()+1);
        alienBullets[i].setSpeed(1);
        alienBullets[i].setActive(true);
      }
    }
    if ( (!(animationStep%alienStep))&& ((aliens[0].x()==0)||(aliens[ALIENS_NUM-1].x()==WIDTH-1)) )//Changing the aliens'move direction 
        for (byte i = 0; i<ALIENS_NUM; i++)
          aliens[i].setSpeed(-aliens[i].speed());
//Refresh screen
  updateScreen();
  animationStep++;
  delay (GAME_STEP);
//If no aliens left, starting next level1
  if(!aliensLeft)
    initlevel1(level1+1);
}

```

# Bill of Materials

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Arduino Nano [A000005]| contains the code + displays it on the LCD screen | $26.00 | <a href="https://www.amazon.com/Arduino-A000005-ARDUINO-Nano/dp/B0097AU5OU/ref=sr_1_15?keywords=arduino+nano&qid=1689619724&sprefix=ardui%2Caps%2C312&sr=8-15"> Link </a>|
|:--:|:--:|:--:|:--:|
| Push Buttons | the buttons used to play the games | $12.49 | <a href="https://www.amazon.com/dp/B09BKXT1J1/ref=redir_mobile_desktop?_encoding=UTF8&aaxitk=e5ba732c2d3ca4c21552ac330b3c7721&content-id=amzn1.sym.43de8b42-cb89-4910-88e0-25fae4edd09e%3Aamzn1.sym.43de8b42-cb89-4910-88e0-25fae4edd09e&hsa_cr_id=8823072600001&pd_rd_plhdr=t&pd_rd_r=b0be636c-167c-4005-8e93-7c5ca7bdcd33&pd_rd_w=EZTWJ&pd_rd_wg=7vyMv&qid=1689619885&ref_=sbx_be_s_sparkle_lsi4d_asin_0_img&sr=1-1-5aa29f2a-1490-4ae2-848e-815fb6406bcf"> Link </a> |
|:--:|:--:|:--:|:--:|
| 20x4 LCD with IIC | displays the game code | $20.99 | <a href="https://www.amazon.com/Backlight-Module-Shield-Character-R3，Yellow-Green/dp/B09L15ZRDB/ref=sr_1_23_sspa?crid=1X766E6X1OC1U&keywords=20x4+lcd+green&qid=1689619992&s=industrial&sprefix=20x4+lcd+green%2Cindustrial%2C225&sr=1-23-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9idGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Power Switch | turns on the LCD and starts the code | $5.99 | <a href="https://www.amazon.com/5Pcs-Rocker-Switch-Position-QTEATAK/dp/B07Y1GDRQG/ref=sr_1_31_sspa?crid=3IIKEQV8TQU6A&keywords=power%2Bswitch&qid=1689620179&s=industrial&sprefix=power%2Bswitch%2Cindustrial%2C172&sr=1-31-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9idGY&th=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Passive Buzzer | plays the sounds for the games | $7.99 | <a href="https://www.amazon.com/Gikfun-Terminals-Passive-Electronic-Arduino/dp/B01GJLE5BS/ref=sr_1_1_sspa?crid=10R1ME2HY8TNB&keywords=passive+buzzer&qid=1689620324&s=industrial&sprefix=passive+buzze%2Cindustrial%2C163&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| 5K Potentiometer | controls the volume of the buzzer sounds | $9.29 | <a href="https://www.amazon.com/HiLetgo-Single-Joint-Potentiometer-Variable-Resistors/dp/B00N1ZIXKA/ref=sr_1_1_sspa?crid=2NR1CC9X47527&keywords=5k+potentiometer&qid=1689620479&s=industrial&sprefix=5k+potentiometer%2Cindustrial%2C203&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| PCB Slide Switch | when flipped with the power switch, the LCD turns on | $5.39 | <a href="https://www.amazon.com/HiLetgo-SS-12D00-Toggle-Switch-Vertical/dp/B07RTJDW27/ref=sr_1_1_sspa?crid=L9I00AUUZ6FI&keywords=pcb+slide+switch&qid=1689704060&sprefix=pcb+slide+switch%2Caps%2C209&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Jumper Wires | connects the LCD to the screw terminals | $6.99 | <a href="https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD2BWPY/ref=sr_1_1_sspa?crid=2QFB4HN24N83&keywords=jumper%2Bwires&qid=1689704142&sprefix=jumper%2Bwires%2Caps%2C177&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Wires | connects to the PCB parts | $8.99 | <a href="https://www.amazon.com/Fermerry-Silicone-Electrical-Cables-Stranded/dp/B089D2B6T6/ref=sr_1_1_sspa?crid=1REQ7JJZ2YCNK&keywords=wires&qid=1689704239&sprefix=wires%2Caps%2C222&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Screw terminals | holds multiple wires | $8.99 | <a href="https://www.amazon.com/Tnisesm-0-2inch-Terminal-Connector-Spliced/dp/B088LSS14J/ref=sxin_16_pa_sp_search_thematic_sspa?content-id=amzn1.sym.1c86ab1a-a73c-4131-85f1-15bd92ae152d%3Aamzn1.sym.1c86ab1a-a73c-4131-85f1-15bd92ae152d&crid=2WFAVKKDE9HRQ&cv_ct_cx=screw+terminal&keywords=screw+terminal&pd_rd_i=B088LSS14J&pd_rd_r=3bfba2d0-d147-454b-903e-613e748f20cb&pd_rd_w=XdRQl&pd_rd_wg=7mtsr&pf_rd_p=1c86ab1a-a73c-4131-85f1-15bd92ae152d&pf_rd_r=X3RS20J0PQWFG8DW3T8S&qid=1689704357&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=screw+t%2Caps%2C175&sr=1-2-364cf978-ce2a-480a-9bb0-bdb96faa0f61-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9zZWFyY2hfdGhlbWF0aWM&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Anker Power Core | provides power to the game console | $17.99 | <a href="https://www.amazon.com/Anker-PowerCore-Ultra-Compact-High-Speed-Technology/dp/B01CU1EC6Y/ref=sr_1_5?keywords=anker+power+core&qid=1689704440&sr=8-5"> Link </a> |
|:--:|:--:|:--:|:--:|


# Resources and Links
Here are the links to the resources I used to help me complete this project.
- [Starter Project](http://www.spikenzielabs.com/Downloadables/uselessmachine/Useless-Machine-Soldering-Edition.pdf)
- [Intensive Project](https://www.instructables.com/Arduino-Games-Console-With-Multiple-Games/)
- [Modification](https://www.hackster.io/arduinocelentano/space-invaders-like-game-on-1602-lcd-character-display-ef4e6d)
