import random
import sqlite3
import time
import string

# Создание или подключение к базе данных
conn = sqlite3.connect("objects.db")
cursor = conn.cursor()

# Создание таблицы
cursor.execute(
    """
CREATE TABLE IF NOT EXISTS objects (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    coordinate_x REAL NOT NULL,
    coordinate_y REAL NOT NULL,
    object_type TEXT NOT NULL,
    creation_time REAL NOT NULL
)
"""
)

# Возможные типы объектов
object_types = ["Человек", "Машина", "Здание", "Дерево"]

# Генерация случайных данных
def generate_random_name(length=5):
    """Генерирует случайное имя из букв заданной длины."""
    return ''.join(random.choices(string.ascii_letters, k=length))

def generate_random_data(num_entries):
    data = []

    for _ in range(num_entries):
        name = generate_random_name()  # Генерация случайного имени
        coordinate_x = random.uniform(-180.0, 180.0)  # Генерация координаты X
        coordinate_y = random.uniform(-90.0, 90.0)  # Генерация координаты Y
        object_type = random.choice(object_types)
        creation_time = time.time() + random.uniform(-1000000, 1000000)  # Генерация времени создания

        data.append((name, coordinate_x, coordinate_y, object_type, creation_time))

    return data

# Вставка данных в таблицу
num_entries = 100  # Количество записей для генерации
random_data = generate_random_data(num_entries)

cursor.executemany(
    """
INSERT INTO objects (name, coordinate_x, coordinate_y, object_type, creation_time)
VALUES (?, ?, ?, ?, ?)
""",
    random_data,
)

# Сохранение изменений и закрытие соединения
conn.commit()
conn.close()

print(f"База данных успешно создана и заполнена {num_entries} случайными данными.")
