// Написать программу, которая находит максимальное вещественное число типа double в однородном бинарном файле и дублирует его, раздвинув файл. 
//Если максимальное число встречается в файле несколько раз, надо продублировать только первое его вхождение. Путь к файлу задаётся в командной строке. Также программа должна распечатать найденное максимальное число на экран в формате "max = %.1f\n". Если файл пустой, ничего делать не надо.

// Однородный бинарный файл — файл, состоящий из множества элементов одного типа (как массив, записанный в файл в двоичном виде).

// Функция main обязательно должна завершиться return 0;

// Для тестирования имеет смысл написать функцию, которая создаёт бинарный файл и записывает туда массив чисел типа double. 
//Содержимое такого бинарного файла можно проверить с помощью утилиты od, указав ей в качестве типа элементов (-t) вещественные числа размером 8 байт (f8):

// od -t f8 doubles.bin

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *f;
    double max = 0;
    double buffer;
    f = fopen(argv[1], "rb");
    int count = 0;
    int count_2 = 0;
    if (!f)
        return 0;

    int flag = 0; //чисел нет

    if (fread(&buffer, sizeof(double), 1, f) == 1){
        max = buffer;
        flag = 2;
        count++;
        count_2 ++;
    }

    if (flag == 0){
        fclose(f);
        return 0;
    }

    while (fread(&buffer, sizeof(double), 1, f) == 1) {
        count_2 ++;
        if (max < buffer){
            max = buffer;
            count = count_2;
        }
    }
    printf("max = %.1f\n", max);
    fclose(f);
    FILE * tmp_f;
    tmp_f = tmpfile();  

    flag = 1; //уже записали максим
    count_2 = 1;
    // f = fopen("dupl.bin", "rb");
    f = fopen(argv[1], "rb");

    while (fread(&buffer, sizeof(double), 1, f) == 1) {
        fwrite(&buffer, sizeof(double), 1, tmp_f);
        //printf("%d %d", count, count_2);
        if ((count == count_2) && flag) {
            flag = 0;
            fwrite(&max, sizeof(double), 1, tmp_f);
        }
        count_2 ++;
    }

    fclose(f);

    rewind(tmp_f);
    // f = fopen("dupl.bin", "rb");
    f = fopen(argv[1], "wb");

    while (fread(&buffer, sizeof(double), 1, tmp_f) == 1) {
        fwrite(&buffer, sizeof(double), 1, f);
        // printf("%.1f\n", buffer);
    }

    fclose(tmp_f);
    fclose(f);

    return 0;
}