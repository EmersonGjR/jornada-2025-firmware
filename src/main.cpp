#include <Arduino.h>
#include "service_app.h"


/* Entry point for the example */
void setup(void)
{
  /* Initialize the communication interfaces */
  Serial.begin(115200);
  setup_BLE();
  setup_bme688();
}

/* Function that is looped forever */
void loop(void)
{
 loop_BME();
}