#include <ESP8266WiFi.h>
#include <espnow.h>

#define btn0 5

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0x84, 0x0D, 0x8E, 0xB0, 0x7B, 0x8D};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  bool sensorValue = 0;
} struct_message;

bool btnValue{}, lastBtnValue{};
// Create a struct_message called myData
struct_message myData;

unsigned long lastTime = 0;  
unsigned long timerDelay = 10;  // send readings timer

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
  
  pinMode(btn0, INPUT_PULLUP);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
 
void loop() {

  btnValue = digitalRead(btn0);
  if (btnValue != lastBtnValue) {
    
    if (digitalRead(btn0) == LOW) {
      Serial.println(btnValue);
      myData.sensorValue = !myData.sensorValue;
      esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
      }
   }
   
  
  delay(100);  
    lastBtnValue = btnValue;
}
