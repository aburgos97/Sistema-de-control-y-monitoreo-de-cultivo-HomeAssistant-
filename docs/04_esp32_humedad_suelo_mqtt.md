# ESP32 + Sensor de Humedad de Suelo (MQTT)

## Hardware
- ESP32 DevKitC (o similar)
- Sensor capacitivo de humedad de suelo (3.3V)
- 3 cables Dupont
- Fuente USB 5V

## Opción A: Firmware propio (Arduino) publicando a MQTT
1. Carga el sketch `esp32/mqtt_humedad_suelo/esp32_soil_moisture_mqtt.ino`.
2. Edita:
   - WIFI_SSID / WIFI_PASS
   - MQTT_HOST / MQTT_PORT / MQTT_USER / MQTT_PASS
   - TOPIC (ej: `cultivo/suelo/1`)
3. Flashea y verifica que publique cada N segundos un porcentaje (0–100).

## Opción B: ESPHome con sección `mqtt:`
Si prefieres no programar, usa `esp32/esphome/esp32_soil_moisture.yaml`. Cambia:
- `wifi: ssid/password`
- `mqtt: broker/username/password`
- Ajusta `filters:` y la calibración para que la lectura sea estable y en %.

## Lado Home Assistant (escucha)
Define el sensor MQTT en `homeassistant/sensors/mqtt_humedad_suelo.yaml` para consumir el tópico del ESP32.
