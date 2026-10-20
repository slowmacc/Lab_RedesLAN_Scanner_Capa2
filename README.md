# Escaner de Redes Wi-Fi con ESP32

Este proyecto consiste en un script desarrollado en C++ para Arduino, diseñado para ejecutarse en un microcontrolador ESP32. Su función principal es realizar un escaneo continuo del espectro radioeléctrico en la banda de 2.4 GHz para detectar redes Wi-Fi cercanas y extraer información clave de cada una.

## Caracteristicas Principales

* Configuracion del ESP32 en modo Estacion (WIFI_STA).
* Obtencion de la direccion MAC propia del dispositivo.
* Escaneo periodico de redes inalambricas circundantes.
* Extraccion de parametros por red detectada:
  * Nombre de la red (SSID).
  * Direccion fisica del enrutador (BSSID / MAC).
  * Potencia de la senal recibida medida en dBm (RSSI).

## Requisitos de Hardware y Software

* **Microcontrolador:** ESP32 (compatible con el modulo ESP-WROOM-32).
* **Entorno de desarrollo:** Arduino IDE con el soporte para placas ESP32 instalado.
* **Librerias:** `WiFi.h` (incluida por defecto en el nucleo de desarrollo del ESP32).

## Estructura del Codigo

* **`setup()`:** Inicializa el puerto serial a una velocidad de 115200 baudios, configura el modo de operacion inalambrica, desconecta cualquier sesion previa e imprime la direccion MAC del microcontrolador.
* **`loop()`:** Ejecuta un bucle infinito que invoca `WiFi.scanNetworks()`, evalua si se encontraron puntos de acceso y lista por el puerto serie el numero total de redes junto con los detalles de cada una, esperando un intervalo de 5 segundos antes de repetir el proceso.

## Instrucciones de Uso

1. Conecta tu tarjeta ESP32 a la computadora mediante un cable USB.
2. Abre el codigo en Arduino IDE.
3. Selecciona la placa y el puerto COM correspondientes en las herramientas de configuracion.
4. Compila y carga el programa en el ESP32.
5. Abre el Monitor Serie a una velocidad de 115200 baudios para visualizar las redes detectadas y la intensidad de su senal en tiempo real.
