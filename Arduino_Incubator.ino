#define USE_ARDUINO_INTERRUPTS true 
#include <PulseSensorPlayground.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Wire.h>
#include <Bonezegei_DHT11.h>

// LCD settings
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensor settings
const int PulseWire = A0;
const int LED_3 = 2;
const int DHT_PIN = 4;
const int RELAY_PIN = 7;
int Threshold = 550;

// Sensor objects
PulseSensorPlayground pulseSensor;
Bonezegei_DHT11 dht(DHT_PIN);

// Heart rate calculation variables
const int numReadings = 10;  
int bpmReadings[numReadings];
int readIndex = 0;
int total = 0;
int averageBPM = 0;
unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {
    Serial.begin(115200);

    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 1);
    lcd.print("INCUBATOR READY");

    // Set up warning LED
    pinMode(LED_3, OUTPUT);
    digitalWrite(LED_3, LOW);
    
    // Set up relay
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);

    // Set up pulse sensor
    pulseSensor.analogInput(PulseWire);
    pulseSensor.setThreshold(Threshold);
    
    if (pulseSensor.begin()) {
        Serial.println("Pulse Sensor started!");
    } else {
        Serial.println("Pulse Sensor failed to start.");
    }

    // Start DHT11 sensor
    dht.begin();

    // Initialize BPM readings array
    for (int i = 0; i < numReadings; i++) {
        bpmReadings[i] = 0;
    }
}

void loop() {
    // Detect heartbeat
    if (pulseSensor.sawStartOfBeat()) {
        int myBPM = pulseSensor.getBeatsPerMinute();
        total = total - bpmReadings[readIndex];
        bpmReadings[readIndex] = myBPM;
        total = total + bpmReadings[readIndex];
        readIndex = (readIndex + 1) % numReadings;
        Serial.print("Current BPM: ");
        Serial.println(myBPM);
    }

    // Update BPM display every 2 seconds
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        averageBPM = total / numReadings;
        Serial.print("Average BPM: ");
        Serial.println(averageBPM);

        lcd.setCursor(0, 0);
        lcd.print("BPM: ");
        lcd.print(averageBPM);
        lcd.print("   ");  

        if (averageBPM > 110 || averageBPM < 30) {
            digitalWrite(LED_3, HIGH);
        } else {
            digitalWrite(LED_3, LOW);
        }
        previousMillis = currentMillis;
    }

    // Read temperature and humidity from DHT11
    if (dht.getData()) {                         
        float tempC = dht.getTemperature();      
        int humidity = dht.getHumidity();        

        Serial.print("Temperature: ");
        Serial.print(tempC);
        Serial.print("°C  Humidity: ");
        Serial.println(humidity);

        lcd.setCursor(0, 1);
        lcd.print("T:");
        lcd.print(tempC);
        lcd.print("C H:");
        lcd.print(humidity);
        lcd.print("%  ");

        if ((humidity >= 20 && humidity <= 60) || (tempC < 36.5)) {
            digitalWrite(RELAY_PIN, LOW);
        } else {
            digitalWrite(RELAY_PIN, HIGH);
        }
    }
    delay(500);
}
