# 🌡️ Arduino-Based Radiant Warmer 

An open-source **Arduino-controlled radiant warmer** designed for **neonatal thermoregulation**. This project integrates **temperature and humidity monitoring, heart rate sensing, and automated heating** to create a cost-effective incubator solution for newborn care. 🍼✨

---

## 📷 Project Overview

![IMG-20250327-WA0026](https://github.com/user-attachments/assets/e5eed169-ba93-4d97-8595-a24602d9cfb2)

🔹 **Microcontroller**: Arduino Uno  
🔹 **Heating Element**: 100W Lamp  
🔹 **Sensors**: DHT11 (Temperature & Humidity), Pulse Sensor (Heart Rate)  
🔹 **Display**: 16x2 LCD with I2C  
🔹 **User Alerts**: LED indicators for abnormal heart rate  
🔹 **Automated Control**: Relay-based heating system  

---

## 🛠️ Features

✅ **Automated Temperature Regulation** – 100W lamp activates when temp < 36.5°C  
✅ **Real-time Monitoring** – LCD displays temperature, humidity, and BPM  
✅ **Heart Rate Detection** – Alerts for abnormal BPM levels  
✅ **Energy Efficient** – Controlled heating to prevent overheating  
✅ **Cost-Effective & Scalable** – Ideal for research and educational use  

---

## 🔩 Hardware & Components

| Component         | Quantity | Description |
|------------------|---------|------------|
| Arduino Uno      | 1       | Microcontroller |
| 100W Lamp       | 1       | Heating element |
| DHT11 Sensor    | 1       | Temperature & Humidity monitoring |
| Pulse Sensor    | 1       | Heart rate measurement |
| LCD 16x2 (I2C)  | 1       | Display module |
| Relay Module    | 1       | Heating control |
| LED Indicator   | 1       | Abnormal BPM alert |
| Power Supply    | 1       | 9V or USB |

📌 **Wooden Frame & Assembly**:  
- Custom-cut wooden enclosure to simulate the incubator
  
![IMG-20250327-WA0025](https://github.com/user-attachments/assets/973be7a1-51c9-4977-88d9-70e810e28438)

---

## 🔌 Circuit Diagram

![Circuit Diagram](https://github.com/user-attachments/assets/c86dadf6-2d86-406f-ac28-192027e8f97c)

---

## 🚀 How to Set Up

### **1️⃣ Hardware Setup**
- Connect all components as per the **circuit diagram**  
- Secure the **lamp and sensors** in place  
- Ensure **proper power supply**  

### **2️⃣ Software Installation**
- Install **Arduino IDE** & required libraries:  
  ```bash
  Install LiquidCrystal_I2C.h
  Install PulseSensorPlayground.h
  Install Bonezegei_DHT11.h
  ```

### **3️⃣ Operating the Incubator**
- **Automatic Mode** → System maintains temperature and humidity automatically  
- **Heart Rate Monitoring** → LED alert for abnormal BPM readings  

---

## 🎉 Special Thanks
A huge thank you to my incredible team for their dedication and hard work:  
**Anas Mohamed, Ward Selkini, Hassan Badawy, and Ziad Osama.** This project wouldn’t have been possible without their amazing contributions in **software development, hardware assembly, and electrical integration**! 👏  

---

## 📫 Contact
Email: Mostafahany4705@gmail.com <br>
LinkedIn: www.linkedin.com/in/mostafahany4705
