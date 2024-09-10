import random
import string
import time

# Возможные типы объектов
object_types = ["Человек", "Машина", "Здание", "Дерево"]


def generate_name(length):
    """Генерирует имя объекта заданной длины."""
    letters = string.ascii_letters
    return "".join(random.choice(letters) for _ in range(length))


def generate_coordinates():
    """Генерирует случайные координаты в диапазоне от -1000 до 1000."""
    x = round(random.uniform(-1000, 1000), 3)
    y = round(random.uniform(-1000, 1000), 3)
    return x, y


def generate_creation_time():
    """Возвращает текущее время в формате Unix timestamp."""
    return round(time.time(), 5)


num_objects = 100  # Количество объектов для генерации

with open("objects.txt", "w", encoding="utf-8") as file:
    for _ in range(num_objects):
        name = generate_name(
            random.randint(5, 10)
        )  # Генерация имени длиной от 5 до 10 символов
        x, y = generate_coordinates()  # Генерация координат
        object_type = random.choice(object_types)  # Случайный выбор типа объекта
        creation_time = generate_creation_time()  # Генерация времени создания

        # Форматирование строки и запись в файл
        line = f"{name} {x} {y} {object_type} {creation_time}"
        file.write(line + "\n")  # Запись строки в файл

print(f"Файл objects.txt сгенерирован с {num_objects} объектами.")
