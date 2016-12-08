//Llamado de librerias para almacenar datos en SD
#include <SPI.h>
#include <SD.h>

File archivoTxt;
int x = 0;

void setup() {
  //Inicialización comunicación serial
  //Serial.begin(250000);
  //Revisión de SD
  if (!SD.begin(4)) {
    return;
  }
  //Inicialización del documento
  archivoTxt = SD.open("datos.txt", FILE_WRITE);
  archivoTxt.println("ME CONECTE");
  archivoTxt.close();
}

void loop() {
  //Lectura de datos del serial
  while (Serial.available()) {
    String valorLectura = Serial.readStringUntil("\n");
    x++;
    archivoTxt.println(valorLectura);
    Serial.flush();
  }
  //if (x == 10) {
    archivoTxt.close();
 // }
}
