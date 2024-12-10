https://docs.google.com/spreadsheets/d/1os5J39Eiuj1FAeWeGWCYS8i3Ovp5BXRGCaNcuBfIloA/edit?gid=233221097#gid=233221097




#include <stdio.h>

void main(){
	printf("Hello, world!\n");
}
#!/bin/bash

# Проверка наличия аргумента
if [ $# -ne 1 ]; then
    echo "Ошибка: необходимо указать название каталога."
    exit 1
fi

# Название каталога
DIR_NAME=$1

# Проверка наличия каталога на диске
if [ ! -d "$DIR_NAME" ]; then
    echo "Каталог '$DIR_NAME' не найден."
    exit 1
fi

# Создание другого каталога для ссылок
LINK_DIR="links"
mkdir -p "$LINK_DIR"

# Цикл для создания символных ссылок
count=1
for file in "$DIR_NAME"/*; do
    # Форматирование имени ссылки
    link_name=$(printf "%s/%02d" "$LINK_DIR" "$count")
    ln -s "$file" "$link_name"
    count=$((count + 1))
don
