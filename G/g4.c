// Программа в командной строке получает путь к текстовому файлу и некую строку s. Она оставляет в файле только те строки, которые содержат s как подстроку.
//  Длина всех строк файла не превышает 255 (не считая символа переноса строки). Символ переноса строки не входит в подстроку. Для поиска подстроки в строке можно воспользоваться функцией strstr.

// В этой задаче необходимо удалить некоторые строки из файла. Это можно сделать только очистив всё содержимое файла и перезаписав файл заново. 
// Поскольку содержимое всего файла загружать в память нельзя, для решения надо использовать второй временный файл, который можно создать с помощью функции tmpfile.

// FILE* tmpfile(void); — создаёт временный файл и открывает его как бинарный в режиме wb+ (для UNIX флаг b ничего не меняет). 
// Гарантируется, что имя файла будет уникальным в файловой системе. Временный файл автоматически удаляется после закрытия (его тоже нужно явно закрывать с помощью fclose).

// Функция main обязательно должна завершиться return 0;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3){
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f)
        return 0;

    char *poisk = argv[2];
    FILE * tmp_f;
    tmp_f = tmpfile();  

    char buffer[257];

    while(fgets(buffer, sizeof(buffer), f) != NULL){
        if (strstr(buffer, poisk))
            fputs(buffer, tmp_f);
    }
    fclose(f);
    
    FILE *fend = fopen(argv[1], "w");
    if (!fend)
        return 0;

    rewind(tmp_f);
    while (fgets(buffer, sizeof(buffer), tmp_f)) {
        fputs(buffer, fend);
    }
    
    fclose(fend);
    fclose(tmp_f);
    return 0;
}