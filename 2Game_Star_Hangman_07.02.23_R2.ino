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
