// =====================================================
// CARRITO ROBÓTICO EDUCATIVO - ESPOL
// Arduino Nano + L298N
// =====================================================

// -------------------------
// Pines del driver L298N
// -------------------------
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;

// -------------------------
// LEDs indicadores
// -------------------------
const int LED_ROJO     = 8;
const int LED_AMARILLO = 9;
const int LED_VERDE    = 10;

// -------------------------
// Buzzer
// -------------------------
const int BUZZER = 2;


// =====================================================
// CONFIGURACIÓN INICIAL
// =====================================================
void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  // Mantener los motores detenidos al iniciar
  detener();

  // Señal visual y sonora de inicio
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_AMARILLO, HIGH);
  digitalWrite(LED_VERDE, HIGH);

  tone(BUZZER, 1000, 300);

  delay(300);

  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);

  delay(700);
}


// =====================================================
// FUNCIONES DE MOVIMIENTO
// =====================================================

// Movimiento hacia adelante
void adelante() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// Movimiento hacia atrás
void atras() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// Detener motores
void detener() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// Giro hacia la derecha
void derecha() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// Giro hacia la izquierda
void izquierda() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// =====================================================
// SECUENCIA PRINCIPAL
// =====================================================
void loop() {

  // ---------------------------------
  // 1. Avanzar durante 3 segundos
  // ---------------------------------
  digitalWrite(LED_ROJO, HIGH);

  adelante();

  delay(3000);


  // ---------------------------------
  // 2. Giro a la derecha
  // ---------------------------------
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, HIGH);

  tone(BUZZER, 1500, 150);

  derecha();

  delay(900);


  // ---------------------------------
  // 3. Avanzar durante 2.5 segundos
  // ---------------------------------
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, HIGH);

  adelante();

  delay(2500);


  // ---------------------------------
  // 4. Giro a la izquierda
  // ---------------------------------
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, HIGH);

  tone(BUZZER, 1500, 150);

  izquierda();

  delay(900);


  // ---------------------------------
  // 5. Detener el carrito
  // ---------------------------------
  detener();

  digitalWrite(LED_ROJO, LOW);

  delay(300);
}
