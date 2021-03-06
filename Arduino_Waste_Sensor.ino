#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int soundTriggerPin = 2;
const int soundEchoPin = 3;

void setup(void) 
{
    lcd.init();
    lcd.clear();         
    lcd.backlight();
    pinMode(soundTriggerPin, OUTPUT);
    pinMode(soundEchoPin, INPUT);

    Serial.begin(9600);
}
void loop(void)
{
    digitalWrite(soundTriggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(soundTriggerPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(soundTriggerPin, LOW);
      long duration = pulseIn(soundEchoPin, HIGH);
    float distance = duration * 0.034 / 2;
    lcd.setCursor(2,0); 
    lcd.print(distance);
    lcd.println(" cm");
    if (distance < 30) {
      String WasteDistance = "YES";
      lcd.setCursor(2,1);
      lcd.print(WasteDistance);
    }
    else   {
      String WasteDistance = "NO";
      lcd.setCursor(2,1);
      lcd.print(WasteDistance);
  }
  delay(250);

}
