
#include <SPI.h>
#include <RF24.h>
#include <ESP32Servo.h>

// nRF24L01 connections
RF24 radio(4, 5);  // CE, CSN

const byte address[6] = "ROBOT";

// Servo signal pins
const int servoPins[4] = {13, 14, 25, 26};

Servo servos[4];

// Data received wirelessly
struct ControlData {
  uint8_t angle[4];
};

ControlData controls = {{90, 90, 90, 90}};

void setup() {
  Serial.begin(115200);

  // Set up the four servos
  for (int i = 0; i < 4; i++) {
    servos[i].setPeriodHertz(50);
    servos[i].attach(servoPins[i], 500, 2500);
    servos[i].write(90);
  }

  // Start wireless receiver
  if (!radio.begin()) {
    Serial.println("nRF24L01 not detected!");
    while (true) {
      delay(1000);
    }
  }

  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(76);
  radio.openReadingPipe(1, address);
  radio.startListening();

  Serial.println("Robot controller ready");
}

void loop() {
  if (radio.available()) {
    ControlData incoming;

    while (radio.available()) {
      radio.read(&incoming, sizeof(incoming));
    }

    // Reject invalid servo angles
    bool valid = true;

    for (int i = 0; i < 4; i++) {
      if (incoming.angle[i] > 180) {
        valid = false;
      }
    }

    if (valid) {
      controls = incoming;

      for (int i = 0; i < 4; i++) {
        servos[i].write(controls.angle[i]);
      }

      Serial.printf(
        "Servos: %u, %u, %u, %u\n",
        controls.angle[0],
        controls.angle[1],
        controls.angle[2],
        controls.angle[3]
      );
    }
  }
}
