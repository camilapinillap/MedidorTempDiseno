int led = 6;
int pul = 7;
int buzzer = 5;
int ledAzul = 11;
int ledVerde = 10;
int ledRojo = 9;
bool estadoBuzzer = false;
#define PIN_SENSOR A0
int ValorTemp, ValorMv, ValorPWM;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pul, INPUT);
  Serial.begin(9600);
}
void loop() {
  ValorTemp = analogRead(PIN_SENSOR);

  ValorMv = map(ValorTemp, 0, 1023, 0, 5000);
  ValorPWM = ValorMv / 10;
  Serial.print(ValorPWM);
  if (ValorPWM <= 15) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    estadoBuzzer = false;
  }
  if (ValorPWM > 15 && ValorPWM < 26) {
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    estadoBuzzer = false;
  }
  if (ValorPWM >= 27) {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, HIGH);
    estadoBuzzer = true; 
    digitalWrite(led, HIGH);
  }
  Serial.print(" ---- Pulsador: ");Serial.println(digitalRead(pul));
  if (digitalRead(pul) == HIGH && estadoBuzzer == true) {
    estadoBuzzer = false;
    digitalWrite(buzzer, LOW);
    delay(5000);
  }
}