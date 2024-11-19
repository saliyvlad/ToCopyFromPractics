#include <stdio.h>

void main(){
	int a;
	printf("введите год:");
	scanf("%d",&a);
	if (a%400 == 0){
	printf("Год високосный\n");
}
	else if (a%100 == 0){
		printf("Год не високосный\n");
}
	else if (a%4 == 0){
		printf("Год является високосным\n");
}
	else printf("Год не является високосным\n");
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
    # Проверка, чтобы создать не более 3 ссылок
    if [ $count -le 3 ]; then
        # Форматирование имени ссылки
        link_name=$(printf "%s/%02d" "$LINK_DIR" "$count")
        ln -s "$file" "$link_name"
        count=$((count + 1))
    else
        break
    fi
done
