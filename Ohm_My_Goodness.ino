#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// Variable to store the current time in milliseconds
unsigned long currentTime;

void setup(void)
{
  // Start serial communication
  Serial.begin(9600);
  Serial.println("ms,degC"); // Print CSV header

  // Start up the temperature sensors
  sensors.begin();
}

void loop(void)
{
  // Request temperature readings from the sensor
  sensors.requestTemperatures();

  // Record the current time in milliseconds
  currentTime = millis();

  // Read the temperature in degrees Celsius
  float tempC = sensors.getTempCByIndex(0);

  // Print the time and temperature as CSV data
  Serial.print(currentTime);
  Serial.print(",");
  Serial.println(tempC);

  // Delay for a specific interval (e.g., 2000 milliseconds)
  delay(2000);
}
