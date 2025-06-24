#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int buttonPin = 7;
int buttonState = HIGH;
int lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);  // Start serial for debugging
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(A0));
  lcd.print("Press button");
  Serial.println("Setup complete, waiting for button press...");
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {  // Button pressed
        Serial.println("Button pressed!");
        showRandomPrompt();
      }
    }
  }

  lastButtonState = reading;
}

void printPrompt(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  if (line2.length() > 0) {
    lcd.print(line2);
  }
}

void showRandomPrompt() {
  int prompt = random(1, 31);
  Serial.print("Showing prompt number: ");
  Serial.println(prompt);

  switch (prompt) {
    case 1:  printPrompt("HIGHEST RATED", "BOOK"); break;
    case 2:  printPrompt("HIGH REPUBLIC", "BOOK"); break;
    case 3:  printPrompt("LOWEST RATED", "BOOK"); break;
    case 4:  printPrompt("SHORTEST BOOK", "ON TBR"); break;
    case 5:  printPrompt("ENEMIES TO", "LOVERS"); break;
    case 6:  printPrompt("BOOK WITH A", "FACE ON COVER"); break;
    case 7:  printPrompt("BOOK FROM", "2021"); break;
    case 8:  printPrompt("BOOK WITH", "TRANS CHARACTERS"); break;
    case 9:  printPrompt("BOOKTOK", "BOOK"); break;
    case 10: printPrompt("ARC", ""); break;
    case 11: printPrompt("SHELF", "VETERAN"); break;
    case 12: printPrompt("ROMANTASY", ""); break;
    case 13: printPrompt("BOOK WITH A", "NAME IN TITLE"); break;
    case 14: printPrompt("BOOK IN A", "SERIES"); break;
    case 15: printPrompt("GL", ""); break;
    case 16: printPrompt("BOOK THAT", "TAKES PLACE"); break;
    case 17: printPrompt("NOT TYPICAL", "GENRE"); break;
    case 18: printPrompt("ROM-COM", ""); break;
    case 19: printPrompt("FAKE DATING", ""); break;
    case 20: printPrompt("CONTINUING", "A SERIES"); break;
    case 21: printPrompt("BOOKS WITH", "SONG TITLES"); break;
    case 22: printPrompt("FREE", "CHOICE"); break;
    case 23: printPrompt("RANDOM NUMBER", "GENERATOR"); break;
    case 24: printPrompt("RANDOM LETTER", "GENERATOR"); break;
    case 25: printPrompt("BL", ""); break;
    case 26: printPrompt("BIPOC", "AUTHOR"); break;
    case 27: printPrompt("RANDOM", "COLOR GEN"); break;
    case 28: printPrompt("KINDLE", "BOOKS"); break;
    case 29: printPrompt("BOOK WITH A", "HOT PERSON"); break;
    case 30: printPrompt("BOOK WITH MORE", "THAN 5 WORDS"); break;
    default: printPrompt("ERROR", "NO PROMPT"); break;
  }
}
