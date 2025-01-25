import requests
import pyautogui
import time

# Адрес ESP32
esp32_ip = "http://192.168.227.226"  # Замените на IP-адрес вашего ESP32

# Параметры ускорения
ACCELERATION_STEPS = 5  # Количество повторов команды для увеличения скорости
MAX_SPEED_MULTIPLIER = 5  # Максимальное ускорение (умножение скорости)

def process_command(command, current_speed):
    move_distance = 10 * current_speed  # Увеличиваем дистанцию в зависимости от скорости

    if command == "LEFT":
        pyautogui.move(-move_distance, 0)  # Движение влево
    elif command == "RIGHT":
        pyautogui.move(move_distance, 0)  # Движение вправо
    elif command == "UP":
        pyautogui.move(0, -move_distance)  # Движение вверх
    elif command == "DOWN":
        pyautogui.move(0, move_distance)  # Движение вниз
    elif command == "LEFT_CLICK":
        pyautogui.click(button='left')  # Левый клик
    elif command == "RIGHT_CLICK":
        pyautogui.click(button='right')  # Правый клик

def main():
    last_command = None
    repeat_count = 0
    speed_multiplier = 1

    while True:
        try:
            # Отправляем GET-запрос на ESP32 для получения команды
            response = requests.get(f"{esp32_ip}/data")
            if response.status_code == 200:
                command = response.text.strip()
                print(f"Принята команда: {command}")

                if command == last_command:
                    # Увеличиваем счетчик повторов одной и той же команды
                    repeat_count += 1
                    if repeat_count >= ACCELERATION_STEPS:
                        # Увеличиваем скорость, но не более MAX_SPEED_MULTIPLIER
                        speed_multiplier = min(speed_multiplier + 1, MAX_SPEED_MULTIPLIER)
                else:
                    # Если команда изменилась, сбрасываем счетчик и скорость
                    repeat_count = 0
                    speed_multiplier = 1

                # Выполняем команду с текущей скоростью
                process_command(command, speed_multiplier)

                # Запоминаем последнюю команду
                last_command = command
            else:
                print(f"Ошибка соединения: {response.status_code}")

            time.sleep(0.1)  # Интервал между запросами

        except KeyboardInterrupt:
            print("Программа завершена")
            break

if __name__ == "__main__":
    main()
