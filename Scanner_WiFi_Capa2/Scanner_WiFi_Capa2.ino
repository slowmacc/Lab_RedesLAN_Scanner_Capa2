#include "WiFi.h"

void setup() {
  // Iniciamos la comunicación con la computadora a 115200 baudios
  Serial.begin(115200);
  
  // Configuramos el ESP32 en modo Estación (como si fuera un celular)
  WiFi.mode(WIFI_STA); 
  WiFi.disconnect(); // Nos aseguramos de no estar conectados a nada
  delay(100);
  
  Serial.println("Escáner de Redes Iniciado...");
  Serial.print("Mi propia dirección MAC es: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  Serial.println("Escaneando el espectro Wi-Fi (2.4 GHz)...");
  
  // Esta función cuenta cuántas redes detecta la antena
  int n = WiFi.scanNetworks(); 
  
  if (n == 0) {
    Serial.println("No se encontraron redes.");
  } else {
    Serial.print(n);
    Serial.println(" redes detectadas:");
    
    // Imprimimos los datos de cada red encontrada
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(". Red: ");
      Serial.print(WiFi.SSID(i)); // Nombre
      Serial.print(" | MAC (BSSID): ");
      Serial.print(WiFi.BSSIDstr(i)); // Dirección física del router
      Serial.print(" | Señal: ");
      Serial.print(WiFi.RSSI(i)); // Potencia
      Serial.println(" dBm");
      delay(10);
    }
  }
  Serial.println("-----------------------------------------");
  delay(5000); // Espera 5 segundos antes del siguiente escaneo
}