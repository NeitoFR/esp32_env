#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>

OneWire oneWire(4);
DallasTemperature sensors(&oneWire);

// Wifi variable
const char *wifi_ssid = "op8t_neito";
const char *wifi_pwd = "tructruc123";

// MQTT variable
const char* influx_host = "192.168.35.190";
const char* influx_token = "7QPHKpQKROwNFI1h9SG6df42YrEwyt9QwqHFX-koB3nEJMQ_Sdk98iFpmDIJ22brojF4OsZpUBfUHlOSVAHG7A==";

WiFiClient espClient;

void setup_wifi()
{
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_pwd);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nWiFi connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void setup()
{
  // Start the Serial Monitor
  Serial.begin(115200);

  // Connect Wifi
  setup_wifi();

  // Setup Influx DB connection

  // Start the DS18B20 sensor
  sensors.begin();
}

void loop()
{
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print("Last temp : ");
  Serial.print(temperatureC);
  Serial.println("ºC");

  // char tempString[8];
  // dtostrf(temperatureC, 1, 2, tempString);

  // char topic[strlen(mqtt_topic) + strlen("/temp")];
  // strcpy(topic, mqtt_topic);
  // strcat(topic, "/temp");

  delay(5000);
}
