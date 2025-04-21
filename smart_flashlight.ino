// Self-adjusting "flashlight"
// This project adjusts the brightness of an LED based on ambient light levels.
// The brighter the surroundings, the dimmer the LED becomes, and vice versa.

const int flashlight = 9;      // PWM-capable pin connected to the LED
const int sensor_pin = A1;     // Analog pin connected to the LDR voltage divider

int sensor_value = 0;          // Stores the raw analog value from the LDR
int flashlight_brightness = 0; // Stores the calculated brightness for the LED

void setup() {
  Serial.begin(9600);          // Start serial communication for debugging
  pinMode(flashlight, OUTPUT); // Set the flashlight pin as an output
}

void loop() {
  // Read the current light level from the LDR
  sensor_value = analogRead(sensor_pin);

  // Map sensor value (from ambient light) to LED brightness:
  // In dark conditions (~200), LED will be at full brightness (255)
  // In bright conditions (~800), LED will be dim or off (0)
  flashlight_brightness = map(sensor_value, 200, 800, 255, 0);

  // Adjust the 200 and 800 based on what values you see from analogRead() in your room's lighting.


  // Ensure the brightness value stays within 0–255 range
  flashlight_brightness = constrain(flashlight_brightness, 0, 255);

  // Apply the brightness to the LED using PWM
  analogWrite(flashlight, flashlight_brightness);

  // Output sensor and brightness values to the Serial Monitor
  Serial.print("Sensor: ");
  Serial.print(sensor_value);
  Serial.print(" | Brightness: ");
  Serial.println(flashlight_brightness);

  // Short delay to stabilize readings and reduce flicker
  delay(50);
}
