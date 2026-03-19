#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>

Servo esc;
Servo steering;

typedef struct struct_message {
    char a[32];
    int b;
    int c;
    bool d;
} struct_message;

struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(myData.a);
  Serial.print("Speed: ");
  Serial.println(myData.b);
  Serial.print("Steering: ");
  Serial.println(myData.c);
  Serial.print("Bool: ");
  Serial.println(myData.d);
  Serial.println();
}
 
void setup() {
  Serial.begin(115200);
  steering.attach(12);
  esc.attach(14);
  esc.write(1000);

  delay(4000);
  esc.write(1000);
  delay(1000);
  Serial.println("Startup successful");

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("Receiver ready");
}
 
void loop() {
  if (myData.b > 0) {
      esc.write(1300);
  }
  else {
    esc.write(1000);
  }

  steering.write(myData.c);
}
