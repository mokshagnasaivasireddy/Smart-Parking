#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define ENTRY_IR 2
#define EXIT_IR 3
#define ENTRY_SERVO_PIN 6
#define EXIT_SERVO_PIN 5

MFRC522 rfid(SS_PIN, RST_PIN);
Servo entryGate;
Servo exitGate;

String validUID = "E2:9A:6F:05";  // Replace with your actual UID

bool entrySent = false;
bool exitSent = false;
bool waitingForPayment = false;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  
  SPI.begin();
  rfid.PCD_Init();

  pinMode(ENTRY_IR, INPUT_PULLUP);  // Use pull-up resistors
  pinMode(EXIT_IR, INPUT_PULLUP);

  entryGate.attach(ENTRY_SERVO_PIN);
  exitGate.attach(EXIT_SERVO_PIN);

  entryGate.write(0);
  exitGate.write(0);

  Serial.println("✅ Parking System Ready...");
}

void loop() {
  // ENTRY DETECTION
  if (digitalRead(ENTRY_IR) == LOW && !entrySent) {
    Serial.println("ENTRY_DETECTED");
    entrySent = true;
    delay(9000);
    entryGate.write(90);
    delay(3000);
    entryGate.write(0);
    delay(1000);
  }
  
  if (digitalRead(ENTRY_IR) == HIGH) {
    entrySent = false;
  }

  // EXIT DETECTION
  if (digitalRead(EXIT_IR) == LOW && !exitSent) {
    Serial.println("EXIT_DETECTED");
    Serial.println("WAITING_FOR_PAYMENT");
    exitSent = true;
    waitingForPayment = true;
  }
  
  if (digitalRead(EXIT_IR) == HIGH) {
    exitSent = false;
  }

  // RFID PAYMENT (only check if waiting for payment)
  if (waitingForPayment && rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) uid += "0";
      uid += String(rfid.uid.uidByte[i], HEX);
      if (i < rfid.uid.size - 1) uid += ":";
    }
    uid.toUpperCase();

    Serial.print("RFID:");
    Serial.println(uid);

    if (uid == validUID) {
      Serial.println("PAYMENT_SUCCESS");
      openExitGate();
      waitingForPayment = false;
    } else {
      Serial.println("INVALID_CARD");
    }

    rfid.PICC_HaltA();
  }
  
  delay(100); // Small delay to stabilize
}

void openExitGate() {
  exitGate.write(90);
  delay(3000);
  exitGate.write(0);
}