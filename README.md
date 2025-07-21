## ESP8266 Firebase Home Automation

This project demonstrates how to build a simple WiFi-based home automation system using an ***ESP8266 NodeMCU**, **Firebase Realtime Database**, and a **web-based control portal**. It allows you to remotely control two relays (e.g., lights, fans, etc.) in real-time via Firebase.

---

## Features

- Control two electrical appliances via WiFi
- Real-time state updates using Firebase Realtime Database
- Visual feedback via onboard LED for connection status
- Firebase integration with minimal setup
- Easily extendable for more relays or sensors
- Frontend web portal for user interaction

---

## Hardware Requirements

| Component                     | Quantity |
|-------------------------------|----------|
| ESP8266 NodeMCU               | 1        |
| 2-Channel Relay Module        | 1        |
| LED (optional - status LED)   | 1        |
| Jumper Wires                  | As needed|
| Breadboard (optional)         | 1        |
| USB Cable (Micro USB)         | 1        |

---

## Software Requirements

- Arduino IDE (with ESP8266 board installed)
- [FirebaseESP8266 library](https://github.com/mobizt/Firebase-ESP8266)
- Firebase Realtime Database (Free tier works)
- Firebase-compatible Web Portal (HTML + JS using Firebase SDK)

---

## Pin Mapping

| Device       | NodeMCU Pin |
|--------------|-------------|
| Relay 1      | D1 (GPIO5)   |
| Relay 2      | D2 (GPIO4)   |
| Status LED   | D4 (GPIO2)   |

---

## Firebase Setup

1. Go to [Firebase Console](https://console.firebase.google.com/)
2. Create a new project
3. Enable **Realtime Database**
4. Under **Rules**, replace with:
   ```json
   {
     "rules": {
       ".read": true,
       ".write": true
     }
   }
⚠️ Note: This allows public access — use only for testing. For production, implement user authentication.
5. Enable Anonymous Authentication (optional but safer than open access)
6. Go to Project Settings > General and copy:
   - Database URL
   - Web API Key
7. In the **database root**, add:
   
   ```json
   {
     "relay1state": 0,
     "relay2state": 0
   }
