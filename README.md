# Sistema de Monitoreo y Control para Cultivo con Home Assistant

Guía práctica, de bajo costo y sin necesidad de programar, para montar un sistema de **monitoreo** (VPD, T°, humedad, CO₂, humedad de suelo) y **control** (humidificador, deshumidificador, aires, extractores) usando **Home Assistant** en una Raspberry Pi.

**Puntos fuertes**
- Flexibilidad de Home Assistant + integraciones de la comunidad.
- Presupuesto bajo y componentes fáciles de conseguir.
- Recetas listas: Pulse (REST), BlueLab Guardian WiFi (integración comunitaria), ESP32 (humedad de suelo por MQTT), Broadlink RM4 Pro, Tuya (enchufes).

## Índice
1. [Instalación HAOS](docs/01_instalacion_haos_raspberry.md)
2. [Add-ons básicos](docs/02_addons_basicos.md)
3. [Integraciones (BlueLab, Pulse, Broadlink, Tuya, MQTT)](docs/03_integraciones.md)
4. [Sensor humedad de suelo con ESP32 + MQTT](docs/04_esp32_humedad_suelo_mqtt.md)
5. [Dashboard Lovelace](docs/05_dashboard_lovelace.md)
6. [Automatizaciones](docs/06_automatizaciones.md)
7. [Troubleshooting](docs/07_troubleshooting.md)
8. [Privacidad y secrets](docs/08_privacidad_y_secrets.md)
9. [Créditos](docs/09_creditos.md)

> **Privacidad:** No incluyas IPs reales ni claves en el repo. Usa `secrets.yaml` como se muestra en `homeassistant/secrets.example.yaml`.
