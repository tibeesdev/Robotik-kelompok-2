#include <SoftwareSerial.h>

SoftwareSerial bluetooth(1,0); //TX RX

const int rodaKanan1 = 6;
const int rodaKanan2 = 7;
const int rodaKiri1 = 8;
const int rodaKiri2 = 9;

char dataBluetooth = 0;

void maju() {
  digitalWrite(rodaKanan1,HIGH);
  digitalWrite(rodaKanan2,LOW);
  digitalWrite(rodaKiri1,HIGH);
  digitalWrite(rodaKiri2,LOW);
}

void mundur() {
  digitalWrite(rodaKanan1,LOW);
  digitalWrite(rodaKanan2,HIGH);
  digitalWrite(rodaKiri1,LOW);
  digitalWrite(rodaKiri2,HIGH);
}

void belokKanan() {
  digitalWrite(rodaKanan1,HIGH);
  digitalWrite(rodaKanan2,HIGH);
  digitalWrite(rodaKiri1,HIGH);
  digitalWrite(rodaKiri2,LOW);
}

void belokKiri() {
  digitalWrite(rodaKanan1,HIGH);
  digitalWrite(rodaKanan2,LOW);
  digitalWrite(rodaKiri1,HIGH);
  digitalWrite(rodaKiri2,HIGH);
}

void stopMotor() {
  digitalWrite(rodaKanan1, LOW);
  digitalWrite(rodaKanan2, LOW);
  digitalWrite(rodaKiri1, LOW);
  digitalWrite(rodaKiri2, LOW);
}

void setup() {
  pinMode(rodaKanan1, OUTPUT);
  pinMode(rodaKanan2, OUTPUT);
  pinMode(rodaKiri1, OUTPUT);
  pinMode(rodaKiri2, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);

  stopMotor();
}

void loop() {
  if (bluetooth.available() > 0) {
    dataBluetooth = bluetooth.read();
    Serial.println(dataBluetooth);

    if (dataBluetooth == 'W') {
      void maju();
    }
    else if (dataBluetooth == 'S') {
      void mundur();
    }
    else if (dataBluetooth == 'D') {
      void belokKanan();
    }
    else if (dataBluetooth == 'A') {
      void belokKiri();
    }
    else if (dataBluetooth == 'Q') {
      void stopMotor();
    }
  }
}
