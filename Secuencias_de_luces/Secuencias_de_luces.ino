
const int SOS_BTN = 4;
const int SIRENA_BTN = 3;
const int KIT_BTN = 2;

int LEDS[] = { 13, 12, 11, 10, 9, 8, 7 };

void setup() {
  // Configuramos el puerto serial a
  // una velocidad de 115200 baudios
  // (bits por segundo)
  Serial.begin(115200);

  // Configuramos los LEDs 0-6 como
  // las salidas
  for (int i; i < 8; i++) {
    pinMode(LEDS[i], OUTPUT);
  }

  // Configuramos los pines
  // de los botones como entradas
  pinMode(SOS_BTN, INPUT);
  pinMode(SIRENA_BTN, INPUT);
  pinMode(KIT_BTN, INPUT);

}  // Fin del void setup()

void loop() {

  // Si el botón de SOS es presionado,
  if (digitalRead(SOS_BTN) == HIGH) {
    // ejecuta esto
    Serial.println("El botón SOS funciona");
    for (int i = 0; i < 8; i++) {
      digitalWrite(LEDS[i], HIGH);
    }
    delay(400);
    for (int i = 0; i < 8; i++) {
      digitalWrite(LEDS[i], LOW);
    }
    delay(400);

    for (int i = 0; i < 8; i++) {
      digitalWrite(LEDS[i], HIGH);
    };
    delay(800);
    for (int i = 0; i < 8; i++) {
      digitalWrite(LEDS[i], LOW);
    }
    delay(800);

    for (int i = 0; i < 8; i++) {
      digitalWrite(LEDS[i], HIGH);
    }
    delay(400);
    for (int i = 0; i < 8; i++) {
      digitalWrite(LEDS[i], LOW);
    }
    delay(400);
  }
  
 // Si el botón SIRENA funciona,
if (digitalRead(SIRENA_BTN) == HIGH) {
    // ejecuta esto...
    Serial.println("El botón SIRENA funciona");
    
    // Patrón de torreta de ambulancia (ciclo durante 5 segundos)
    unsigned long inicio = millis();
    while (millis() - inicio < 5000) { // Ejecutar por 5 segundos
        // Encender LEDs impares (grupo 1)
        for (int i = 0; i < 7; i += 2) {
            digitalWrite(LEDS[i], HIGH);
        }
        // Apagar LEDs pares (grupo 2)
        for (int i = 1; i < 7; i += 2) {
            digitalWrite(LEDS[i], LOW);
        }
        delay(100); // Retener 100 ms
        
        // Invertir el patrón
        for (int i = 0; i < 7; i += 2) {
            digitalWrite(LEDS[i], LOW);
        }
        for (int i = 1; i < 7; i += 2) {
            digitalWrite(LEDS[i], HIGH);
        }
        delay(100); // Retener 100 ms
    }
    
    // Apagar todos los LEDs al finalizar
    for (int i = 0; i < 7; i++) {
        digitalWrite(LEDS[i], LOW);
    }
}
// Si el botón KIT funciona;
  if (digitalRead(KIT_BTN) == HIGH) {
    // ejecuta esto...
    Serial.println("El botón KIT funciona");
    for (int i = 0; i < 7; i++) {
      digitalWrite(LEDS[i], HIGH);
      delay(200);
      digitalWrite(LEDS[i], LOW);
    }

    digitalWrite(LEDS[6], HIGH);
    delay(100);
    digitalWrite(LEDS[6], LOW);
    delay(100);

    for (int i = 7; i > 0; i--) {
      digitalWrite(LEDS[i], HIGH);
      delay(200);
      digitalWrite(LEDS[i], LOW);
    }
    digitalWrite(LEDS[0], HIGH);
    delay(500);
    digitalWrite(LEDS[0], LOW);
    delay(500);
  }
