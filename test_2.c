
#include <stdio.h>
#include <stdarg.h>

int dividers(int d, int n, ...) {
    int count = 0; // Счетчик подходящих делителей
    va_list args; // Объявление переменной для работы с переменным числом аргументов
    va_start(args, n); // Инициализация списка аргументов, начиная с n

    for (int i = 0; i < n; i++) {
        int number = va_arg(args, int); // Получение следующего аргумента
        if (number != 0 && d % number == 0) { // Проверка условия: не равно 0 и делитель d
            count++;
        }
    }
    va_end(args); // Освобождение ресурсов, использованных для работы с переменным списком аргументов
    return count; // Возврат количества найденных делителей
}

int main() {
    int result = dividers(12, 5, 2, 3, 4, 5, 0);
    printf("Kol-vo deliteley: %d\n", result); // Ожидается 3 (2, 3 и 4 являются делителями 12)
    return 0;
}