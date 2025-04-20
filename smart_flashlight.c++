// self-adjusting "flashlight" 
// adjusts the brightness of the LED depending on how bright the surroundings are

const int flashlight = 8;
const int sensor_pin = A1;

int sensor_value = 0; 
int flashlight_brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(flashlight, OUTPUT);
}

void loop() {
  sensor_value = analogRead(sensor_pin);

  // Map brightness: brighter environment = dimmer LED
  flashlight_brightness = constrain(255 - (sensor_value * 255 / 1023), 0, 255);

  analogWrite(flashlight, flashlight_brightness);

  // Print debug values
  Serial.print("Sensor: ");
  Serial.print(sensor_value);
  Serial.print(" | Brightness: ");
  Serial.println(flashlight_brightness);

  delay(50);
}
