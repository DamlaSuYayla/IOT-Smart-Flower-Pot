#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>

#define SOIL_WET 550
#define SOIL_DRY 1200
#define SENSOR_POWER_PIN 12
#define SENSOR_PIN A0
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2
#define LED_PIN 6
#define NUM_LEDS 16

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight(); 
  pinMode(SENSOR_POWER_PIN, OUTPUT);
  pixels.begin();
  lcd.clear();
  lcd.setCursor(0, 0);
  delay(2000);
}

void loop() {
  digitalWrite(SENSOR_POWER_PIN, HIGH);
  int moisture = readSensor();

  lcd.clear();
  lcd.setCursor(0, 0);


  if (moisture > SOIL_DRY) {
    lcd.setCursor(0,0);
    lcd.print("Bana Su Ver");
    Serial.print("Toprak Nem Seviyesi: ");
    Serial.println(moisture);
    setLEDColor(255, 0, 0);  // Kırmızı
  } else if (moisture >= SOIL_WET && moisture < SOIL_DRY) {
    lcd.setCursor(0,0);
    lcd.print("Su Istemiyorum");
    Serial.print("Toprak Nem Seviyesi: ");
    Serial.println(moisture);
    setLEDColor(0, 150, 0);  // Yeşil
  } else {
    lcd.setCursor(0,0);
    lcd.print("Su cok fazla!!");
    Serial.print("Toprak Nem Seviyesi: ");
    Serial.println(moisture);
    setLEDColor(0, 0, 255);  // Mavi
  }

  digitalWrite(SENSOR_POWER_PIN, LOW);
  delay(500);
}

int readSensor() {
  int val = analogRead(SENSOR_PIN);
  return val;
}

void setLEDColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.show();
}
