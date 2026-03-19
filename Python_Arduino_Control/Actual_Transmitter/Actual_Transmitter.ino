#include <esp_now.h>
#include <WiFi.h>

int SPEED, SERVO_ANGLE;
uint8_t broadcastAddress[] = {0xCC, 0x7B, 0x5C, 0x28, 0xD0, 0x48};

typedef struct struct_message {
  char a[32];
  int b;
  int c;
  bool d;
} struct_message;

struct_message myData;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {
  if (!Serial.available()) {
    return;
  }

  String str = Serial.readString();
  str.trim();
  if (str.length() < 3) {
    return;
  }

  SPEED = str.substring(0, 2).toInt();
  SERVO_ANGLE = str.substring(2).toInt();

  strcpy(myData.a, "control");
  myData.b = SPEED;
  myData.c = SERVO_ANGLE;
  myData.d = false;

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }

  delay(25);
}
