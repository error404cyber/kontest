#include <stdio.h>
#include <string.h>
#include <assert.h>

int perevod (char chis){
    if ((chis >= '0') && (chis <= '9'))
        return (chis - '0');
    else
        if ((chis >= 'A') && (chis <= 'F'))
            return (chis - 'A' + 10);
        else 
            if ((chis >= 'a') && (chis <= 'f'))
                return (chis - 'a' + 10);
            else
                return -1;
}

int strtoint(const char str[], int *res){
    long long int my_res = 0;
    int i = 0;
    int base = 0;
    long long int counter = 1; // СС в степени, начиная с 0
    if (str[0] != '0')
        return -1;
    switch (str[1])
    {
    case 'b':
        base = 2;
        break;
    case 'o':
        base = 8;
        break;
    case 'x':
        base = 16;
        break;
    default:
        return -1;
        break;
    }
    
    if ((base == 2) || (base == 8)){
        for (i = strlen(str) - 1; i >= 2; i--){
            if ((((str[i] > '1') || (str[i] < '0')) && (base == 2)) ||
                (((str[i] > '7') || (str[i] < '0')) && (base == 8)))  //не в двоичке началось
                return -1;
            my_res += ((str[i] - '0') * counter);
            counter *= base;
        }
    }
    else{
        for (i = strlen(str) - 1; i >= 2; i--){
            if (perevod(str[i]) < 0)
                return -1;
            my_res += (perevod(str[i]) * counter);
            counter *= base;
        }
    }
    *res = my_res;
    return 1;
}





