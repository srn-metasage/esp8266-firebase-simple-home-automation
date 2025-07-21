#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "SSID" // Replace with your WiFi SSID
#define WIFI_PASSWORD "PASSWORD" // Replace with your WiFi PASSWORD

#define FIREBASE_HOST "msvv-home-automation-model-default-rtdb.firebaseio.com" // Replace with your FIREBASE CREDENTIALS
#define FIREBASE_AUTH "AIzaSyByEadK5vTrCsO3s3ZHrK34o9dzaRcPnrA" // Replace with your FIREBASE CREDENTIALS

FirebaseData fbdo;

int relaypin1 = 5;
int relaypin2 = 4;
int conPin = 2;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(relaypin1, OUTPUT);
  pinMode(relaypin2, OUTPUT);
  pinMode(conPin, OUTPUT);
  digitalWrite(conPin, LOW);
  delay(200);
  digitalWrite(conPin, HIGH);
  delay(150);
  digitalWrite(conPin, LOW);
  delay(150);
  digitalWrite(conPin, HIGH);
  delay(150);
  digitalWrite(conPin, LOW);
  delay(150);
  digitalWrite(conPin, HIGH);
  delay(150);
  digitalWrite(conPin, LOW);
  delay(150);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(conPin, HIGH);
    delay(150);
    digitalWrite(conPin, LOW);
    delay(150);
    Serial.print(".");
  }
  Serial.println("\n Connected to WiFi");
  digitalWrite(conPin, HIGH);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  if (Firebase.getInt(fbdo, "/relay1state")) {
    int relay1value = fbdo.intData();
    digitalWrite(relaypin1, relay1value);
  } else {
    Serial.print("RELAY 1 ERR");
    Serial.println(fbdo.errorReason());
  }

  if (Firebase.getInt(fbdo, "/relay2state")) {
    int relay2value = fbdo.intData();
    digitalWrite(relaypin2, relay2value);
  } else {
    Serial.print("RELAY 2 ERR");
    Serial.println(fbdo.errorReason());
  }
  delay(100);
}
