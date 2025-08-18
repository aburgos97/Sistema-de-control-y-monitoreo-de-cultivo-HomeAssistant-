#include <WiFi.h>
#include <PubSubClient.h>

const char* WIFI_SSID = "TU_WIFI";
const char* WIFI_PASS = "TU_PASS";

const char* MQTT_HOST = "192.168.1.10";
const uint16_t MQTT_PORT = 1883;
const char* MQTT_USER = "usuario_mqtt";
const char* MQTT_PASS = "clave_mqtt";

const char* TOPIC = "cultivo/suelo/1";
const int SOIL_PIN = 34;       // Entrada analógica
const int PUBLISH_EVERY_MS = 10000;

WiFiClient espClient;
PubSubClient client(espClient);

void wifiConnect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void mqttConnect() {
  while (!client.connected()) {
    client.connect("esp32-soil-1", MQTT_USER, MQTT_PASS);
    if (!client.connected()) delay(1000);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(SOIL_PIN, INPUT);
  wifiConnect();
  client.setServer(MQTT_HOST, MQTT_PORT);
  mqttConnect();
}

float readSoilPercent() {
  // Calibración simple: ajusta min/max según tu sensor (valores ADC 0-4095)
  int raw = analogRead(SOIL_PIN);
  int dry = 3000;   // ajustar
  int wet = 1200;   // ajustar
  float pct = 100.0 * (float)(dry - raw) / (float)(dry - wet);
  if (pct < 0) pct = 0;
  if (pct > 100) pct = 100;
  return pct;
}

unsigned long lastPub = 0;

void loop() {
  if (WiFi.status() != WL_CONNECTED) wifiConnect();
  if (!client.connected()) mqttConnect();
  client.loop();

  if (millis() - lastPub > PUBLISH_EVERY_MS) {
    float pct = readSoilPercent();
    char buf[16];
    dtostrf(pct, 4, 1, buf);
    client.publish(TOPIC, buf, true);
    lastPub = millis();
  }
}
