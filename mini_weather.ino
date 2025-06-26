// Pin configuration
const int lm35Pin = A0;           // LM35 temperature sensor connected to A0
const int soilSensorPin = A1;     // Soil moisture sensor connected to A1
const int ledPin = 8;             // LED connected to pin 8

void setup() {
  Serial.begin(9600);             // Start serial communication
  pinMode(ledPin, OUTPUT);        // Set LED pin as output
}

void loop() {
  // Read LM35 sensor
  int tempReading = analogRead(lm35Pin);          // Read from A0
  float voltage = tempReading * (5.0 / 1023.0);    // Convert to voltage
  float temperatureC = voltage * 100.0;            // LM35 gives 10mV per °C

  // Read soil moisture sensor
  int soilMoisture = analogRead(soilSensorPin);   // Read from A1

  // Print data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C | Soil Moisture: ");
  Serial.println(soilMoisture);

  // Control LED: turn ON if soil is dry
  if (soilMoisture > 600) {       // Adjust this threshold if needed
    digitalWrite(ledPin, HIGH);   // Dry soil → LED ON
  } else {
    digitalWrite(ledPin, LOW);    // Moist soil → LED OFF
  }

  delay(1000);  // Delay for 1 second
}
