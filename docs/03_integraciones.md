# Integraciones

## BlueLab Guardian WiFi
Usaremos la integración comunitaria de BlueLab Guardian WiFi mantenida por la comunidad. Recomendado instalarla vía **HACS** (Home Assistant Community Store).
- En HACS → Integrations → “+” → busca “BlueLab” o agrega el repositorio manualmente.
- Reinicia Home Assistant y agrega la integración desde **Configuración → Dispositivos y servicios**.
- Se crearán entidades para pH, EC, T°, etc., según tu dispositivo.

**Crédito del proyecto:** ver `docs/09_creditos.md`.

---

## Pulse (API REST)
Pulse publica datos vía REST. En `homeassistant/sensors/pulse.yaml` hay ejemplos que:
- Consultan `https://api.pulsegrow.com/devices/<DEVICE_ID>/recent-data`
- Envían `x-api-key` en headers (usa `!secret`)
- Exponen VPD, T°, Humedad, CO₂, etc.
- Ajusta `scan_interval` responsablemente.

---

## Broadlink RM4 Pro
Integración nativa:
1. **Configuración → Dispositivos y servicios → + Agregar integración → Broadlink**
2. Ingresa la IP del RM4 Pro (reserva DHCP recomendable).
3. Aprende comandos IR/RF desde la UI o usa flujos de Node-RED (`examples/node_red_flows.json`).

Usos típicos: aire acondicionado (IR), humidificador/deshumidificador (IR o enchufe RF).

---

## Tuya (enchufes inteligentes)
Integración oficial Tuya:
1. Crea cuenta Tuya IoT y vincula la app (Smart Life/Tuya).
2. Agrega la integración Tuya en Home Assistant.
3. Maneja ON/OFF de equipos como humidificador/extractor.

---

## MQTT (Mosquitto)
Para sensores propios (ej. ESP32 humedad de suelo):
1. Instala el add-on **Mosquitto broker**.
2. Crea usuario/clave MQTT en Home Assistant.
3. Publica desde tu ESP32 al tópico elegido (ej.: `cultivo/suelo/1`).
4. Define el `sensor:` MQTT en `homeassistant/sensors/mqtt_humedad_suelo.yaml`.
