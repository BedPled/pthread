/*
 Имеется 10 файлов, в каждом из которых записано несколько целых через пробел. +

Необходимо написать однопоточную программу, которая посчитает общую сумму чисел во всех файлах, +
замерить время выполнения программы

Написать многопоточную программу, которая посчитает общую сумму чисел во всех файлах,
замерить время выполнения программы

Для реализации многопоточности использовать pthread*/
#include "lib.h"
#include <iostream>
#include <sysinfoapi.h>
using namespace std;

int main() {
    int start, end;
    start = GetTickCount();
    cout << singleThreading ();
    end =  GetTickCount();
    cout << endl << "Время однопоточной программы: " << end - start << " ms" << endl << endl;

    start = GetTickCount();
    cout << multiThreading();
    end =  GetTickCount();
    cout << endl << "Время многопоточной программы: " << end - start << " ms" << endl;
    return 0;
}
