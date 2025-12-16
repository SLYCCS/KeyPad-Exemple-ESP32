#include <Keypad.h>
const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
uint8_t colPins[COLS] = { 16, 4, 2, 15 };
uint8_t rowPins[ROWS] = { 19, 18, 5, 17 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
const String password = "123A"; // Contraseña de ejemplo
String inputPassword;
void setup() {
  Serial.begin(9600);
  Serial.println("Introduce la contraseña:");
}
void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.print(key);
    if (key == '#') {
      if (inputPassword == password) {
        Serial.println("\nAcceso concedido.");
      } else {
        Serial.println("\nAcceso denegado.");
      }
      inputPassword = ""; // Reinicia
    } else if (key == '*') {
      inputPassword = ""; // Borra entrada
      Serial.println("\nEntrada borrada.");
    } else {
      inputPassword += key; // Añade carácter
    }
  }
}
