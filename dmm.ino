#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int analog1 = A0;
const int analog2 = A1;
int val1 = 0;
int val2 = 0;
double val1f = 0.0;
double val2f = 0.0;
const double conv = 0.009765625;
char val1s[8] = "";
char val2s[8] = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();
  // turn on the backlight
  lcd.backlight();
  lcd.clear();
}

void loop() {
  char ostr1[16] = "A0: ";
  char ostr2[16] = "A1: ";
  // put your main code here, to run repeatedly:
  lcd.clear();
  // read in new values on the analog pins
  val1 = analogRead(analog1);
  val2 = analogRead(analog2);
  // convert the values to floats assuming max 10V
  val1f = val1 * conv;
  val2f = val2 * conv;
  // convert the values to strings
  dtostrf(val1f, 6, 4, val1s);
  dtostrf(val2f, 6, 4, val2s);
  // display the strings on the lcd
  lcd.setCursor(0, 0);
  lcd.print(strcat(strcat(ostr1,val1s)," Volts"));
  lcd.setCursor(0, 1);
  lcd.print(strcat(strcat(ostr2,val2s)," Volts"));
  delay(500);
}
