#include <stdio.h>

int getletter() {
    int c = getchar(); // Читаем один символ из стандартного ввода

    // Проверяем, является ли символ заглавной или строчной латинской буквой
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return c; // Возвращаем символ, если это буква
    }

    return -1; // Возвращаем -1, если это не буква
}

int main() {
    printf("Enter litera: ");
    int result = getletter();

    if (result != -1) {
        printf("Entering: %c\n", result);
    } else {
        printf("Don't enter liters.\n");
    }

    return 0;
}