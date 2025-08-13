# Troubleshooting

- **No ves sensores de Pulse?**
  - Revisa `x-api-key` y `pulse_resource` en `secrets.yaml`.
  - Prueba la URL en un navegador/API client.
  - Sube `scan_interval` (no es necesario pedir datos cada pocos segundos).

- **ESP32 no publica a MQTT**
  - Verifica credenciales y broker (IP/puerto 1883).
  - Comprueba con un cliente MQTT (ej. MQTT Explorer) si llegan mensajes.

- **Broadlink no aprende IR**
  - Asegura cobertura de red y que HA llega a la IP del RM4 Pro.
  - Intenta aprender desde la UI de la integración Broadlink.

- **Tuya no sincroniza dispositivos**
  - Revisa el proyecto Tuya IoT y la vinculación con la app correcta.
