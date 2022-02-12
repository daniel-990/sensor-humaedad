
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Definir pines SPI en Arduino
#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET 13

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

void setup() {
 Serial.begin(9600);
 Serial.println("Valor del sensor de humedad");
    
 display.begin(SSD1306_SWITCHCAPVCC); // Inicia el display OLED (Carga Buffer)
 display.clearDisplay(); // Borrar imagen en el OLED
 display.setTextSize(1); // Definir Tamaño del Texto
 display.setTextColor(WHITE); // Definir color del texto. (mono=>Blanco)
 display.setCursor(0,10 ); // Definir posición inicio texto Columna (0) Fila (10)
 display.println("Sensor humedad..."); // Carga la información al buffer
 display.display(); // Actualiza display con datos en Buffer
 delay(2000); // Demora de 2 segundos.

}

void loop() {
  
  //sensor de humendad
  int humidity = analogRead(A0);

  Serial.print("Lectura:");
  Serial.println(humidity);

  //pantalla oled
  /*
   display.clearDisplay(); // Borrar imagen en el OLED
   display.setTextSize(1); // Definir Tamaño del Texto
   display.setTextColor(WHITE); // Definir color del texto. (mono=>Blanco)
   display.setCursor(0,10 ); // Definir posición inicio texto Columna (0) Fila (10)
   display.println("Lectura");
   display.println(humidity); 
   display.display(); // Actualiza display con datos en Buffer
   delay(2000); // Demora de 2 segundos.
  */
  
  if(humidity >= 0 & humidity <= 300){
      Serial.println("Sensor en suelo seco");
   
   display.clearDisplay(); // Borrar imagen en el OLED
   display.setTextSize(1); // Definir Tamaño del Texto
   display.setTextColor(WHITE); // Definir color del texto. (mono=>Blanco)
   display.setCursor(0,10 ); // Definir posición inicio texto Columna (0) Fila (10)
   display.println("suelo seco");
   display.println(humidity); 
   display.display(); // Actualiza display con datos en Buffer
   delay(2000); // Demora de 2 segundos.
  
  } else if(humidity > 301 & humidity <= 700){
      Serial.println("Sensor en suelo húmedo");
      
   display.clearDisplay(); // Borrar imagen en el OLED
   display.setTextSize(1); // Definir Tamaño del Texto
   display.setTextColor(WHITE); // Definir color del texto. (mono=>Blanco)
   display.setCursor(0,10 ); // Definir posición inicio texto Columna (0) Fila (10)
   display.println("suelo humedo"); 
   display.println(humidity); 
   display.display(); // Actualiza display con datos en Buffer
   delay(2000); // Demora de 2 segundos.
      
  }else if(humidity >= 701){
      Serial.println("sensor /agua");

   display.clearDisplay(); // Borrar imagen en el OLED
   display.setTextSize(1); // Definir Tamaño del Texto
   display.setTextColor(WHITE); // Definir color del texto. (mono=>Blanco)
   display.setCursor(0,10 ); // Definir posición inicio texto Columna (0) Fila (10)
   display.println("agua"); 
   display.println(humidity); 
   display.display(); // Actualiza display con datos en Buffer
   delay(2000); // Demora de 2 segundos.
      
  }
  delay(1000);



}
