#include <wire.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

//----------------------------Global Variables--------------------------

const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

String inputString;
long inputInt;

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//########################################################################
//########################################################################

void setup()
{
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.
  Serial.begin(9600);
  inputString.reserve(10); // maximum number of digit for a number is 10
}

void loop()
{
  
  //--------------------------------Origin--------------------------------

  lcd.print("Origin:");
  lcd.setCursor(0, 1);

  lcd.print("MyValue");//....Read Input and store

  lcd.setCursor(0, 0);
  lcd.clear();
  delay(1000);

  //------------------------------Destination-----------------------------

  lcd.print("Destination:");
  lcd.setCursor(0, 1);

  lcd.print("MyValue");//....Read Input and store

  lcd.setCursor(0, 0);
  lcd.clear();
  delay(1000);

  //-----------------------------No. of People----------------------------

  lcd.print("No. of People:");
  lcd.setCursor(0, 1);

  lcd.print("MyValue");//....Read Input and store

  lcd.setCursor(0, 0);
  lcd.clear();
  delay(1000);

  //--------------------------------Luggage-------------------------------

  lcd.print("Luggage:");
  lcd.setCursor(0, 1);

  lcd.print("MyValue");//....Read Input and store

  lcd.setCursor(0, 0);
  lcd.clear();
  delay(1000);

}

//########################################################################
//########################################################################

//---------------------------------Source---------------------------------

void getSource(){
  char source = keypad.getKey();

  if (source) {
    Serial.println(source);

    if (source >= '0' && source <= '9') {     // only act on numeric keys
      inputString += source;               // append new character to input string
    } else if (source == '#') {             // Using # as an enter key
      if (inputString.length() > 0) {
        inputInt = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        Serial.println(inputInt);

      }
    } else if (source == '*') {
      inputString = "";                 // clear input
    }
  }
}

//--------------------------------Destination--------------------------------

void getDestination(){
  char destination = keypad.getKey();

  if (destination) {
    Serial.println(destination);

    if (destination >= '0' && destination <= '9') {     // only act on numeric keys
      inputString += destination;               // append new character to input string
    } else if (destination == '#') {             // Using # as an enter key
      if (inputString.length() > 0) {
        inputInt = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        Serial.println(inputInt);

      }
    } else if (destination == '*') {
      inputString = "";                 // clear input
    }
  }
}

//--------------------------------No. of Passenger--------------------------------

void getNoOfPassenger(){
  char noOfPassenger = keypad.getKey();

  if (noOfPassenger) {
    Serial.println(noOfPassenger);

    if (noOfPassenger >= '0' && noOfPassenger <= '9') {     // only act on numeric keys
      inputString += noOfPassenger;               // append new character to input string
    } else if (noOfPassenger == '#') {             // Using # as an enter key
      if (inputString.length() > 0) {
        inputInt = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        Serial.println(inputInt);

      }
    } else if (noOfPassenger == '*') {
      inputString = "";                 // clear input
    }
  }
}