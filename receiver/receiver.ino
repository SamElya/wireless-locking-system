#include <ESP8266WiFi.h>
#include <espnow.h>

#define led0 5

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    bool sensorValue;
} struct_message;

// Create a struct_message called myData
struct_message myData;

void toggle_leds() {
  digitalWrite(led0, myData.sensorValue == 1 ? HIGH : LOW);

}

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));

  toggle_leds();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  pinMode(led0, OUTPUT);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  
}
