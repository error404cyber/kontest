#include <stdio.h>
#include <stdlib.h>
typedef struct IntNumber{
    int type;
    union{
        short svalue;
        int ivalue;
        long lvalue;
    };
} IntNumber;

IntNumber bconj(IntNumber first, IntNumber second){
    IntNumber res;
    size_t one = 0;
    if (first.type == 0){
        one = first.svalue;
    }
    if (first.type == 1){
        one = first.ivalue;
    }
    if (first.type == 2){
        one = first.lvalue;
    }

    size_t two = 0;
    if (second.type == 0){
        two = second.svalue;
    }
    if (second.type == 1){
        two = second.ivalue;
    }
    if (second.type == 2){
        two = second.lvalue;
    }

    if (first.type > second.type){
        res.type = first.type;
    }
    else{
        res.type = second.type;
    }

    if ((res.type == 0) || (res.type == 1)) {
        res.ivalue = (int)(one & two);
        res.type = 1;
    } else if (res.type == 2) {
        res.lvalue = (long)(one & two);
    }

    return res;
}

