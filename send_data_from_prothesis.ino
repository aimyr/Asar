#include <WiFi.h>
#include <WebServer.h>
#include "MPU9250.h"
#include "eeprom_utils.h"
#include <Wire.h>

MPU9250 mpu;

// Данные для подключения к WiFi
const char* ssid = "Aimer";
const char* password = "aimerbek";

// Пины для 4 кнопок
int buttonPins[4] = {0, 1, 2, 3};  
WebServer server(80);  // HTTP-сервер на порту 80

// Инициализация переменных для углов
float pitch = 0.0, roll = 0.0, yaw = 0.0;
const float deadzone = 5.0;
const int EEPROM_START_ADDRESS = 0;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Инициализация пинов для кнопок
    for (int i = 0; i < 4; i++) {
        pinMode(buttonPins[i], INPUT_PULLDOWN);  // Кнопки с подтяжкой к VCC
    }

    // Проверка подключения MPU9250
    if (!mpu.setup(0x68)) {
        while (1) {
            Serial.println("MPU connection failed. Please check your connection.");
            delay(5000);
        }
    }

    // Проверяем наличие данных в EEPROM и загружаем калибровку
    EEPROM.begin(0x80);
    loadCalibration();
    Serial.println("Calibration data loaded from EEPROM.");

    // Настройка маршрутов HTTP-сервера
    server.on("/", handleRoot);  // Основная страница
    server.on("/data", handleData);  // Отправка данных с сенсоров и кнопок
    server.begin();
}

void loop() {
    server.handleClient();
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() - prev_ms > 25) {  // Обновляем каждые 25 мс
            pitch = mpu.getPitch();
            roll = mpu.getRoll();
            
            // Вывод значений в Serial Monitor
            Serial.print("Pitch: ");
            Serial.print(pitch, 2);  // Вывод pitch с точностью до 2 знаков
            Serial.print(", Roll: ");
            Serial.println(roll, 2);
            for (int i = 0; i < 4; i++) {
        if (digitalRead(buttonPins[i]) == 1) {  // Кнопка нажата (LOW)
            Serial.print("Button ");
            Serial.print(i);
            Serial.println(" pressed");}}  // Вывод roll с точностью до 2 знаков
            
            prev_ms = millis();
        }
    }
}

// Обработка запроса к главной странице
void handleRoot() {
    server.send(200, "text/plain", "MPU9250 and Button Status Server");
}

// Обработка запроса на данные
void handleData() {
    String command = "";
    
    // Обрабатываем углы
    if (pitch > 15.0 + deadzone) {
        command = "DOWN";
    } else if (pitch < -15.0 - deadzone) {
        command = "UP";
    }
    
    if (roll > -75.0 + deadzone) {
        command = "LEFT";
    } else if (roll < -105.0 - deadzone) {
        command = "RIGHT";
    }
     for (int i = 0; i < 4; i++) {
        if (digitalRead(buttonPins[i]) == 1) {  // Кнопка нажата (LOW)

            if (i == 2){
                command = "LEFT_CLICK";
                Serial.println("LEFT_CLICK");
            } 
            if (i == 3){
              Serial.println("RIGHT_CLICK");
              command = "RIGHT_CLICK";
            } 
        }}
    // Обрабатываем кнопки

    
    // Отправка команды клиенту и вывод в Serial Monitor
    server.send(200, "text/plain", command);
    Serial.println("Command sent: " + command);  // Дублирование команды в Serial
}
