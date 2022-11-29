#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
SoftwareSerial Serial1(8, 9);

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

const int analog1InPin = A0;

int sensor = 10;
int state = LOW;

int val = 0;

int sensor1Value = 0;

const int buzz = 13;

const int irPin = 11;
const int piezoPin = 12;

int lowState = 1;
int highState = 1;

void sendwifi(String chr, unsigned int len)
{
  String temp[20];
  Serial1.print("AT+CIPSEND=0,");
  Serial1.println(len);
  delay(1000);
  Serial1.println(chr);
  delay(2000);
}

void setup() {

  pinMode(sensor, INPUT);
  pinMode(buzz, OUTPUT);
  mlx.begin();
  pinMode(irPin, INPUT_PULLUP);
  pinMode(piezoPin, INPUT_PULLUP);
  digitalWrite(buzz, LOW);
  lcd.begin(16, 2);
  lcd.clear(); lcd.setCursor(0, 0); lcd.print("welcome");
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(1000);
  lcd.clear(); lcd.setCursor(0, 0); lcd.print("WIFI INIT");
  Serial1.print("AT\r\n");
  delay(1000);
  Serial1.print("ATE0\r\n");
  delay(1000);
  Serial1.print("AT+CIPMUX=1\r\n");
  delay(1000);
  Serial1.print("AT+CIPSERVER=1,23\r\n");
  delay(1000);
  lcd.clear(); lcd.setCursor(0, 0); lcd.print("192.168.4.1");
  lcd.setCursor(0, 1); lcd.print("Port: 23");
  delay(1000);
  lcd.clear(); lcd.setCursor(0, 0); lcd.print("CONNECTED");
  sendwifi("WELCOME\r\n", 9);
  delay(1000);
}
char x;
void loop() {
  sensor1Value = analogRead(analog1InPin);
  lowState = digitalRead(irPin);
  highState = digitalRead(piezoPin);
  val = digitalRead(sensor);
  while (Serial.available() > 0)
  {
    x = Serial.read();
    if (x == '1')
    {
      digitalWrite(buzz, HIGH);
      lcd.clear(); lcd.setCursor(0, 0); lcd.print("INTRUDER DECETED");
      sendwifi("INTRUDER DECETED\r\n", strlen("INTRUDER DECETED\r\n"));
      Serial.flush();
      delay(1000);
    }
    if (x == '2')
    {
      digitalWrite(buzz, LOW);

      Serial.flush();
      delay(1000);
    }
  }
  if (val == HIGH) {
    lcd.clear();
    lcd.print("PIR = " );
    digitalWrite(buzz, HIGH);
    delay(500); // Delay of led is 500

    if (state == LOW) {
      Serial1.println(" Motion detected ");
      state = HIGH;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print ("Motion detected :");
    }
  }
  else {
    digitalWrite(buzz, LOW);
    delay(500);

    if (state == HIGH) {
      Serial1.println("The action/ motion has stopped");
      state = LOW;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print ("Motion detected stopped");
    }
  }
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print ("Temp :");
  lcd.print(mlx.readObjectTempC());
  lcd.print((char)223);
  lcd.print(" C");
  Serial1.println("\r\nTemp : ");
  delay(2000);
  Serial1.print(mlx.readAmbientTempC());
  delay(1000);
  if (mlx.readAmbientTempC() > 103)
  {
    digitalWrite(buzz, HIGH);
    lcd.clear();
    lcd.begin(16, 2);
    lcd.print("Body Temperature");
    lcd.setCursor(0, 1);
    lcd.print("Abnormal ");
    delay(1000);
    Serial1.println("\r\nBody Temperature Abnormal");
    delay(600);
    digitalWrite(buzz, LOW);
  }
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Sound = " );
  lcd.print(sensor1Value);
  delay(1000);
  Serial1.print("AT+CIPSEND=0,");
  Serial1.println(10);
  delay(1000);
  Serial1.println("\r\nSound : ");
  delay(1000);
  Serial1.print("AT+CIPSEND=0,");
  Serial1.println(4);
  delay(1000);
  Serial1.println(sensor1Value);
  delay(1000);
  if (lowState == LOW)
  {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print ("IR DETECTED");
    delay(1500);
    Serial1.println("\r\nIR DETECTED: ");
    delay(1000);
  }
  if (highState == LOW)
  {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print ("PIEZO DETECTED");
    delay(1500);
    Serial1.println("\r\nPIEZO DETECTED: ");
    delay(1000);
  }
}
