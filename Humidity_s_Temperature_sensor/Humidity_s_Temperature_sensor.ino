#include "DHT.h"
int DHTPIN =  8 ;    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
int STATE_HUMIDITY_TEMP = 1;
void getTempHumidity(int DHTPIN) {
  if (STATE_HUMIDITY_TEMP == 1) {
    delay(2000);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
  }
  else {
    Serial.println("No data");
  }
}
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  getTempHumidity(DHTPIN);
}
