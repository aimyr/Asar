#include <Servo.h> 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10);  // RX, TX
Servo sx; 
Servo sy; 

int currentXPosition = 80;  // Текущая позиция сервоприводов по оси X
int currentYPosition = 80;  // Текущая позиция сервоприводов по оси Y

void setup() {
  sx.attach(5);  // Подключаем сервопривод к пину 5
  sy.attach(6);  // Подключаем сервопривод к пину 6
  Serial.begin(9600);  // Открываем серийный порт
  mySerial.begin(9600);  // Открываем SoftwareSerial порт
  
  sy.write(currentYPosition);  // Устанавливаем начальную позицию оси Y
  sx.write(currentXPosition);  // Устанавливаем начальную позицию оси X
}

void loop() {
  // Если есть данные для чтения
  if (mySerial.available()) {
    String receivedData = mySerial.readString();  // Чтение строки данных
    receivedData.trim();  // Удаляем лишние пробелы и символы новой строки
    
    // Проверка, что строка содержит данные
    if (receivedData.length() > 0 && receivedData.length() < 2 ) {
      Serial.println(receivedData);  // Вывод данных в консоль для отладки

      // Проверка значений данных и изменение позиции сервоприводов только при необходимости
      if (receivedData == "0") {
        if (currentXPosition != 80 || currentYPosition != 80) {
          currentYPosition = 80;
          currentXPosition = 80;
          sy.write(currentYPosition);
          sx.write(currentXPosition);
        }
      }
      if (receivedData == "1") {
        if (currentXPosition != 60) {
          currentXPosition = 60;
          sx.write(currentXPosition);
        }
      }
      if (receivedData == "2") {
        if (currentYPosition != 60) {
          currentYPosition = 60;
          sy.write(currentYPosition);
        }
      }
      if (receivedData == "3") {
        if (currentYPosition != 100) {
          currentYPosition = 100;
          sy.write(currentYPosition);
        }
      }
      if (receivedData == "4") {
        if (currentXPosition != 100) {
          currentXPosition = 100;
          sx.write(currentXPosition);
        }
      }

      delay(300);  // Добавлена небольшая задержка
    }
  }
}
