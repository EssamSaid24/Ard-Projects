#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define led 13
LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char StorePass[]="2580";
int i=0;
int count=0;
char pass[4];
void setup(){
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Enter password");
  lcd.setCursor(0,1);
  pinMode(led,OUTPUT);

}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    lcd.print('*');
        pass[i]=key;
    i++;
  }
    if(i==4)
    {
      for(int j=0;j<4;j++)
      {
        if(pass[j]==StorePass[j])count++;
      }
      if(count==4)
      {
        lcd.clear();
        digitalWrite(led,HIGH);
        delay(1000);
        digitalWrite(led,LOW);
        

        lcd.setCursor(0,0);
        lcd.print("Correct Pass    ");
        delay(5000);
        i=0;
        count=0;
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
      }else
      {
        printt();
                digitalWrite(led,HIGH);

      }
   
  }}


void printt()
{
        lcd.clear();
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
        lcd.print("Wrong Pass     ");
        delay(2000);
        i=0;
        count=0;
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
}
